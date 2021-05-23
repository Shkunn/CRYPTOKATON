#include <string>
#include <vector>

#include "block.h"

namespace CoffeeBean {

	struct BlockChain {
		std::vector<Block> chain;
		const Block        genesis;
		unsigned int       difficulty;

		BlockChain(const Block genesis):
			genesis(genesis), difficulty(4) {
			chain.push_back(genesis);
		}

		BlockChain(const Block genesis, unsigned int difficulty):
			genesis(genesis), difficulty(difficulty) {
			chain.push_back(genesis);
		}

		Block generate(std::string data);

		const bool validate(Block      &block     );
		const bool validate(BlockChain &blockChain);
		const bool replace (BlockChain &blockChain);

		inline size_t size();
		inline Block &operator[](size_t i);

		std::string str();
	};

}
