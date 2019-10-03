#include <iostream>
#include <unistd.h>
#include "Cipher.h"

void mess(void); // How to use the program

int main( int argc, char **argv ) {
	
	char opt;	
	int eflag = 0, dflag = 0;
	const char* argumentText = NULL;
	int shifts = 0;	
	std::string input;
	char operation;
	
	if(argc > 1 ) { //Is there any arguments? If not it couts some help
		
		//getopt is for extracting parameters from terminal
		while((opt = getopt(argc, argv, "e:d:s:")) != -1)
		{
			//There are three basic options "encrytion/decryption/shifts"
			switch(opt)
			{
				case 'e':
				
					if( dflag == 0 ) {
						argumentText = optarg ? optarg : NULL;
						eflag = 1;
					}else{
						std::cout << "You can only do one operation at a time !!" << std::endl;
						exit(1);
					}
			
					operation = 'e';
					
					break;

				case 'd':

					if( eflag == 0 ) {
						argumentText = optarg ? optarg : NULL;
						dflag = 1;
					} else { 
						std::cout << "You can only do one operation at a time !!" << std::endl;
						exit(1);
					}
		
					operation = 'd';

					break;

				case 's':
					
					shifts = optarg ? atoi(optarg) : 0;
					
					break;
			}
		}
	} else { 
		mess(); //Directions 
	}

	// If One of two arguments is empty it stops the process
	if( (shifts == 0) || (argumentText == NULL) ) {
		std::cout << "You have to enter both text and number of shifts !!" << std::endl;
		exit(1);
	}

	input = argumentText;
	
	std::cout << "\033[H\033[2J\n" << "<--------Ceasar Cipher-------->\n";		
	Cipher c(input, shifts);
	
	switch(operation) {

		case 'e': printf("Encrypted text: %s\n", c.encrypt().c_str()); break;
		case 'd': printf("Decrypted text: %s\n", c.decrypt().c_str()); break;
	}

	std::cout << std::endl;

	return 0;
}

void mess(void) { 
	using namespace std;

	cout << "Ceasar Cipher\n" << endl;
	cout << "This is an attempt to create Ceasars Cipher(Encryptor/Decryptor) with C++.\n" << endl;
	cout << "Usage: eg. caesar -e <Text> -s <Shifts>" << endl;
	cout << "	-e encrypt given text, is nessesary to provide the shift number." << endl;
	cout << "	-s number of Shifts. Eg. -s 2.. A -> C." << endl;
	cout << "	-d decrypt given text, is nessasary to provide the shift number.\n" << endl;
}
