#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    string str;
    Stack S;
    cout << "Enter a string: " << endl;

    while (getline(cin, str)){
    	
	for (int i = 0; i < str.size(); ++i){
	  S.push(str[i]);
	  
	}
	cout << "Reversed:" << endl;
	while (!S.isEmpty()){
	    cout << S.pop();
	}
	cout << endl;
    }    

    return 0;
}



