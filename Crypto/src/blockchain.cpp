#include <ctime>
#include <list>
#include <string>
#include <transaction.h>
#include <block.h>
#include <blockchain.h>

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
        std::string message = "????";
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
            value += block.getValueAmont();
        }
        value += this->current_block.getValueAmont();
        return value;
    }

    void Blockchain::addBlock(Block new_block){
        this->blocks.push_back(this->current_block);
        this->current_block = new_block;
    }

    int Blockchain::getDifficulty() {
        return 4;
    }  
}