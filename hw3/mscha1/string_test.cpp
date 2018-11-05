#include "String.h"
#include <iostream>

using namespace std;

void test_constructors_and_print(){
    cout << "-----TESTING CONSTRUCTORS AND PRINT------" << endl;
    String i("Hello World");
    cout << i << endl;

    String n();
    cout << n << endl;

    String first("First");
    String f(first);
    cout << f << endl;
}

String test_read(){
    cout << "-----TESTING READ-----" << endl;
    String s;
    cin >> s;
    return s;
}

void test_index_operator(){
    cout << "-----TESTING INDEX OPERATOR-----" << endl;
    String h("Hello World");
    cout << "l: " << h[2] << endl;
    cout << "d: " << h[10] << endl;
}

void test_assignment(){
    cout << "-----TESTING ASSSIGNMENT-----" << endl;
    String h("Hello World");
    String b("Bye World");
    h = b;
    cout << "Bye World: " << h << endl;	

    String you("You");
    String me ("Me");
    me = you;
    cout << "You: " << me << endl;
}

void test_size(){
    cout << "-----TESTING SIZE-----" << endl;
    String h("Hello World");
    cout << "11: " <<  h.size() << endl;

    String ICS("ICS 45C");
    cout << "7: " << ICS.size() << endl;
}

void test_indexOf(){
    cout << "-----TESTING INDEXOF----" << endl;
    String h("Hello World");
    cout << "2: " << h.indexOf('l') << endl;
    cout << "-1: " << h.indexOf('z') << endl;

    String haystack("The quick brown fox ran up the lazy log");
    String needle("ran");
    String quack("quack");
    cout << "20: " << haystack.indexOf(needle) << endl;
    cout << "-1: " << haystack.indexOf(quack) << endl;
}


void test_boolean(){
    cout << "-----TESTING BOOLEAN-----" << endl;
    String h1("Hello World");
    String h2("Hello World");
    String h3("Bye World");
    String a1("b");
    String a2("a");

    cout << "EQUALITY:" << endl;
    if ((h1 == h2) == 1)
	cout << "CORRECT" << endl;
    if ((h1 == h3) == 0)
	cout << "CORRECT" << endl;

    cout << "INEQUALITY:" << endl;
    if ((h1 != h2) == 0)
	cout << "CORRECT" << endl;
    if ((h1 != h3) == 1)
	cout << "CORRECT" << endl;

    cout << "GREATER THAN:" << endl;
    if ((a1 > a2) == 1)
	cout << "CORRECT" << endl;
    if ((a2 > a1) == 0)
	cout << "CORRECT" << endl;

    cout << "LESS THAN:" << endl;
    if ((a2 < a1) == 1)
	cout << "CORRECT" << endl;
    if ((a1 < a2) == 0)
	cout << "CORRECT" << endl;

    cout << "GREATER THAN OR EQUAL:" << endl;
    if ((h1 >= h2) == 1)
	cout << "CORRECT" << endl;
    if ((a1 >= a2) == 1)
	cout << "CORRECT " << endl;
    if ((a2 >= a1) == 0)
	cout << "CORRECT" << endl;

    cout << "LESS THAN OR EQUAL:" << endl;
    if ((h1 <= h2) == 1)
	cout << "CORRECT" << endl;
    if ((a2 <= a1) == 1)
	cout << "CORRECT" << endl;
    if ((a1 <= a2) == 0)
	cout << "CORRECT" << endl; 
}

void test_reverse(){
    cout << "-----TESTING REVERSE----" << endl;
    String s1("Hello");
    String s2("TOMATO IS LOVE");
    cout << "olleH: " << s1.reverse() << endl;
    cout << "EVOL SI OTAMOT: " <<s2.reverse() << endl;
}

void test_concatenation(){
    cout << "-----TESTING CONCATENATION-----" << endl;
    String s1("HELLO ");
    String s2("WORLD ");
    String s3("BYE ");
    cout << "HELLO WORLD: " << s1 + s2 << endl;
    s3 += s2;
    cout << "BYE WORLD: " << s3 << endl;

}	

int main(){
    test_constructors_and_print();
    test_index_operator();
    test_assignment();
    test_size();
    test_indexOf();
    test_reverse();
    test_boolean();
    test_concatenation();
    cout << test_read() << endl;
    return 0;

}

