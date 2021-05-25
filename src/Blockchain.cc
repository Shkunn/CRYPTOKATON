#include <bitset>
#include <sstream>

#include "openssl/sha.h"
#include "../include/Blockchain.h"

// in seconds and in blocks
const int BLOCK_GENERATION_INTERVAL      = 10;
const int DIFFICULTY_ADJUSTMENT_INTERVAL = 10;

inline size_t Blockchain::size()
{
    return chain.size();
}

inline const Block Blockchain::operator[](size_t i)
{
    if(i >= size())
    {
        exit(EXIT_FAILURE);
    }
    return chain[i];
}

bool Block::operator!=(const Block &otherBlock) const
{
    return index           !=   otherBlock.index          ||
           hash            !=   otherBlock.hash           ||
           previousHash    !=   otherBlock.previousHash   ||
           timestamp       !=   otherBlock.timestamp      ||
           data            !=   otherBlock.data;
}

std::string sha256(const std::string str)
{
    unsigned            char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX          sha256;
    std::stringstream   ss;


    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void Block::str()
{
    std::cout << "\nBLOCK\n"
              << "\tINDEX         : " << index         << "\n"  
              << "\tHash          : " << hash          << "\n"  
              << "\tPrevious Hash : " << previousHash  << "\n"
              << "\tTimestamp     : " << timestamp     << "\n"
              << "\tData          : " << data          << "\n"
              << "\tDifficulty    : " << difficulty    << "\n"
              << "\tNonce         : " << nonce         << "\n";
}

void Blockchain::str()
{
    std::cout << "BLOCKCHAIN" << std::endl;

    for(Block &block: chain)
    {
        block.str();
    }
}

const std::string calcHash(int index, std::string previousHash, std::time_t timestamp, std::string data)
{
    std::string val   = std::to_string(index) + previousHash + std::to_string(timestamp) + data; 
    std::string input = sha256(val);

    return input;
}

const std::string calcHash(int index, std::string previousHash, std::time_t timestamp, std::string data, int nonce)
{
    std::string val   = std::to_string(index) + previousHash + std::to_string(timestamp) + data + std::to_string(nonce); 
    std::string input = sha256(val);

    return input;
}

const std::string calcHash(Block block)
{
    std::string val   = std::to_string(block.index) + block.previousHash + std::to_string(block.timestamp) + block.data; 
    std::string input = sha256(val);

    return input;
}

const std::string calcHash(Block* block)
{
    std::string val   = std::to_string(block->index) + block->previousHash + std::to_string(block -> timestamp) + block -> data + std::to_string(block -> nonce); 
    std::string input = sha256(val);

    return input;
}

Block Blockchain::generateNewBlock(std::string data)
{
    const int nextIndex = (int)size();
    const time_t nextTimestamp = time(nullptr);    
    const std::string previousHash = chain[size() - 1].hash;
    const std::string nextHash = calcHash(nextIndex, previousHash, nextTimestamp, data, difficulty);
    
    return {
        nextIndex, 
        nextHash, 
        previousHash, 
        nextTimestamp, 
        data, 
        difficulty
    };
}

const bool Blockchain::isValid(Block newBlock)
{
    Block previousBlock = chain[size() - 1];

    if( previousBlock.index + 1 != newBlock.index )
    {
        std::cout << "Invalid Index..." << std::endl;

        return false;
    } 
    else if( previousBlock.hash != newBlock.previousHash )
    {
        std::cout << "Invalid Hash..." << std::endl;

        return false;
    }
    else if( calcHash(newBlock) != newBlock.hash )
    {
        std::cout << "Invalid Hash: "  + calcHash(newBlock) << " vs " << newBlock.hash << std::endl;
        
        return false;
    }

    return true;
}

const bool Blockchain::isValid(Blockchain &newBlockchain)
{
    if(newBlockchain.genesis != genesis)
    {
        return false;
    }

    for(size_t i = 1; i < newBlockchain.size(); i++)
    {
        if(!isValid(newBlockchain[i]))
        {
            return false;
        }
    }

    return true;
}

// const bool isValid(Block newBlock, Block previousBlock)
// {
//     if(previousBlock.timestamp - 60 < newBlock.timestamp && newBlock.timestamp - 60 < getCurrentTimestamp())
//     {
//         return true;
//     } 
//     return false;
// }
 
const bool Blockchain::replace(Blockchain &newBlockchain)
{
    if (isValid(newBlockchain) && newBlockchain.size() > chain.size())
    {
        chain = newBlockchain.chain;
        return true;
    }

    return false;
} 

const char* hex_char_to_bin(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    return nullptr;
}

std::string hex_str_to_bin_str(const std::string& hex)
{
    std::string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hex_char_to_bin(hex[i]);
    return bin;
}

const bool Block::hashMatchesDifficulty()
{
    const std::string hashInBinary = hex_str_to_bin_str(hash);

    for (int i = 0; i < difficulty; ++i)
    {
        if(hashInBinary[i] != '0')
        {
            return false;
        }
    }
    return true;
}

void Block::mine()
{
    while(true)
    {
        if(hashMatchesDifficulty())
        {
            break;
        }
        nonce ++;
        hash = calcHash(this);
    }
}

// const time_t getCurrentTimestamp()
// {
//     return time(nullptr);
// }

// const int getAdjustedDifficulty(Block lastestBlock, Blockchain blockchain)
// {
//     const Block prevAdjustmentBlock = lastestBlock[blockchain.size() - DIFFICULTY_ADJUSTMENT_INTERVAL]  
//     return 0;
// }

// const int Blockchain::getDifficulty()
// {
//     Block latestBlock = chain[size() - 1];
//     if(latestBlock.index % DIFFICULTY_ADJUSTMENT_INTERVAL == 0 && latestBlock.index != 0)
//     {
//         return getAdjustedDifficulty(latestBlock, chain);
//     }
//     return latestBlock.difficulty;
// }

const std::string Transaction::getTransactionId()
{
    std::stringstream ssi;

    for(auto &transaction: txIns)
    {
        ssi << transaction.txOutId 
            << std::to_string(transaction.txOutIndex);
    }
    for(auto &transaction: txOuts)
    {
        ssi << transaction.adress 
            << std::to_string(transaction.amount);
    }

    return sha256(ssi.str());
}

// const std::string singTxIn(Transaction transaction, int ixInIndex, std::string privateKey, std::vector<UnspentTxOut> unspentTxOuts)
// {
//     const TxIn txIn = transaction.txIns[ixInIndex];
//     const std::string dataToSign = transaction.id;
//     const UnspentTxOut referencedUnspentTxOut =
// }