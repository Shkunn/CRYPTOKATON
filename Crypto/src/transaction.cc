#include <ctime>
#include <list>
#include <string>

#include "../include/transaction.h"
#include "../include/utils.h"


namespace BeerCoin {

    Transaction::Transaction(SignedMessage* signed_message, unsigned long id, std::string receiver_key, float amount) {
        this->id = id;
        this->receiver_key = receiver_key;
        this->amount = amount;
        this->signed_message = signed_message;
        this->_hash = "";
    }

    Transaction::~Transaction() {
        //TODO destructor
    }

    bool Transaction::isSignatureValid() {
        return checkSignature(this->signed_message);
    } 

    float Transaction::getAmount(){
        return amount;
    }       

    std::string Transaction::getHash() {
        if(this->_hash == "")
            this->_hash = sha256(std::to_string(this->id) + 
                      this->receiver_key + 
                      std::to_string(this->amount) + 
                      this->signed_message->message + 
                      this->signed_message->publicKey + 
                      this->signed_message->signature
                    );
        return this->_hash;
    }
}