#include <ctime>
#include <list>
#include <string>
#include <iostream>

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

    std::string Transaction::getReceiverKey() {
        return this->receiver_key;
    } 

    bool Transaction::isMessageValid() {
        std::string msg = std::to_string(id) + ";" + this->signed_message->publicKey + ";" + this->receiver_key + ";" + std::to_string(amount);
        return msg == this->signed_message->message;
    }

    bool Transaction::isValid() {
        return isMessageValid() && isSignatureValid();
    }

    void Transaction::print() {
        std::cout << "Transaction : \n" << std::endl;
        std::cout << "\t id : " + std::to_string(this->id) + "\n" << std::endl;
        std::cout << "\t receiverKey : " + this->receiver_key + "\n" << std::endl;
        std::cout << "\t amount : " +  std::to_string(this->amount) + "\n" << std::endl;
        std::cout << "\t hash : " + this->_hash + "\n" << std::endl;
        std::cout << "\t publicKey : " + this->signed_message->publicKey + "\n" << std::endl;
        std::cout << "\t message : " + this->signed_message->message + "\n" << std::endl;
        std::cout << "\t signature : " + this->signed_message->signature<< std::endl;
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