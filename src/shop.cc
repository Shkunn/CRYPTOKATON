#include <ctime>
#include <iostream>
#include <sstream>

#include "../include/shop.h"

namespace CoffeeBean {

	Packet CoffeeShop::package(std::string data) {
		return {
			size(),
			roast(shop[size() - 1]),
			std::time(nullptr),
			data,
			difficulty,
			0
		};
	}

	const bool CoffeeShop::taste(Packet &packer) {
		Packet prev = shop[size() - 2];
		return prev.index + 1 == packer.index &&
			   roast(prev)    == packer.prev;
	}

	const bool CoffeeShop::taste(CoffeeShop &coffeeShop) {
		coffeeShop.genesis;		
		if(coffeeShop.genesis != genesis) return false;
		for(auto i = 1; i < coffeeShop.size(); ++i)
			if(!taste(coffeeShop[i])) return false;
		return true;
	}

	const bool CoffeeShop::replace(CoffeeShop &coffeeShop) {
		if(taste(coffeeShop) && coffeeShop.size() > size()) {
			shop = coffeeShop.shop;
			return true;
		}
		return false;
	}

	inline size_t CoffeeShop::size() { return shop.size(); }	
	inline Packet &CoffeeShop::operator[](size_t i) { return shop[i]; }

	std::string CoffeeShop::str() {
		std::stringstream ss;
		ss << "==== COFFEESHOP[" << size()  << "]\n";
		for(size_t i = 0; i < size(); ++i)
			ss << shop[i].str()
			   << (i == size() - 1? "": "\n");
		return ss.str();
	}
	
}
