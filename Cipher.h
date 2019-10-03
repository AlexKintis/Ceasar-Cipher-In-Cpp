#include <iostream>

class Cipher {

	private:
		std::string input;
		int shifts;
	public: 
		Cipher(std::string, int);
		std::string encrypt();
		std::string decrypt();
};
