#include <sstream>

#include "../include/trans.h"
#include "../include/utils.h"

namespace CoffeeBean {

	const std::string TransOut::str() {
		std::stringstream ss;
		ss << "TransOut:\n" 
		   << "\tAddr  : " << address << "\n"
		   << "\tAmount: " << amount;
		return ss.str();
	}

	const std::string TransInp::str() {
		std::stringstream ss;
		ss << "TransInp["     << id        << "]:\n" 
		   << "\tRoast    : " << roast     << "\n"
		   << "\tSignature: " << signature;
		return ss.str();
	}

	const std::string Trans::str() {
		std::stringstream ss;
		ss << "Trans[" << id << "]:\n" 
		   << "\tTransInps:\n";
		for(auto &transInp: transInps)
			ss << transInp.str() << "\n";
		for(auto &transOut: transOuts)
			ss << transOut.str() << "\n";
		return ss.str();
	}

	const std::string Trans::getId() {
		std::stringstream ss;
		for(auto &transInp: transInps)
			ss << transInp.roast
			   << std::to_string(transInp.id);
		for(auto &transOut: transOuts)
		 	ss << transOut.address
		 	   << std::to_string(transOut.amount);
		 return sha256(ss.str());
	}
	
}
