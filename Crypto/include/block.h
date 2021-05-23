#include <ctime>
#include <list>
#include <string>
#include <transaction.h>

namespace BeerCoin {

    typedef struct {
        std::string miner_pub_key;
        float value;
    } MinerReward;

    class Block
    {
        private:
            unsigned long index;
            std::string hash;
            long proof;
            std::time_t timestamp;
            std::string previous_hash;
            std::list<Transaction> transactions;
            MinerReward minerReward;

        public:
            Block(std::string previous_hash);
            ~Block();

            bool addTransaction(Transaction transaction);
            void mineBlock(int difficulty, std::string miner_pub);
            bool isFull();
            float getValueAmont();
            std::string getHash(); 
    };
}
