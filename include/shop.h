#include <string>
#include <vector>

#include "packet.h"

namespace CoffeeBean {

	struct CoffeeShop {
		std::vector<Packet> shop;
		const Packet        genesis;
		unsigned int        difficulty;

		CoffeeShop(const Packet genesis):
			genesis(genesis), difficulty(4) {
			shop.push_back(genesis);
		}

		CoffeeShop(const Packet genesis, unsigned int difficulty):
			genesis(genesis), difficulty(difficulty) {
			shop.push_back(genesis);
		}

		Packet package(std::string data);

		const bool taste  (Packet     &packet    );
		const bool taste  (CoffeeShop &coffeeShop);
		const bool replace(CoffeeShop &coffeeShop);

		inline size_t size();
		inline Packet &operator[](size_t i);

		std::string str();
	};

}
