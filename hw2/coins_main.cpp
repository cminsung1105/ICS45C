#include "Coins.h"

int dollars_to_cents(float dollar){
    return dollar * 100;
    }

float coins_to_dollars(Coins c){
    return c.get_quarters()*0.25 + c.get_dimes()*0.1 + 
	c.get_nickels()*0.05 + c.get_pennies()*0.01;
    }

int main(){
    Coins pocket(5, 3, 6, 8);
    Coins piggybank(50, 50, 50, 50);

    cout << "Pocket: " << pocket << endl;
    cout << "Piggybank: " << piggybank << endl;

    cout << "Bought bag of chips for 68 cents" << endl;
    pocket.extract_exact_change(coins_required_for_cents(68));
   
    cout << "Pocket: " << pocket << endl;

    cout << "Transferred 2.08 dollars from piggybank to pocket" << endl; 
    Coins cash = piggybank.extract_exact_change(coins_required_for_cents(
	dollars_to_cents(2.05)));
    pocket.deposit_coins(cash);

    cout << "Pocket: " << pocket << endl;
    cout << "Piggybank: " << piggybank << endl;

    cout << "Found loose change in sofa (10q, 10d, 10n, 10p)" << endl;
    Coins sofa(10, 10, 10, 10);

    cout << "Transferred to piggybank" << endl;
    piggybank.deposit_coins(sofa);

    cout << "Piggybank: " << "$" << coins_to_dollars(piggybank) << endl;

    return 0;
}
