#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

vector<int> read_file(){
    ifstream inFile("rand_numbers.txt");
    vector<int> nums;
    copy(istream_iterator<int>(inFile), istream_iterator<int>(), 
	back_inserter(nums));
    sort(begin(nums), end(nums));
    inFile.close();
    return nums;
}

void store_odd(vector<int> nums){
    ofstream outFile("odd.txt");
    for_each(begin(nums), end(nums), 
	[&](int n){
	    if (n % 2 == 1){
		outFile << n << " ";
	    }
	}
    );
    outFile.close();
}

void store_even(vector<int> nums){
    ofstream outFile("even.txt");
    for_each(begin(nums), end(nums), 
	[&](int n){
	    if (n % 2 == 0){
		outFile << n << "\n";
	    }
	}
    );
    outFile.close();
}

int main(){
    vector<int> nums = read_file();
    store_odd(nums);
    store_even(nums);
    return 0;
}
