#include <ctime>
#include <list>
#include <string>
#include <block.h>

namespace BeerCoin {
    class Blockchain
    {
        Blockchain(/* args */) {

        }
        ~Blockchain() {

        }

        bool addTransaction(std::string sender, std::string receiver, std::string signature, float amount, unsigned long id) {
            return false;
        }


        float Blockchain::getValueForUser(std::string user) {

        }

        int getDifficulty() {
            return 4;
        }
    };   
}