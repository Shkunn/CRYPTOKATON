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
            unsigned long amount;
            SignedMessage* signed_message;

        public:
            Transaction(SignedMessage* signed_message, unsigned long id, std::string receiver_key, unsigned long amount);
            ~Transaction();

            bool isSignatureValid();
                
    };
}
