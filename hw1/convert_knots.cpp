#include <iostream>
using namespace std;

double to_mpm( double knot ){
    return ((knot * 6076) / 5280) / 60;
}

int main(){
    double userknot;
    cin >> userknot;
    
    cout << to_mpm(userknot) << " miles per minute" << endl;
    return 0;
}
    
