#include <ctime>
#include <iostream>
#include <sstream>

#include "../include/chain.h"

namespace CoffeeBean {

	Block BlockChain::generate(std::string data) {
		return {
			size(),
			roast(chain[size() - 1]),
			std::time(nullptr),
			data,
			difficulty,
			0
		};
	}

	const bool BlockChain::validate(Block &block) {
		Block prev = chain[size() - 2];
		return prev.index + 1 == block.index &&
			   roast(prev)    == block.prev;
	}

	const bool BlockChain::validate(BlockChain &blockChain) {
		blockChain.genesis;		
		if(blockChain.genesis != genesis) return false;
		for(auto i = 1; i < blockChain.size(); ++i)
			if(!validate(blockChain[i])) return false;
		return true;
	}

	const bool BlockChain::replace(BlockChain &blockChain) {
		if(validate(blockChain) && blockChain.size() > size()) {
			chain = blockChain.chain;
			return true;
		}
		return false;
	}

	inline size_t BlockChain::size() { return chain.size(); }	
	inline Block &BlockChain::operator[](size_t i) { return chain[i]; }

	std::string BlockChain::str() {
		std::stringstream ss;
		ss << "==== BLOCKCHAIN[" << size()  << "]\n";
		for(size_t i = 0; i < size(); ++i)
			ss << chain[i].str()
			   << (i == size() - 1? "": "\n");
		return ss.str();
	}
	
}
