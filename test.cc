#include <ctime>
#include <iostream>
#include <string>

#include "include/packet.h"
#include "include/shop.h"

const unsigned int DIFFICULTY = 20;

int main() {
	CoffeeBean::Packet genesis = { 0, "", std::time(nullptr), "Genesis" };
	CoffeeBean::CoffeeShop coffeeShop = CoffeeBean::CoffeeShop(genesis, DIFFICULTY);
	CoffeeBean::Packet coffee = coffeeShop.package("First Coffee!");
	
	std::time_t t0 = std::time(nullptr);
	std::cout << "[START] Grinding ...\n";

	coffee.grind();
	
	std::time_t t1 = std::time(nullptr);
	std::time_t dt = (t1 - t0) * 100;
	std::cout << "[END  ] Grinded in " << dt << "ms\n";

	std::cout << "\n";
	
	coffeeShop.shop.push_back(coffee);
	
	std::cout << coffeeShop.str() << "\n"
			  << "Taste: " << coffeeShop.taste(coffeeShop) << "\n"
			  << "Rotten Replacement Success: "
			  << coffeeShop.replace(coffeeShop) << "\n";

	std::cout << "\n";
	
	coffee.data = "Rotten!";
	coffeeShop.shop.push_back(coffee);

	std::cout << coffeeShop.str() << "\n"
			  << "Taste: " << coffeeShop.taste(coffeeShop) << "\n"
			  << "Rotten Replacement Success: "
			  << coffeeShop.replace(coffeeShop) << "\n";

	std::cout << "\n";

	return EXIT_SUCCESS;
}
