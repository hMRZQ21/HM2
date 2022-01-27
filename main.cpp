#include <iostream> 
#include "Source.hpp"
using namespace std;

int membersOfR, innerMenusInput; //to store user's menu options
char confirmation; //to store user Yes/No
bool menuON = true, correctInput, condition;
string sourceNums; //to store user inputs

int main(int argc, char* argv[]){
	do{
		PrintMainMenu(); correctInput = false;
		while(!correctInput){ cin >> membersOfR; condition = cin.fail(); correctInput = validate(condition); }
		switch(membersOfR){
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:	// cascading cases
			case 7: 
			case 8:
			case 9:
			case 10:{
				PrintTargetMenu(membersOfR); correctInput = false;
				while(!correctInput){
					cin >> innerMenusInput; condition = cin.fail(); correctInput = validate(condition);
				}
				if(!(innerMenusInput >= 2 && innerMenusInput <= 10) && innerMenusInput != 16){
					PrintExitMenu(innerMenusInput); cin >> confirmation; menuON = MenuStatus(confirmation);
				}
				else{
					PrintConvMenu(membersOfR, innerMenusInput); cin >> sourceNums;
					SourceToSource(membersOfR, innerMenusInput, sourceNums); break;
				}
				break;
			}

			case 16:{
				PrintTargetMenu(membersOfR); correctInput = false;
				while(!correctInput){
					cin >> innerMenusInput; condition = cin.fail(); correctInput = validate(condition); 
				}
				if(!(innerMenusInput >= 2 && innerMenusInput <= 10) && innerMenusInput != 16){
					PrintExitMenu(innerMenusInput); cin >> confirmation; menuON = MenuStatus(confirmation);
				}	
				else{
					int counter = 0; PrintConvMenu(membersOfR, innerMenusInput);
					while(counter<5){ // input validation loop
						cin >> sourceNums;
						if(HexValidation(sourceNums)){ HexToAny(sourceNums, innerMenusInput); break; }
						// actual conversions when hex is valid
						else { counter++;
							if(counter == 5){
								cout << "NOT A VALID NUMBER!\nYOU WILL BE RETURED TO THE MAIN MENU.\n"; SeperatorList(7);
							}
							else{ cout << "NOT A VALID NUMBER! TRY AGAIN:\n" << "HEXADECIMAL: "; }
						}
					}
				}
				break;
			}
				
			default:{
				PrintExitMenu(membersOfR); cin >> confirmation; menuON = MenuStatus(confirmation);
				cout << endl; break;
			}
		}
	}
  while(menuON == true);
 return 0;
}
// datatype handling only works for one character at a time, because it doesn't implement streams. 