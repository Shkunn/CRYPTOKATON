#include <ctime>
#include <list>
#include <string>
#include <transaction.h>

namespace BeerCoin {

    class Block
    {
        private:
            const unsigned long index;
            const std::string hash;
            const long proof;
            const std::time_t timestamp;
            const std::string previous_hash;
            std::list<Transaction> transactions;

        public:
            Block(/* args */);
            ~Block();

            bool addTransaction(Transaction transaction);
            void mineBlock(int difficulty);
            std::string getHash(); 
    };
}
