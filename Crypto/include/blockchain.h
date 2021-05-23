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
            Blockchain();
            ~Blockchain();

            bool addTransaction(std::string sender,
                                std::string receiver, 
                                std::string signature, 
                                float amount, 
                                unsigned long id
                                );

            bool isValid(int difficulty);
            float getUserBalance(std::string user);
            int getDifficulty();
            void print();
            void addBlock(Block new_block);
        };   
}