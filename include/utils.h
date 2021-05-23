#pragma once

#include <string>

namespace CoffeeBean {

	const char* hexChar2Bin(char c);

	const std::string hex2Bin(std::string hex);
	const std::string sha256(std::string string);
}
