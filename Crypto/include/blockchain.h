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
        Block current_block;
        unsigned long transaction_id;

    public:
        Blockchain(/* args */);
        ~Blockchain();

        bool addTransaction(std::string sender, std::string receiver, std::string signature, float amount, unsigned long id);
        float getUserBalance(std::string user);
        int getDifficulty();
    };   
}