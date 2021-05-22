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

    Block(int init_index, std::string init_hash, std::string init_prev_hash, std::time_t init_timestamp, std::string init_data)
        :index(init_index), hash(init_hash), previousHash(init_prev_hash), timestamp(init_timestamp), data(init_data) {}

    bool operator!=(const Block &otherBlock) const;
};

struct Blockchain
{
    std::vector<Block> chain;

    const Block genesis;

    Blockchain(const Block genesis)
        :genesis(genesis) {}

    const Block generateNewBlock(std::string data); 

    const bool isValid(Block newBlock);
    const bool isValid(Blockchain &newBlockchain);
    inline size_t size();
    inline const Block& operator[](size_t i);

    const bool replace(Blockchain &newBlockchain);
};

std::string sha256(const std::string str);

const std::string calcHash(int index, std::string previousHash, std::time_t timestamp, std::string data);
const std::string calcHash(Block block);