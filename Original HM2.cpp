//Name: Hussam Marzooq
//EMPLID: 23911169

#include <iostream>
#include <cctype>
#include <string> //to read user numbers to be converted
#include <cmath> //for pow function used in conversions
using namespace std; 

int main() {

	int membersOfR, innerMenusInput; //to store user's menu options
	int result = 0, digitized = 0, base; //for use in conversions & output
	char confirmation; //to store user Yes/No
	bool menuON = true;
	bool exitScreen = false;
	bool sourceUnderTen = false; //all bools are for activating sub-menus
	bool sourceIsDeci = false;
	bool sourceIsHex = false;
	string sourceNums, hexNumber = ""; //to store user inputs & outputs

	do { //main menu as do-while loop
		for (int i= 0; i <= 36; i++){ cout << "="; }
		cout << endl; 
		/* This for loop is to imitate the sample format of = signs and repeats many times over
		  the duration of this program with different lengths of = signs. */

		cout << "Number System Conversion ";

		for (int i= 0; i<= 12; i++){ cout << "="; }
		cout << endl;

		for (int i= 0; i <= 36; i++){ cout << "="; }
		cout << endl;

		cout << "CHOOSE YOUR SOURCE NUMBER SYSTEM:\n";
		cout << "(2) BINARY\n";
		cout << "(3) TERNARY\n";
		cout << "(4) QUATERNARY\n";
		cout << "(5) QUINARY\n";
		cout << "(6) SENARY\n";          // main menu options
		cout << "(7) SEPTENARY\n";
		cout << "(8) OCTAL\n";
		cout << "(9) NONARY\n";
		cout << "(10) DECIMAL\n";
		cout << "(16) HEXADECIMAL\n";
		cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n";

		for (int i= 0; i <= 42; i++){ cout << "="; } 
		cout << endl;
		cin >> membersOfR; //take input

		switch (membersOfR){ //to activate specific sub-menus
			case 2: 
			case 3: 
			case 4: 
			case 5:    //fall through cases because they all are the same proccess
			case 6: 
			case 7: 
			case 8: 
			case 9: 

				sourceUnderTen = true;
				while(sourceUnderTen == true){ //activating sub-menu

					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;
					
					cout << "Source Number System: " << membersOfR << " ";
	
					for (int i= 0; i<= 12; i++){ cout << "="; }
					cout << endl;

					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;

					cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n";
					cout << "(10) DECIMAL\n"; 
					cout << "INPUT ANY OTHER VALUE TO QUIT THE PROGRAM.\n";
					
					for (int i= 0; i <= 55; i++){ cout << "="; }
					cout << endl;
					
					cin >> innerMenusInput; //take in value to be converted or exit
					
					if(innerMenusInput == 10){ //conversion happens from sources to decimal
						for (int i= 0; i <= 55; i++){ cout << "="; }
						cout << endl;
						
						cout << "Source Number System: " << membersOfR;
						cout << ", Target Number System: " << innerMenusInput << " ";
	
						for (int i= 0; i<= 6; i++){ cout << "="; }
						cout << endl;

						for (int i= 0; i <= 55; i++){ cout << "="; }
						cout << endl;
						
						cout << "INPUT YOUR NUMBER IN SOURCE NUMBER SYSTEM:\n";
						
						switch(membersOfR){ //to ask for the correct source input
							case 2: cout << "BINARY: "; break;
							case 3: cout << "TERNARY: "; break;
							case 4: cout << "QUATERNARY: "; break;
							case 5: cout << "QUINARY: "; break;
							case 6: cout << "SENARY: "; break;
							case 7: cout << "SEPTENARY: "; break;
							case 8: cout << "OCTAL: "; break;
							case 9: cout << "NONARY: "; break;
						}
						cin >> sourceNums; //taking input as a string

						base = membersOfR; //to generalize over all sources

						for (int i=0; i< sourceNums.size(); i++) {
       						digitized = sourceNums.at(i) - '0' ;
       						result += digitized * pow(base, (sourceNums.size() - i - 1));
    					} 
    					/* this loop iterates over the index of a string and stores its numerical
    					   equivalent in another variable which then is used to do the generalized
    					   conversion and stored in a result variable */

    					cout << "DECIMAL: " << result << endl;

    					result = 0;      
    					/* this is to ensure we get a correct result each time we repeat 
    					   this process */

						cout << "YOU WILL BE RETURNED TO MAIN MENU.\n";
						for (int i= 0; i <= 55; i++){ cout << "="; }
						cout << endl << endl;

						menuON = true; break;
					}
					else { //exit program. This repeats for cases 10 and 16 as well
						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl;
						cout << "Confirm Close ";

						for (int i= 0; i<= 36; i++){ cout << "="; }
						cout << endl;

						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl;

						cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM? (Y/N)\n";
						cin >> confirmation; //taking input as a char

						if(confirmation == 'Y'){
							cout<< "BYE!\n";
							menuON = false; //to exit program
						}
						else if(confirmation == 'N'){
							cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
							menuON = true; //to loop back to main menu
						}

						for (int i= 0; i<= 46; i++){ cout << "="; }
						cout << endl << endl; break;
						
						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl;
					}
				}	
			break; //breaking out of every case

			case 10: 
				sourceIsDeci = true;
				while(sourceIsDeci == true){
					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;
					
					cout << "Source Number System: " << membersOfR << " ";
	
					for (int i= 0; i<= 11; i++){ cout << "="; }
					cout << endl;

					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;

					cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n";
					cout << "(2) BINARY\n";
					cout << "(3) TERNARY\n";
					cout << "(4) QUATERNARY\n";
					cout << "(5) QUINARY\n";
					cout << "(6) SENARY\n";         
					cout << "(7) SEPTENARY\n";
					cout << "(8) OCTAL\n";
					cout << "(9) NONARY\n";
					cout << "(16) HEXADECIMAL\n";
					cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n";

					for (int i= 0; i <= 55; i++){ cout << "="; }
					cout << endl;
					
					cin >> innerMenusInput;
					
					if((innerMenusInput >= 2 && innerMenusInput <= 9) || innerMenusInput == 16){
					/* conversion happens from decimal to sources (aka reverse of previous cases)
					   with the addition of a hexadecimal case */

						for (int i= 0; i <= 55; i++){ cout << "="; }
						cout << endl;

						cout << "Source Number System: " << membersOfR;
						cout << ", Target Number System: " << innerMenusInput << " ";
	
						for (int i= 0; i<= 5; i++){ cout << "="; }
						cout << endl;

						for (int i= 0; i <= 55; i++){ cout << "="; }
						cout << endl;

						cout << "INPUT YOUR NUMBER IN SOURCE BASE:\n";
						cout << "DECIMAL: ";
						cin >> sourceNums; 
						//reading input as a string even in the case of hexadecimal
						
						if(innerMenusInput != 16){
							digitized = 0;
							int t = 1;
							base = membersOfR; //essentially base 10

							for (int i=0; i< sourceNums.size(); i++) { 
								//getting the equivalent numerical values
        						
        						digitized += sourceNums.at(i) - '0' ;
        						digitized *= 10;
    						} 
    						digitized /= 10; //to fix the extra 0 at the end of a number
    					
    						while(digitized > 0){ // actual conversion happens here
        						result += (digitized% innerMenusInput)*t ;
       							digitized /= innerMenusInput ;
        						t *= base ;
   							}
						
							switch(innerMenusInput){
								case 2: cout << "BINARY: "; break;
								case 3: cout << "TERNARY: "; break;
								case 4: cout << "QUATERNARY: "; break;
								case 5: cout << "QUINARY: "; break;
								case 6: cout << "SENARY: "; break;
								case 7: cout << "SEPTENARY: "; break;
								case 8: cout << "OCTAL: "; break;
								case 9: cout << "NONARY: "; break;
							}
							cout << result << endl;
							result = 0;  //to ensure the result is correct each time
						}
						else if (innerMenusInput == 16){ //decimal to hex conversion happens
							digitized = 0;
							for (int i=0; i< sourceNums.size(); i++) { 
    							digitized += sourceNums.at(i) - '0' ;
    							digitized *= 10;
							}
							digitized /= 10; //to fix the extra 0 at the end of a number
							
							int remainder = 0; // to store remainder of modulo
							
							while(digitized > 0){
    							remainder = digitized %16;
    							if(remainder >9){
      								switch(remainder){
           								case 10: hexNumber = "A" + hexNumber; break;
            							case 11: hexNumber = "B" + hexNumber; break;
            							case 12: hexNumber = "C" + hexNumber; break;
            							case 13: hexNumber = "D" + hexNumber; break;
            							case 14: hexNumber = "E" + hexNumber; break;
            							case 15: hexNumber = "F" + hexNumber; break;
        							}
    							}
    							else { hexNumber = char(remainder + '0') + hexNumber; }
        						// Converts integers (0-9) to ASCII code and stores as char

        						digitized /= 16;
    						} 
    						//the same while structure to do conversion but modified with
    						//switch statement to take letters into account

							cout << "HEXADECIMAL: " << hexNumber << endl;
							hexNumber = "" ; 
						}
						cout << "YOU WILL BE RETURNED TO MAIN MENU.\n";

						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl << endl;
						menuON = true; break;
					}
					else { //exit program
						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl;
						cout << "Confirm Close ";

						for (int i= 0; i<= 32; i++){ cout << "="; }
						cout << endl;

						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl;

						cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM? (Y/N)\n";
						cin >> confirmation; //taking input

						if(confirmation == 'Y'){
							cout << "BYE!\n";
							
							for (int i= 0; i<= 46; i++){ cout << "="; }
							cout << endl ; 

							menuON = false; break; //to exit program
						}
						else if(confirmation == 'N'){
							cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
							sourceIsDeci = false; //to loop back to main menu
						}

						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl << endl;
					}
				}	
			break;
		
			case 16: 

				sourceIsHex = true;
				while(sourceIsHex == true){

					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;
					cout << "Source Number System: " << membersOfR << " ";
	
					for (int i= 0; i<= 11; i++){ cout << "="; }
					cout << endl;

					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;

					cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n";
					cout << "(8) OCTAL\n";
					cout << "(10) DECIMAL\n";
					cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n";

					for (int i= 0; i <= 55; i++){ cout << "="; }
					cout << endl;
					
					cin >> innerMenusInput; //taking input
					
					if (innerMenusInput == 8 || innerMenusInput == 10){
						//hex to octal or hex to decimal conversion happens

						for (int i= 0; i <= 56; i++){ cout << "="; }
						cout << endl;

						cout << "Source Number System: " << membersOfR;
						cout << ", Target Number System: " << innerMenusInput << " ";
	
						for (int i= 0; i<= 6; i++){ cout << "="; }
						cout << endl;

						for (int i= 0; i <= 56; i++){ cout << "="; }
						cout << endl;

						cout << "INPUT YOUR NUMBER IN SOURCE BASE:\n";
						cout << "HEXADECIMAL: ";
						cin >> hexNumber;
						
						//validation loop goes here

						int temp = 0, digitizedInBinary = 0, t = 1;
						long binarized = 0;
						int decimalized = 0, octal = 0, j = 0; 
						//variables to be used for the conversions & loops

						switch(innerMenusInput){
							case 8: 
								/* in short, this conversion does hex to binary,
								   then binary to decimal, then to octal.
								   Reference (explains the proccess in high level): 
								   https://www.youtube.com/watch?v=ML_AkW97Axk */

								for (int i=0; i< hexNumber.size(); i++) {
      								if('a' <= hexNumber.at(i) && hexNumber.at(i) <= 'f'){
           								temp = hexNumber.at(i) + 10;
       								}
       								else if('A' <= hexNumber.at(i) && hexNumber.at(i) <= 'F'){
           								temp = hexNumber.at(i) - 'A' + 10;
       								}
       								else { temp = hexNumber.at(i) - '0' ; }
       								digitizedInBinary += temp * pow(16, hexNumber.size() - i - 1);
    							}	
    							while(digitizedInBinary > 0){
       								binarized += (digitizedInBinary% 2)*t ;
       								digitizedInBinary /= 2 ;
    								t *= 10 ;
   								}
  								//this does hex to binary.

    							while(binarized > 0){ //binary to decimal
        							decimalized += (binarized % 10) * pow(2,j);
        							j++ ; 
        							binarized /= 10;
    							}
    							
    							j = 1; //because we are multiplying with it below
    							
    							while(decimalized > 0){//then lastly decimal to octal
        							octal += (decimalized% 8)*j;
        							decimalized /= 8;
        							j *= 10;
    							}
								cout << "OCTAL: " << octal << endl; 
								octal = 0; //zero it for each repetition 
							
							break;
							
							case 10: //to do  hex to decimal conversion
								digitized = 0;
								for (int i=0; i< hexNumber.size(); i++) {
      								if('a' <= hexNumber.at(i) && hexNumber.at(i) <= 'f'){
            							digitized = hexNumber.at(i) - 'a' + 10 ;
        							}
       								else if('A' <= hexNumber.at(i) && hexNumber.at(i) <= 'F'){
          								digitized = hexNumber.at(i) - 'A' + 10 ;
      								}
       								else { digitized = hexNumber.at(i) - '0' ; }

       								result += digitized * pow(16, hexNumber.size() - i - 1);
   								}
								cout << "DECIMAL: " << result << endl; 
								result = 0; //reset every time
							
							break;
						}
						cout << "YOU WILL BE RETURNED TO MAIN MENU.\n";
						menuON = true; 

						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl << endl; break;
					}
					else { //exit program
						for (int i= 0; i <= 36; i++){ cout << "="; }
						cout << endl;
						cout << "Confirm Close ";

						for (int i= 0; i<= 22; i++){ cout << "="; }
						cout << endl;

						for (int i= 0; i <= 36; i++){ cout << "="; }
						cout << endl;

						cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM? (Y/N)\n";
						cin >> confirmation; //taking input

						if(confirmation == 'Y'){
							cout << "BYE!\n";
							
							for (int i= 0; i<= 46; i++){ cout << "="; }
							cout << endl; 

							menuON = false; break; //to exit program
						}
						else if(confirmation == 'N'){
							cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
							sourceIsHex = false; //to loop back to main menu
						}
						for (int i= 0; i <= 46; i++){ cout << "="; }
						cout << endl << endl;
					}
				}
			break;

			default: //default case is to exit program
				do { //exit confirmation as nested do-while loop
		
					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;

					cout << "Confirm Close ";

					for (int i= 0; i<= 22; i++){ cout << "="; }
					cout << endl;

					for (int i= 0; i <= 36; i++){ cout << "="; }
					cout << endl;

					cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM? (Y/N)\n";
					cin >> confirmation; //taking input

					if(confirmation == 'Y'){
						cout<< "BYE!\n";
						menuON = false; //to exit program
					}
					else if(confirmation == 'N'){
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
						menuON = true; //to loop back to main menu
					}

					for (int i= 0; i<= 46; i++){ cout << "="; }
					cout << endl << endl; break;

				} while(exitScreen == true);
		}

	} while(menuON == true);
	
	return 0;
}