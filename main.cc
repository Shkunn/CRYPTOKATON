#include <iostream>
#include <sstream>
#include <iomanip>

#include "include/Blockchain.h"


int main(int argc, char **argv)
{
    std::string data; 
    
    std::cout << "Type your data: ";
    std::cin >> data;

    const Block genesisBlock = Block(0, "0", "0", time(nullptr), data);

    std::string hash = calcHash(genesisBlock.index, genesisBlock.previousHash, genesisBlock.timestamp, genesisBlock.data);
    std::cout << "\nBLOCK\n" 
              << "\tINDEX         : " << genesisBlock.index         << "\n"     
              << "\tPrevious Hash : " << genesisBlock.previousHash  << "\n"
              << "\tTimestamp     : " << genesisBlock.timestamp     << "\n"
              << "\tData          : " << genesisBlock.data          << "\n";
}