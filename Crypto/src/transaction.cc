#include <ctime>
#include <list>
#include <string>

#include "../include/transaction.h"
#include "../include/utils.h"


namespace BeerCoin {

    Transaction::Transaction(SignedMessage* signed_message, unsigned long id, std::string receiver_key, unsigned long amount) {
        this->id = id;
        this->receiver_key = receiver_key;
        this->amount = amount;
        this->signed_message = signed_message;
    }

    Transaction::~Transaction() {
        //TODO destructor
    }

    bool Transaction::isSignatureValid() {
        return checkSignature(this->signed_message);
    }        
}