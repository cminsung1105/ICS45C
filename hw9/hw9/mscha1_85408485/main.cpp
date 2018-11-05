#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include "SetList.h"
#include "MapArray.h"

using namespace std;

int main(){
    ifstream in("stopwords.txt");
    SetList<string> exclusion;
    for_each(istream_iterator<string>(in), istream_iterator<string>(),
	[&](string s)
	{
	    exclusion.insert(s);
	}
    ); 
    in.close();

    ifstream inFile("sample_doc.txt");
    MapArray <string, int> frequency;
    for_each(istream_iterator<string>(inFile), istream_iterator<string>(), 
	[&](string s){
	    string l(s);
	    transform(l.begin(), l.end(), l.begin(), ::tolower);
	    if (exclusion.count(l) == 0){
	        ++frequency[l];
	    }
        }
    );
    inFile.close();

    ofstream outFile("frequency.txt");
    for_each(begin(frequency), end(frequency), 
	[&](pair<string,int> m){
	    outFile << m.first << " " << m.second << "\n";
        }
    );
    outFile.close(); 

    return 0;
}
