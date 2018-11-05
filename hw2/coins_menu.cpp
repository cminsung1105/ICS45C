#include <iostream>
#include "Coins.h"

using namespace std;

void presentMenu(){
    cout<< "* * * * * * * * * * * * * * * * * * * * * * * * *\n"
      <<   "*		 COINS BANK MENU	  	*\n"
      <<   "*			 		   	*\n"
      <<   "* OPTION				ENTER	*\n"
      <<   "*						*\n"
      <<   "*   DEPOSIT CHANGE (in $)		D or d	*\n"
      <<   "*   EXTRACT CHANGE(in $)		E or e	*\n"
      <<   "*   PRINT BALANCE			B or b	*\n"
      <<   "*			 			*\n"
      <<   "*   Quit				Q or q	*\n"
      <<   "*						*\n"
      <<   "* * * * * * * * * * * * * * * * * * * * * * * * *\n";
}

char getInput(){
    cout << "Enter a command character: " << endl;
    char cmd;
    cin >> cmd;
    return cmd;
}

int dollars_to_cents(float dollars){
    return dollars * 100;
}

void evaluateCommand(Coins & myCoins, Coins & transaction, char cmd){
    switch(cmd){
	float amount;
	case 'D': case 'd':
	    cout << "DEPOSIT AMOUNT: ";
	    cin >> amount;
	    
	    transaction = coins_required_for_cents(dollars_to_cents(amount));
	    
	    myCoins.deposit_coins(transaction);

	    cout << "NEW BALANCE: " << myCoins << endl;
	      	
	    break; 

	case 'E': case 'e':
	    cout << "EXTRACTION AMOUNT: ";
	    cin >> amount;

	    transaction = coins_required_for_cents(dollars_to_cents(amount));

	    myCoins.extract_exact_change(transaction);

	    cout << "NEW BALANCE: " << myCoins << endl;	
	    break;	    

	case 'B': case 'b':
	    cout << "CURRENT BALANCE: " << myCoins << endl; 
	    break;

	case 'Q': case 'q':
	    cout << "Exiting from Coin Bank" << endl;
	    exit(0);
	    break;

	default:
	    cout << "Invalid command: " << cmd << endl;
	    break;
    } 
    return;
}

int main(){
    Coins myCoins(0, 0, 0, 0);
 
    while(true){
	Coins transaction(0, 0, 0, 0);
	presentMenu();
        char cmd = getInput();
	evaluateCommand(myCoins, transaction,  cmd);
    }

    return 0;
}
