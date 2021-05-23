#include <ctime>
#include <list>
#include <string>
#include <block.h>
#include <transaction.h>
#include <utils.h>
#include <iostream>

#define MAX_TRANSATIONS_IN_BLOCK 5
#define MINER_REWARD 1.0 // TODO: programatic way


namespace BeerCoin {

    Block::Block(std::string previous_hash) {
        this->previous_hash = previous_hash;
        this->proof = -1;
    }

    Block::~Block() {

    }

    bool Block::addTransaction(Transaction transaction) {
        if(! transaction.isSignatureValid())
            return false;
        
        // if(this->transactions.size() >= MAX_TRANSATIONS_IN_BLOCK)
        //     return false;
        
        if(isFull())
            return false;

        this->transactions.push_back(transaction);
        return true;   
    }

    bool Block::isFull() {
        return this->transactions.size() >= MAX_TRANSATIONS_IN_BLOCK;
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

    bool Block::isValid(int difficulty) {
        for(auto transaction : this->transactions) {
            if(!transaction.isValid())
                return false;
        }

        if(isMined()) {
            return this->getHash().substr(0, difficulty) == get_constrainst(difficulty);
        }
        return true;
    }

    bool Block::isMined() {
        return this->proof != -1;
    }

    float Block::getUserBalance(std::string user) {
        float value = 0;
        for(auto transaction : this->transactions) {
            if(transaction.getReceiverKey() == user) {
                value += transaction.getAmount();
            }
        }
        if(this->minerReward.miner_pub_key == user) {
            value += this->minerReward.value;
        }
        return value;
    }

    void Block::print() {
        std::cout << "Block : \n" << std::endl;
        std::cout << "\t index : " +  std::to_string(this->index) + "\n" << std::endl;
        std::cout << "\t previousHash : " + this->previous_hash + "\n" << std::endl;
        std::cout << "\t hash : " + this->hash + "\n" << std::endl;
        std::cout << "\t proof : " +  std::to_string(this->proof) + "\n" << std::endl;
        std::cout << "\t timestamp : " +  std::to_string(this->timestamp) + "\n" << std::endl;
        for (auto transaction : this->transactions) {
            transaction.print();
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
            this->previous_hash +
            this->minerReward.miner_pub_key +
            std::to_string(this->minerReward.value)
        );
    }
}
