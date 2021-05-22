#include <ctime>
#include <list>
#include <string>

namespace BeerCoin {

    typedef struct
    {
        const std::string message;
        const std::string signature;
        const std::string publicKey;
    } SignedMessage;
    

    class Transaction
    {
        private:
            unsigned long id;
            std::string receiver_key;
            float amount;
            SignedMessage* signed_message;

            std::string _hash;

        public:
            Transaction(SignedMessage* signed_message, unsigned long id, std::string receiver_key, float amount);
            ~Transaction();

            bool isSignatureValid();
            std::string getHash();
                
    };
}
