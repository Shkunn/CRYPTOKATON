#include <string>
#include <vector>

namespace CoffeeBean {

	struct TransOut {
		std::string address;
		int         amount;
			
		const std::string str();
	};

	struct TransInp {
		size_t       id;
		std::string  roast;
		std::string  signature;
		
		const std::string str();
	};

	struct Trans {
		std::string           id;
		std::vector<TransInp> transInps;
		std::vector<TransOut> transOuts;

		const std::string getId();

		const std::string str();
	};
	
}
