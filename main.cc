#include <iostream>
#include <sstream>
#include <iomanip>

#include "include/Blockchain.h"


int main(int argc, char **argv)
{
    Block genesisBlock = {
        0, 
        "0",
        "", 
        time(nullptr), 
        "Genesis"
    };

    genesisBlock.hash = calcHash(genesisBlock);

    // genesisBlock.str();

    Blockchain blockchain = Blockchain(genesisBlock);
    Block newBlock = blockchain.generateNewBlock("First");

    // newBlock.str();

    newBlock.mine();

    blockchain.chain.push_back(newBlock);

    blockchain.str();
    
    return EXIT_SUCCESS;
}