#include <ctime>
#include <list>
#include <string>
#include <block.h>

namespace BeerCoin {
    class Blockchain
    {
    private:
        std::list<Block> blocks;
        int difficulty;
    public:
        Blockchain(/* args */);
        ~Blockchain();

        void addBlock(Block block);
        int getDifficulty();
    };   
}