#include <iostream>
#include "HM2 Functions.hpp"
using namespace std;

int membersOfR, innerMenusInput, base//to store user's menu options
int result = 0, digitized = 0, base; //for use in conversions & output
char confirmation; //to store user Yes/No
bool menuON = true, exitScreen = false;
string sourceNums, hexNumber = ""; //to store user inputs & outputs

int main() {

	do{
		PrintMainMenu();
		cin >> membersOfR;

		switch(membersOfR){
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:{
				PrintUnderTenSubMenu(membersOfR);
				cin >> innerMenusInput;
				
				break;
			}
			
			case 10:{
				PrintTenSubMenu();

				break;
			}
			
			case 16:{
				PrintHexSubMenu();

				break;
			}

			default:{
				do{
					PrintExitMenu(); cin >> confirmation;
					
					if(confirmation == 'Y'){
						cout<< "BYE!\n";
						menuON = false; //to exit program
					}
					else if(confirmation == 'N'){
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
						menuON = true; //to loop back to main menu
					}
					SeperatorList(6); cout << endl;
					break;

				} while(exitScreen == true);
			}

		}

	} while(menuON == true);

	return 0;
}
