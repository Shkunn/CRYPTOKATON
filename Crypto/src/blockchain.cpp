#include <ctime>
#include <list>
#include <string>
#include <transaction.h>
#include <block.h>
#include <blockchain.h>
#include <iostream>

#define MINER_PUB "wallaonverra"

namespace BeerCoin {

    Blockchain::Blockchain() {

    }
    
    Blockchain::~Blockchain() {

    }

    bool Blockchain::addTransaction(std::string sender, std::string receiver, std::string signature, float amount, unsigned long id) {
        // ajouter au bloc actuel
        // si le bloc actuel est full
        //   miner le bloc actuel
        //   créer nouveau bloc
        //   ajouter le bloc actuel à la liste (addBlock)
        //   block actuel devient le nouveau
        //
        std::string message = std::to_string(id) + ";" + sender + ";" + receiver + ";" + std::to_string(amount);
        BeerCoin::SignedMessage *signed_message = new BeerCoin::SignedMessage;
        signed_message->message = message;
        signed_message->publicKey = sender;
        signed_message->signature = signature;

        Transaction new_transaction(signed_message, id, receiver, amount);
        if(this->current_block.addTransaction(new_transaction))
            return true;

        if(this->current_block.isFull()){
            this->current_block.mineBlock(getDifficulty(), MINER_PUB);
            Block new_block(this->current_block.getHash());
            addBlock(new_block);
            return true;
        }
        return false;
    }

    float Blockchain::getUserBalance(std::string user) {
        float value = 0;
        for(auto block : this->blocks){
            value += block.getUserBalance(user);
        }
        value += this->current_block.getUserBalance(user);
        return value;
    }

    bool Blockchain::isValid(int difficulty) {
        for(auto block : this->blocks) {
            if(!block.isValid(difficulty))
                return false;
        }
        return this->current_block.isValid(difficulty);
    }

    void Blockchain::addBlock(Block new_block){
        this->blocks.push_back(this->current_block);
        this->current_block = new_block;
    }

    void Blockchain::print() {
        std::cout << "Blockchain : \n" << std::endl;
        std::cout << "\t difficulty : " +  std::to_string(this->difficulty) + "\n" << std::endl;
        for (auto block : this->blocks) {
            block.print();
        }
        current_block.print();
    }

    int Blockchain::getDifficulty() {
        return 7; // FIXME programatic ?
    }  
}