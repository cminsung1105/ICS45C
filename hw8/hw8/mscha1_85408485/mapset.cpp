#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

set<string> read_stopwords(){
    ifstream in("stopwords.txt");
    set <string> exclusion;
    copy(istream_iterator<string>(in), istream_iterator<string>(), 
	inserter(exclusion, begin(exclusion)));
    in.close();
    return exclusion;
}

map<string, int> store_map(set<string> exclusion){
    ifstream inFile("sample_doc.txt");
    map <string, int> frequency;
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
    return frequency;
} 

void write_frequency(map<string, int> f){
    ofstream outFile("frequency.txt");
    for_each(begin(f), end(f), 
	[&](pair<string,int> m){
	    outFile << m.first << " " << m.second << "\n";
        }
    );
    outFile.close();
}

int main(){
    set<string> exclusion = read_stopwords();
    map<string, int> m = store_map(exclusion);
    write_frequency(m);
    return 0;
}


