#pragma once

#include <ctime>
#include <string>

namespace CoffeeBean {

	struct Block {
		size_t       index;
		std::string  prev;
		std::time_t  timestamp;
		std::string  data;
		unsigned int difficulty = 1;
		unsigned int nonce      = 0;

		const bool match() const;
		void mine();

		bool operator!=(const Block &other) const;

		std::string str();
	};

	std::string roast(      Block *block);
	std::string roast(      Block &block);
	std::string roast(const Block *block);
	std::string roast(const Block &block);
	std::string roast(
		size_t       index,
		std::string  prev,
		std::time_t  timestamp,
		std::string  data,
		unsigned int difficulty,
		unsigned int nonce
	);

}
