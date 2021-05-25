#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>


struct Block
{
    int             index;
    std::string     hash;
    std::string     previousHash;
    std::time_t     timestamp;
    std::string     data;
    int             difficulty    = 1;
    int             nonce         = 0; 

    void str();
    bool operator!=(const Block &otherBlock) const;
    void mine();
    const bool hashMatchesDifficulty();

};

struct Blockchain
{
    std::vector<Block> chain;

    const Block genesis;
    int difficulty;

    Blockchain(const Block genesis)
        :genesis(genesis), difficulty(1)
        {
            chain.push_back(genesis);
        }

    Blockchain(const Block genesis, int difficulty)
        :genesis(genesis), difficulty(difficulty)
        {
            chain.push_back(genesis);
        }

    Block generateNewBlock(std::string data); 

    void str();

    const bool isValid(Block newBlock);
    const bool isValid(Blockchain &newBlockchain);
    inline size_t size();
    inline const Block operator[](size_t i);

    const bool replace(Blockchain &newBlockchain);
    // const int Blockchain::getDifficulty();
};

std::string sha256(const std::string str);

const std::string calcHash(int index, std::string previousHash, std::time_t timestamp, std::string data);
const std::string calcHash(int index, std::string previousHash, std::time_t timestamp, std::string data, int nonce);
const std::string calcHash(Block block);


struct TxOut
{
    std::string adress;
    int         amount;

    TxOut(std::string adress, int amount)
        :adress(adress), amount(amount) {} 
};

struct TxIn
{
    std::string txOutId;
    int         txOutIndex;
    std::string signature;
};

struct Transaction
{
    std::string id;
    std::vector<TxOut> txOuts;
    std::vector<TxIn> txIns;

    const std::string getTransactionId();
};

struct UnspentTxOut 
{
    std::string txOutId;
    std::string adress;
    int         txOutIndex;
    int         amount;

    UnspentTxOut(std::string txOutId, std::string adress, int txOutIndex, int amount)
        :txOutId(txOutId), adress(adress), txOutIndex(txOutIndex), amount(amount) {} 
};