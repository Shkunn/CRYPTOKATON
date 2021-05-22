#include "transaction.h"

namespace BeerCoin {
    bool checkSignature(SignedMessage *msg);
    std::string sha256(std::string message);
}