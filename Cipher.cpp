#include <iostream>
#include "Cipher.h"

/*    Constructor */
Cipher::Cipher(std::string input, int s) {

	this->input = input;
	this->shifts = s;
	printf("Original text: %s\n", this->input.c_str()); 
}

/*    Encryption    */
std::string Cipher::encrypt() {

	int i=0;
	
	//Declaring reference for the sake of the convenience	
	std::string& strRef = this->input;  
	int& intRef = this->shifts;
	
	//The magic happens here
	while(i < strRef.size()){
	
		char c = strRef[i];	

		//lowecase
		if(c >= 'a' && c <= 'z') {
			c = c + intRef;
			if(c > 'z'){
				c = c - 'z' + 'a' - 1;
			}
			strRef[i] = c;
		} 
		//upercase
		else if(c >= 'A' && c <= 'Z') {
			c = c + intRef;
			if(c > 'Z'){
				c = c - 'Z' + 'A' - 1;
			}
			strRef[i] = c;
		}
		
		i++;
	}
	
	return strRef;
}

/*    Decryption    */
std::string Cipher::decrypt() {

	int i=0;
	
	//Declaring reference for the sake of the convenience	
	std::string& strRef = this->input;  
	int& intRef = this->shifts;
	
	//The magic happens here
	while(i < strRef.size()){
	
		char c = strRef[i];	
		//lowecase
		if(c >= 'a' && c <= 'z') {
			c = c - intRef;
			if(c < 'a'){
				c = c + 'z' - 'a' + 1;
			}
			strRef[i] = c;
		} 
		//upercase
		else if(c >= 'A' && c <= 'Z') {
			c = c - intRef;
			if(c < 'A'){
				c = c + 'Z' - 'A' + 1;
			}
			strRef[i] = c;
		}
		
		i++;
	}
	
	return strRef;
}

