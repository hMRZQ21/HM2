#ifndef Source_h
#define Source_h
#include <string> 
#include <cctype>
#include <cmath>
using namespace std; 

void SeperatorList(int num){
	switch(num){
		case 1: for(int i=0; i<=6; i++){ cout << "-"; } cout << endl; break; 
		case 2: for(int i=0; i<=11; i++){ cout << "-"; } cout << endl; break; 
		case 3: for(int i=0; i<=22; i++){ cout << "-"; } cout << endl; break; 
		case 4: for(int i=0; i<=36; i++){ cout << "-"; } cout << endl; break; 
		case 5: for(int i=0; i<=42; i++){ cout << "-"; } cout << endl; break; 
		case 6: for(int i=0; i<=46; i++){ cout << "-"; } cout << endl; break; 
		case 7: for(int i=0; i<=55; i++){ cout << "-"; } cout << endl; break; 
	}
}

bool MenuStatus(char confirmation){
	bool menuON;
	if(confirmation == 'Y' || confirmation == 'y'){ cout << "BYE!\n"; menuON = false; }
	else if(confirmation == 'N' || confirmation == 'n'){
		cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n"; SeperatorList(7); menuON = true; 
	}
	return menuON;
}

bool HexValidation(string hex){ //used in validation loop for hex input
	bool validHex = false; int i;
	for(i=0; i<hex.size(); i++){ if(!isxdigit(hex[i])){ return false; }}
	return true;
}

bool validate(bool condition){ //also used in the hex validation loop
	if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Incorrect input. Try again: "; return false; }
	return true;
}

void PrintSourceMenu(){
	cout << "(2) BINARY\n" << "(3) TERNARY\n" << "(4) QUATERNARY\n";
	cout << "(5) QUINARY\n" << "(6) SENARY\n" << "(7) SEPTENARY\n" << "(8) OCTAL\n";
	cout << "(9) NONARY\n" << "(10) DECIMAL\n" << "(16) HEXADECIMAL\n\n";
	cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n"; SeperatorList(5);
	cout << "Insert menu option: ";
}

void PrintMainMenu(){
	cout << endl; SeperatorList(4);
	cout << "Number System Conversion "; SeperatorList(2); SeperatorList(4);
	cout << "CHOOSE YOUR SOURCE NUMBER SYSTEM:\n"; PrintSourceMenu();
}

void PrintTargetMenu(int membersOfR){
	cout << endl; SeperatorList(4);
	cout << "Source Number System: " << membersOfR << " "; SeperatorList(2); SeperatorList(4);
	cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n"; PrintSourceMenu();
}

void PrintExitMenu(int membersOfR){
	cout << endl; SeperatorList(4); cout << "Confirm Close "; SeperatorList(3); SeperatorList(4);
	cout << "YOU ENTERED: " << membersOfR << endl;
	cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM? (Y/N)\n" << "Enter confirmation: ";
}

void SwitchList(int membersOfR){
	switch(membersOfR){
		case 2: cout << "BINARY: "; break; 
		case 3: cout << "TERNARY: "; break;
		case 4: cout << "QUATERNARY: "; break;
		case 5: cout << "QUINARY: "; break;
		case 6: cout << "SENARY: "; break;
		case 7: cout << "SEPTENARY: "; break;
		case 8: cout << "OCTAL: "; break;
		case 9: cout << "NONARY: "; break;
		case 10: cout << "DECIMAL: "; break;
		case 16: cout << "HEXADECIMAL: "; break;
	}
}

void PrintConvMenu(int membersOfR, int innerMenusInput){
	cout << endl; SeperatorList(7); cout << "Source Number System: " << membersOfR;
	cout << ", Target Number System: " << innerMenusInput << " "; SeperatorList(1); SeperatorList(7);
	cout << "INPUT YOUR NUMBER IN SOURCE NUMBER SYSTEM:\n"; SwitchList(membersOfR);
}

void ToHex(int decimal){ // does conversions to hex 
	int n = decimal, i = 0, temp; string hex = "";
	while(n != 0){
		temp = 0; temp = n%16;
		if(temp<10){ hex[i] = temp + 48; i++; }
		else{ hex[i] = temp + 55; i++; }
		n /= 16;
	}
	for(int j=i-1; j>=0; j--){ cout << hex[j]; }
	cout << endl << endl; MenuStatus('n');
}

void SourceToSource(int membersOfR, int innerMenusInput, string sourceNums){ // does base to base conversions
	SwitchList(innerMenusInput); 
	int base = membersOfR, digitized = 0, toDec = 0, result = 0, t = 1;
	for(int i=0; i<sourceNums.size(); i++){
		digitized = sourceNums[i] - '0'; toDec += digitized * pow(base, (sourceNums.size()-i-1));
	}
	if(innerMenusInput == 16){ ToHex(toDec); }
	else{
		while(toDec>0){ result += (toDec%innerMenusInput)*t; toDec /= innerMenusInput; t *= 10; }
		cout << result << endl; MenuStatus('n');	
	}
}

void HexToAny(string hex, int innerMenusInput){ //does hex to base conversions
	SwitchList(innerMenusInput);
	if(innerMenusInput == 16){ cout << hex << endl; }
	else{
		int temp = 0, toBinary = 0, result = 0, t = 1, base = innerMenusInput;
		for(int i=0; i< hex.size(); i++){
			if('a' <= hex[i] && hex[i] <= 'f'){ temp = hex[i] - 'a' + 10; } 
			else if('A' <= hex[i] && hex[i] <= 'F'){ temp = hex[i] - 'A' + 10; }
			else { temp = hex[i] - '0'; }
			toBinary += temp * pow(16, hex.size() - i - 1);
		}
		while(toBinary>0){ result += (toBinary%base)*t; toBinary /= base; t *= 10; }
		cout << result << endl;
	}
	MenuStatus('n');
}

#endif
