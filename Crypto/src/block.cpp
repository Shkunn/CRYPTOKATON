#include <ctime>
#include <list>
#include <string>
#include <block.h>
#include <transaction.h>
#include <utils.h>

#define MAX_TRANSATIONS_IN_BLOCK 5
#define MINER_REWARD 1.0 // TODO: programatic way


namespace BeerCoin {

    Block::Block(std::string previous_hash) {
        this->previous_hash = previous_hash;
    }

    Block::~Block() {

    }

    bool Block::addTransaction(Transaction transaction) {
        if(! transaction.isSignatureValid())
            return false;
        
        if(this->transactions.size() >= MAX_TRANSATIONS_IN_BLOCK)
            return false;

        this->transactions.push_back(transaction);
        return true;   
    }

    bool Block::isFull() {
        return this->transactions.size() == MAX_TRANSATIONS_IN_BLOCK;
    }

    std::string get_constrainst(int difficulty){
        std::string constrainst = "";
        for (int i = 0; i < difficulty; i++)
        {
            constrainst += "0";
        }
        return constrainst;
    }

    void Block::mineBlock(int difficulty, std::string miner_pub) {
        this->minerReward.miner_pub_key = miner_pub;
        this->minerReward.value = MINER_REWARD;
        std::string hash_to_fund = getHash();
        while(hash_to_fund.substr(0, difficulty) != get_constrainst(difficulty)) {
            this->proof += 1;
            hash_to_fund = getHash();
        }
    }

    std::string Block::getHash() {
        std::string transactions_hash = "";
        for(auto transaction: this->transactions) {
            transactions_hash += transaction.getHash();
        }

        return sha256(
            transactions_hash +
            std::to_string(this->proof) +
            std::to_string(this->timestamp) +
            this->previous_hash
        );
    }
}
