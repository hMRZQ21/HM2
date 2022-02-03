#ifndef Source_h
#define Source_h
#include <string> 
#include <cctype>
#include <cmath>
#include <vector>
using namespace std; 

vector<string> yes = {"y","ye", "yes", "yea", "yeah"};
vector<string> no = {"n", "no", "na", "nah"};

string LowerCase(string confirmation){ // changes exit menu confirmation input to lowercase
	string lowerCase; 
	for(int i=0; i<confirmation.size(); i++){ lowerCase += tolower(confirmation[i]); }
	return lowerCase;
}	

void SeperatorList(int num){ // for readability sake
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

bool MenuStatus(string confirmation){ // 
	for(int i=0; i<5; i++){
		if(yes[i] == confirmation){ cout << "\n...Bye!\n"; return false; }
		else if(no[i] == confirmation){
			cout << "\nYou will be returned to the main menu.\n"; SeperatorList(7); return true;
		}
		else { continue; }
	}	return false;
}

bool ExitValidation(string confirmation){ // utilizes the string arrays of "acceptable" exit..
	for(int i=0; i<5; i++){ 								// ...confirmations
		if(confirmation == yes[i] || confirmation == no[i]){ return true; }
		else { continue; }
	} return false;
}

bool HexValidation(string hex){ // validates hex input
	bool validHex = false;
	for(int i=0; i<hex.size(); i++){
		if(!isxdigit(hex[i])){ return false; }
	}
	return true;
}

bool validate(bool condition){ // used in input validation
	if(cin.fail()){ cin.clear(); cin.ignore(); cout << "Incorrect input. Try again: "; return false; }
	return true;
}

void PrintSourceMenu(){ // prints part of the main menu
	cout << "(2) Binary\n" << "(3) Ternary\n" << "(4) Quaternary\n" << "(5) Quinary\n";
	cout << "(6) Senary\n" << "(7) Septenary\n" << "(8) Octal\n" << "(9) Nonary\n";
	cout << "(10) Decimal\n" << "(16) Hexadecimal\n\n" << "Input any other value to exit the program.\n";
	SeperatorList(5); cout << "Insert menu option: ";
}

void PrintMainMenu(){ // main menu format
	cout << endl; SeperatorList(4); cout << "Number System Conversion ";
	SeperatorList(2); SeperatorList(4); cout << "Choose the source number system:\n"; PrintSourceMenu();
}

void PrintTargetMenu(int R){ // target menu format
	cout << endl; SeperatorList(4); cout << "Source Number System: " << R << " ";
	SeperatorList(2); SeperatorList(4); cout << "Choose the target number system:\n"; PrintSourceMenu();
}

void PrintExitMenu(int R){ // exit menu format
	cout << endl; SeperatorList(4); cout << "Confirm Close "; SeperatorList(3); SeperatorList(4);
	cout << "You entered: " << R << endl; cout << "Do you want to exit the program? (Y/N)\n";
	cout << "Enter confirmation: ";
}

void SwitchList(int R){ // for readability sake
	switch(R){
		case 2: cout << "Binary: "; break; /**/ case 3: cout << "Ternary: "; break;
		case 4: cout << "Quaternary: "; break; /**/ case 5: cout << "Quinary: "; break;
		case 6: cout << "Senary: "; break; /**/ case 7: cout << "Septenary: "; break;
		case 8: cout << "Octal: "; break; /**/ case 9: cout << "Nonary: "; break;
		case 10: cout << "Decimal: "; break; /**/ case 16: cout << "Hexadecimal: "; break;
	}
}

void PrintConvMenu(int R, int innerInput){ // conversion menu format
	cout << endl; SeperatorList(7); cout << "Source Number System: " << R;
	cout << ", Target Number System: " << innerInput << " "; SeperatorList(1); SeperatorList(7);
	cout << "Input the number to be converted (in its source base):\n"; SwitchList(R);
}

void ToHex(int decimal){ // converts from decimal to hex
	int n = decimal, i = 0, temp; string hex = "";
	while(n != 0){
		temp = 0; temp = n%16;
		if(temp < 10){ hex[i] = temp + 48; i++; }
		else { hex[i] = temp + 55; i++; }
		n /= 16;
	}
	for(int j=i-1; j>=0; j--){ cout << hex[j]; }
	cout << endl; MenuStatus("n");
}

void SourceToSource(int R, int innerInput, string sourceNums){  
	SwitchList(innerInput); // converts from base 2-10,16 to base 2-10,16
	int base = R, digitized = 0, toDec = 0, result = 0, t = 1;
	for(int i=0; i<sourceNums.size(); i++){
		digitized = sourceNums[i] - '0'; 
		toDec += digitized * pow(base, (sourceNums.size()-i-1));
	}
	if(innerInput == 16){ ToHex(toDec); }
	else {
		while(toDec > 0){ result += (toDec%innerInput)*t; toDec /= innerInput; t *= 10; }
		cout << result << endl; MenuStatus("n");	
	}
}

void HexToAny(string hex, int innerInput){ // converts from hex to base 2-10
	SwitchList(innerInput);
	if(innerInput == 16){ cout << hex << endl; }
	else { 
		unsigned long long temp = 0, t = 1, base = innerInput, toDec = 0, result = 0; 
		for(int i=0; i<hex.size(); i++){
			if('a' <= hex[i] && hex[i] <= 'f'){ temp = hex[i] - 'a' + 10; } 
			else if('A' <= hex[i] && hex[i] <= 'F'){ temp = hex[i] - 'A' + 10; }
			else { temp = hex[i] - '0'; }
			toDec += temp * pow(16, hex.size() - i - 1);
		}
		while(toDec > 0){ result += (toDec%base)*t; toDec /= base; t *= 10; } 
		cout << result << endl;
	} MenuStatus("n");
}
#endif
