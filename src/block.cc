#include <iomanip>
#include <openssl/sha.h>
#include <sstream>
#include <string>

#include "../include/block.h"

namespace CoffeeBean {

	const char* hexChar2Bin(char c) {
		switch(toupper(c)) {
			case '0': return "0000";
			case '1': return "0001";
			case '2': return "0010";
			case '3': return "0011";
			case '4': return "0100";
			case '5': return "0101";
			case '6': return "0110";
			case '7': return "0111";
			case '8': return "1000";
			case '9': return "1001";
			case 'A': return "1010";
			case 'B': return "1011";
			case 'C': return "1100";
			case 'D': return "1101";
			case 'E': return "1110";
			case 'F': return "1111";
		}
		return nullptr;
	}

	std::string hex2Bin(const std::string &hex) {
		std::string bin;
		for(auto i = 0; i != hex.length(); ++i)
			bin += hexChar2Bin(hex[i]);
		return bin;
	}

	const bool Block::match() const {
		std::string hash = roast(this);
		std::string bin = hex2Bin(hash);
		for(auto i = 0; i < difficulty; ++i)
			if(bin[i] != '0') return false;
		return true;
	}

	void Block::mine() {
		for(;;nonce++) if(match()) break;
	}

	bool Block::operator!=(const Block &other) const {
		return index       != other.index      ||
			   roast(this) != roast(other)     ||
			   prev        != other.prev       ||
			   timestamp   != other.timestamp  ||
			   data        != other.data       ||
			   difficulty  != other.difficulty ||
			   nonce       != other.nonce;
	}
	
	std::string Block::str() {
		std::stringstream ss;
		ss << "Block["    << index       << "]:\n"
		   << "\tcHash: " << roast(this) << "\n"
		   << "\tpHash: " << prev        << "\n"
		   << "\tStamp: " << timestamp   << "\n"
		   << "\tData : " << data        << "\n"
		   << "\tDiff : " << difficulty  << "\n"
		   << "\tNonce: " << nonce;
		return ss.str();
	}

	std::string roast(Block *block) {
		return roast(
			block->index,
			block->prev,
			block->timestamp,
			block->data,
			block->difficulty,
			block->nonce
		);
	}

	std::string roast(Block &block) {
		return roast(
			block.index,
			block.prev,
			block.timestamp,
			block.data,
			block.difficulty,
			block.nonce
		);
	}
	
	std::string roast(const Block *block) {
		return roast(
			block->index,
			block->prev,
			block->timestamp,
			block->data,
			block->difficulty,
			block->nonce
		);
	}

	std::string roast(const Block &block) {
		return roast(
			block.index,
			block.prev,
			block.timestamp,
			block.data,
			block.difficulty,
			block.nonce
		);
	}
	
	std::string roast(
		size_t       index,
		std::string  prev,
		std::time_t  timestamp,
		std::string  data,
		unsigned int difficulty,
		unsigned int nonce
	) {
		std::string index_str      = std::to_string(index);
		std::string timestamp_str  = std::to_string(timestamp);
		std::string difficulty_str = std::to_string(difficulty);
		std::string nonce_str      = std::to_string(nonce);
		
		unsigned char hash[SHA256_DIGEST_LENGTH];
			
		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		SHA256_Update(&sha256,      index_str.c_str(),      index_str.size());		
		SHA256_Update(&sha256,           prev.c_str(),           prev.size());		
		SHA256_Update(&sha256,  timestamp_str.c_str(),  timestamp_str.size());		
		SHA256_Update(&sha256,           data.c_str(),           data.size());
		SHA256_Update(&sha256, difficulty_str.c_str(), difficulty_str.size());
		SHA256_Update(&sha256,      nonce_str.c_str(),      nonce_str.size());
		SHA256_Final(hash, &sha256);

		std::stringstream ss;
		for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
		return ss.str();		
	}

}

