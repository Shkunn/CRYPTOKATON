#include <ctime>
#include <list>
#include <string>

namespace BeerCoin {

    typedef struct
    {
        std::string message;
        std::string signature;
        std::string publicKey;
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

            bool isMessageValid();
            bool isValid();
            void print();

            bool isSignatureValid();
            float getAmount();
            std::string getReceiverKey();
            std::string getHash();
                
    };
}
