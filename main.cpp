#include <iostream> 
#include "Source.hpp"
using namespace std;

int R, innerInput; //to store user's menu options
bool menuON = true, correctInput, condition;
string membersOfR, innerMenusInput, sourceNums, confirmation; //to store user inputs

int main(int argc, char* argv[]){
	do { 
		PrintMainMenu(); correctInput = false;
		
		while(!correctInput){ // datatype handling
			try{ cin >> membersOfR; R = stoi(membersOfR); correctInput = true; }
			catch(...){ cout << "Please enter a valid number: "; }
		}

		switch(R){
			case 2: case 3: case 4: case 5: case 6:	case 7: case 8: case 9: case 10: 
			case 16: { // cascading cases
				PrintTargetMenu(R); correctInput = false;
				
				while(!correctInput){ // datatype handling
					try{ cin >> innerMenusInput; innerInput = stoi(innerMenusInput); correctInput = true; }
					catch(...){ cout << "Please enter a valid number: "; }
				}
				
				if(!(innerInput >= 2 && innerInput <= 10) && innerInput != 16){
					PrintExitMenu(innerInput); correctInput = false;
					
					while(!correctInput){ // validation loop
						cin >> confirmation; string lowerCaseConfirm = LowerCase(confirmation);
						if(ExitValidation(lowerCaseConfirm)){
							menuON = MenuStatus(lowerCaseConfirm); correctInput = true;
						}
						else{ cout << "Invalid input. Try again: "; correctInput = false; }
					} break;
				}

				else { // once input has been validated
					if(R != 16){ // non hex branch
						PrintConvMenu(R, innerInput); cin >> sourceNums;
						SourceToSource(R, innerInput, sourceNums); break;
					}
					else { // hex branch will work slightly differently
						int counter = 0; PrintConvMenu(R, innerInput);
						
						while(counter<5){ // input validation loop
							cin >> sourceNums; 
							if(HexValidation(sourceNums)){ HexToAny(sourceNums, innerInput); break; }
							
							counter++; // if the input is incorrect, program begins counting incorrect inputs
							if(counter == 5){
								cout << "\nNot a valid hex number!\nYou will be returned to the main menu.\n"; 
								SeperatorList(7);
							}
							else { cout << "Not a valid hex number! Try again:\n" << "Hexadecimal: "; }							
						}
					}
				} break;
			}

			default: { // exit menu
				PrintExitMenu(R); correctInput = false;
				
				while(!correctInput){ //input validation
					cin >> confirmation; string lowerCaseConfirm = LowerCase(confirmation);
					if(ExitValidation(lowerCaseConfirm)){
						menuON = MenuStatus(lowerCaseConfirm); correctInput = true;
					}
					else { cout << "Invalid input. Try again: "; correctInput = false; }
				} cout << endl; break;
			}
		}
	} while(menuON == true);
 return 0;
}
// hex to binary overflows at a certain point
// validation for number base inputs
