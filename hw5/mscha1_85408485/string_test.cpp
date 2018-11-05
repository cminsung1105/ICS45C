#include <iostream>
#include "String.h"

using namespace std;

void test_constructors_and_print(){
    cout << "-----TESTING CONSTRUCTORS AND PRINT------" << endl;
    String i("Hello World");
    cout << i << endl;

    String first("First");
    String f(first);
    cout << f << endl;
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
    String uci("University of California, Irvine");
    cout << "11: " << h.size() << endl;
    cout << "32: " << uci.size() << endl;
}

void test_equality(){
    String h1("Hello World");
    String h2("Hello World");
    String h3("Bye World");
    cout << "-----TESTING EQUALITY-----" << endl;
    cout << "1: " << (h1 == h2) << endl;
    cout << "0: " << (h1 == h3) << endl;
}

void test_less_than(){
    String h1("Hello World");
    String h2("Hello World");
    String h3("Bye World");
    String a1("b");
    String a2("a");
    cout << "-----TESTING LESS THAN-----" << endl;
    cout << "1: " << (a2 < a1) << endl;
    cout << "1: " << (h3 < h2) << endl;
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

void test_reverse(){
    cout << "-----TESTING REVERSE----" << endl;
    String s1("Hello");
    String s2("TOMATO IS LOVE");
    cout << "olleH: " << s1.reverse() << endl;
    cout << "EVOL SI OTAMOT: " <<s2.reverse() << endl;
}

void test_index_operator(){
    cout << "-----TESTING INDEX OPERATOR-----" << endl;
    String h("Hello World");
    cout << "l: " << h[2] << endl;
    cout << "d: " << h[10] << endl;
    cout << "ERROR: " << h[15] << endl;
}

void test_indexOf(){
    cout << "-----TESTING INDEXOF----" << endl;
    String h("Hello World");
    cout << "2: " << h.indexOf('l') << endl;
    cout << "-1: " << h.indexOf('z') << endl;
}

void test_read(){
    cout << "-----TESTING READ-----" << endl;
    String s;
    cin >> s;
    cout << s << endl;
}

int main(){
    test_constructors_and_print();
    test_assignment();
    test_size();
    test_equality();
    test_less_than();
    test_concatenation();
    test_reverse();
    test_index_operator();
    test_indexOf();
    test_read();
    return 0;
}
