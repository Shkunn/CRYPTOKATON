#pragma once

#include <ctime>
#include <string>

namespace CoffeeBean {

	struct Packet {
		size_t       index;
		std::string  prev;
		std::time_t  timestamp;
		std::string  data;
		unsigned int difficulty = 1;
		unsigned int nonce      = 0;

		const bool match() const;
		void grind();

		bool operator!=(const Packet &other) const;

		std::string str();
	};

	std::string roast(      Packet *packet);
	std::string roast(      Packet &packet);
	std::string roast(const Packet *packet);
	std::string roast(const Packet &packet);
	std::string roast(
		size_t       index,
		std::string  prev,
		std::time_t  timestamp,
		std::string  data,
		unsigned int difficulty,
		unsigned int nonce
	);

}
