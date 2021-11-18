#include <iostream>
#include <cctype>
#include <string> //to read user numbers to be converted
#include <cmath> //for pow function used in conversions
using namespace std; 

int main() { // work in progress

	string hexNumber = ""; //to store user inputs & outputs
	int counter = 0;
	bool hexValidation = true, invalidPrompter = false, menuON = true, validHex = false;
	cout << "HEXADECIMAL: ";
	cin >> hexNumber;

	while (hexValidation == true){
		for(int i=0; i< hexNumber.size(); i++){
			if(!isxdigit(hexNumber.at(i) && hexNumber.back())){ 
				counter++; 
					if(counter == 5){
						cout << "INVALID INPUT!\n";
						cout << "YOU WILL BE RETURNED TO MAIN MENU\n";
						menuON = true; 
						hexValidation = false; break;
					}

				invalidPrompter = true;
				hexValidation = false; break; 
			}
			else{
			    validHex = true; 
		        hexValidation = false; break;
		    }
		}
	}

	do{
		cout << "INVALID INPUT! TRY AGAIN:\n";
		cout << "HEXADECIMAL: ";
		cin >> hexNumber;
		
		hexValidation = true; 
		invalidPrompter = false; break;

	} while (invalidPrompter == true && counter <5);

	while(validHex == true){
		cout << "Conversion happens\n";
		break;
	}


 return 0;
}
