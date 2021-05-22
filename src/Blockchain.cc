#include "openssl/sha.h"
#include "../include/Blockchain.h"


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

const std::string calcHash(int index, std::string previousHash, std::time_t timestamp, std::string data)
{
    std::string val   = std::to_string(index) + previousHash + std::to_string(timestamp) + data; 
    std::string input = sha256(val);

    return input;
}

const Block Blockchain::generateNewBlock(std::string data)
{
    const std::string previousHash = chain[chain.size() - 1].hash;
    const int nextIndex = (int)chain.size();
    const time_t nextTimestamp = time(nullptr);
    const std::string nextHash = calcHash(nextIndex, previousHash, nextTimestamp, data);
    const Block newBlock = Block(nextIndex, nextHash, previousHash, nextTimestamp, data);

    return newBlock;
}

const bool Blockchain::isValid( Block newBlock)
{
    Block previousBlock = chain[chain.size() - 1];

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
    else if( calculateHashForBlock(newBlock) != newBlock.hash )
    {
        std::cout << "Invalid Hash: "  + calculateHashForBlock(newBlock) + ' vs ' + newBlock.hash << std::endl;
        
        return false;
    }

    return true;
}

const bool Blockchain::isValid(Blockchain newBlockchain)
{
    if(newBlockchain.genesis != genesis)
    {
        return false;
    }

    for(size_t i = 1; i < newBlockchain.chain.size(); i++)
    {
        if(!isValid(newBlockchain.chain[i]))
        {
            return false;
        }
    }
}