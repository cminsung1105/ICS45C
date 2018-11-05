#include <iostream>

using namespace std;

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins{
    private:
        int quarters, dimes, nickels, pennies;

    public:
        Coins(int q, int d, int n, int p){
            quarters = q;
            dimes = d;
            nickels = n;
            pennies = p;
        }

        void deposit_coins( Coins & c ){
            quarters += c.quarters;
            dimes += c.dimes;
            nickels += c.nickels;
            pennies += c.pennies;
            
            c.quarters = 0;
            c.dimes = 0;
            c.nickels = 0;
            c.pennies = 0;
        }

        bool has_exact_change_for_coins( Coins c ){
            return quarters >= c.quarters && dimes >= c.dimes && 
            nickels >= c.nickels && pennies >= c.pennies;
        }

        Coins extract_exact_change( Coins c ){
            if (has_exact_change_for_coins(c)){
                quarters -= c.quarters;
                dimes -= c.dimes;
                nickels -= c.nickels;
                pennies -=c.pennies;
                
                return Coins(c.quarters, c.dimes, c.nickels, c.pennies);  
                
            } else {
                cerr << "NOT ENOUGH BALANCE" << endl;
                return Coins(0, 0, 0, 0);
            }
            
        }
        
        int total_value_in_cents(){
            return quarters*CENTS_PER_QUARTER + dimes*CENTS_PER_DIME + 
            nickels*CENTS_PER_NICKEL + pennies;
        }
        
        void print( ostream & out ){
            cout << quarters << " quarters, " << dimes << " dimes, " <<
	    nickels << " nickels, "  << pennies << " pennies.";
            return;
        }

	int get_quarters(){
	    return quarters;
	}

	int get_dimes(){
	    return dimes;
	}

	int get_nickels(){
	    return nickels;
	}

	int get_pennies(){
	    return pennies;
	}
};

ostream & operator << (ostream & out, Coins c){
    c.print( out );
    return out;
}

Coins coins_required_for_cents(int amount_in_cents){
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    while (amount_in_cents > 0){
        if (amount_in_cents >= 25){
            amount_in_cents -= 25;
            ++quarters;
            
        } else if (amount_in_cents >= 10){
            amount_in_cents -= 10;
            ++dimes;
            
        } else if (amount_in_cents >= 5){
            amount_in_cents -= 5;
            ++nickels;
        } else {
            amount_in_cents -= 1;
            ++pennies;
        }
        
    }
    
    return Coins(quarters, dimes, nickels, pennies);
}
