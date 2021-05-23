#include <sstream>
#include <string>
#include <vector>

#include "../include/packet.h"
#include "../include/utils.h"

namespace CoffeeBean {

	const bool Packet::match() const {
		std::string hash = roast(this);
		std::string bin = hex2Bin(hash);
		for(auto i = 0; i < difficulty; ++i)
			if(bin[i] != '0') return false;
		return true;
	}

	void Packet::grind() {
		for(;;nonce++) if(match()) break;
	}

	bool Packet::operator!=(const Packet &other) const {
		return index       != other.index      ||
			   roast(this) != roast(other)     ||
			   prev        != other.prev       ||
			   timestamp   != other.timestamp  ||
			   data        != other.data       ||
			   difficulty  != other.difficulty ||
			   nonce       != other.nonce;
	}
	
	std::string Packet::str() {
		std::stringstream ss;
		ss << "Packet["    << index       << "]:\n"
		   << "\tcRoast: " << roast(this) << "\n"
		   << "\tpRoast: " << prev        << "\n"
		   << "\tStamp : " << timestamp   << "\n"
		   << "\tData  : " << data        << "\n"
		   << "\tDiff  : " << difficulty  << "\n"
		   << "\tNonce : " << nonce;
		return ss.str();
	}

	std::string roast(Packet *packet) {
		return roast(
			packet->index,
			packet->prev,
			packet->timestamp,
			packet->data,
			packet->difficulty,
			packet->nonce
		);
	}

	std::string roast(Packet &packet) {
		return roast(
			packet.index,
			packet.prev,
			packet.timestamp,
			packet.data,
			packet.difficulty,
			packet.nonce
		);
	}
	
	std::string roast(const Packet *packet) {
		return roast(
			packet->index,
			packet->prev,
			packet->timestamp,
			packet->data,
			packet->difficulty,
			packet->nonce
		);
	}

	std::string roast(const Packet &packet) {
		return roast(
			packet.index,
			packet.prev,
			packet.timestamp,
			packet.data,
			packet.difficulty,
			packet.nonce
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

		return sha256(
			nonce_str      +
			index_str      +
			prev           +
			timestamp_str  +
			data           +
			difficulty_str
		);
	}

}

