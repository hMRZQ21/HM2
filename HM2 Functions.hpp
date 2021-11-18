#ifndef HM2_Functions_h
#define HM2_Functions_h

#include <iostream>
#include <cctype>
#include <string> //to read user numbers to be converted
#include <cmath> //for pow function used in conversions
using namespace std; 

void SeperatorList(int a){
	switch(a){
		case 1:{ for (int i= 0; i <= 6; i++){ cout << "-"; } cout << endl; break; }
		case 2:{ for (int i= 0; i <= 12; i++){ cout << "-"; } cout << endl; break; }
		case 3:{ for (int i= 0; i <= 22; i++){ cout << "-"; } cout << endl; break; }
		case 4:{ for (int i= 0; i <= 36; i++){ cout << "-"; } cout << endl; break; }
		case 5:{ for (int i= 0; i <= 42; i++){ cout << "-"; } cout << endl; break; }
		case 6:{ for (int i= 0; i <= 46; i++){ cout << "-"; } cout << endl; break; }
		case 7:{ for (int i= 0; i <= 55; i++){ cout << "-"; } cout << endl; break; }
	}
}

void PrintMainMenu(){
	SeperatorList(4);
	cout << "Number System Conversion "; SeperatorList(2); SeperatorList(4);

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
	SeperatorList(5);
}

void PrintExitMenu(){
	SeperatorList(4); cout << "Confirm Close "; SeperatorList(3); SeperatorList(4);
	cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM? (Y/N)\n";
}

void PrintUnderTenSubMenu(int membersOfR){
	SeperatorList(4); cout << "Source Number System: " << membersOfR << " "; 
	SeperatorList(2); SeperatorList(4); 
	cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n";
	cout << "(10) DECIMAL\n";
	cout << "INPUT ANY OTHER VALUE TO QUIT THE PROGRAM.\n"; SeperatorList(7); cout << endl;
}

void PrintTenSubMenu(){
	SeperatorList(4); cout << "Source Number System: 10 ";
	SeperatorList(2); SeperatorList(4); 
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
	cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n"; SeperatorList(7);
}

void PrintHexSubMenu(){
	SeperatorList(4); cout << "Source Number System: 16 ";
	SeperatorList(2); SeperatorList(4); 
	cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n";
	cout << "(8) OCTAL\n";
	cout << "(10) DECIMAL\n";
	cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n"; SeperatorList(7);
}

SourceToDecimal(){}

// DecimalToSource(){}

// DecimalToHex(){}

// HexToOctal(){}

// HexToDecimal(){}

#endif
