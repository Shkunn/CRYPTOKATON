#include <ctime>
#include <iostream>
#include <string>

#include "include/block.h"
#include "include/chain.h"

const unsigned int DIFFICULTY = 20;

int main() {
	CoffeeBean::Block genesis = { 0, "", std::time(nullptr), "Genesis" };
	CoffeeBean::BlockChain blockChain = CoffeeBean::BlockChain(genesis, DIFFICULTY);
	CoffeeBean::Block coffee = blockChain.generate("First Coffee!");
	
	std::time_t t0 = std::time(nullptr);
	std::cout << "[START] Mining ...\n";

	coffee.mine();
	
	std::time_t t1 = std::time(nullptr);
	std::time_t dt = (t1 - t0) * 100;
	std::cout << "[END  ] Mined in " << dt << "ms\n";

	std::cout << "\n";
	
	blockChain.chain.push_back(coffee);
	
	std::cout << blockChain.str() << "\n"
			  << "validation: " << blockChain.validate(blockChain) << "\n"
			  << "Corrupted Replacement Success: "
			  << blockChain.replace(blockChain) << "\n";

	std::cout << "\n";
	
	coffee.data = "First Corruption!";
	blockChain.chain.push_back(coffee);

	std::cout << blockChain.str() << "\n"
			  << "validation: " << blockChain.validate(blockChain) << "\n"
			  << "Corrupted Replacement Success: "
			  << blockChain.replace(blockChain) << "\n";

	std::cout << "\n";

	return EXIT_SUCCESS;
}
