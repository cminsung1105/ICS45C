#include <iostream>
#include "String.h"

using namespace std;

//VARIABLES
int String :: allocations = 0;

//CONSTRUCTORS

String :: String(const char * s){
    buf = strdup(s);
}

String :: String(const String & s){
    buf = strdup(s.buf);
}

//PRIVATE METHODS

int String :: strlen(const char * s){
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
	++counter;
    return counter;
}

char * String :: strcpy(char * dest, const char * src){
    int i;
    for (i = 0; src[i] != '\0'; i++)
	dest[i] = src[i];

    dest[i] = '\0';
    return dest;
}	

char * String :: strdup(const char * s){
    return strcpy(new_char_array(strlen(s)+1), s);
}

int String :: strcmp(const char * left, const char * right){
    for (int i = 0; left[i] != '\0'; i++){
	if (left[i] - right[i] != 0)
	    return left[i] - right[i];
    }
    return 0;
}

int String :: strncmp(const char * left, const char * right, int n){
    int i;
    for (i = 0; i < n; i++){
	if (left[i] - right[i] != 0)
	    return left[i] - right[i];
    }
    return 0;
}

char * String :: strchr(char * str, int c){
    for (int i = 0; str[i] != '\0'; i++){
	if (str[i] == c)
	    return str + i;
    }
}

char * String :: strstr(char * haystack, char * needle){
    int len = strlen(needle);
    char * s = haystack;
    char * p;
    while (* s != '\0'){
	p = strchr(s, needle[0]);
	if (p == nullptr)
	    return nullptr;
	if (strncmp(p, needle, len) == 0)
	    return p;
	else
	    s = p + 1;
    }
}

const char * String::strstr(const char *haystack, const char *needle){
    return const_cast<const char *>(strstr(const_cast<char *>(haystack),const_cast<char *>(needle)));
}

void String :: reverse_cpy(char * dest, const char * src){
    int len = strlen(src);
    for (int i = len-1; i >= 0; --i)
	dest[len-i-1] = src[i];
    dest[len] = '\0';
}

char * String :: strcat(char * dest, const char * src){
    int len = strlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++){
        dest[i+len] = src[i];
    }
    dest[i+len] = '\0';
    return dest;
}

char * String :: addArrays(char * dest, const char * src){
    char * temp;
    int src_len = strlen(src);
    int dest_len = strlen(dest);
    temp = new_char_array(src_len + dest_len-1);
    strcpy(temp, dest);
    int i;
    for (i = 0; src[i] != '\0'; i++)
        temp[i+dest_len] = src[i];
    temp[i+dest_len] = '\0';
    return temp;
}

char * String :: new_char_array(int n_bytes){
    ++allocations;
    return new char[n_bytes+1];
}

void String :: delete_char_array(char * p){
    --allocations;
    if (allocations < 0)
	cerr <<"Error (class String): more delete[] than new[]"<< endl;
    delete[] p;
}

//PUBLIC METHODS
String & String :: operator = (const String & s){
    delete_char_array(buf);
    buf = strdup(s.buf);
    return *this;
}

char & String :: operator [] (int index){
    if (inBounds(index))
	return buf[index];
    else
	cerr << "INDEX OUT OF BOUNDS" << endl;
	return buf[0];
}

int String :: size(){
    return strlen(buf);
}

int String :: indexOf(const char c){
    const char * found = strchr(buf, c);
    if (found == nullptr)
	return -1;
    else
	return found - buf;
}

int String :: indexOf(const String pattern){
    const char * found = strstr(buf, pattern.buf);
    if (found == nullptr){
	return -1;
    }
    else
	return found - buf;
}

bool String :: operator == (const String s){
    return strcmp(buf, s.buf) == 0;
}

bool String :: operator != (const String s){
    return strcmp(buf, s.buf) != 0;
}

bool String :: operator > (const String s){
    return strcmp(buf, s.buf) > 0;
}

bool String :: operator < (const String s){
    return strcmp(buf, s.buf) < 0;
}

bool String :: operator <= (const String s){
    return strcmp(buf, s.buf) <= 0;
}

bool String :: operator >= (const String s){
    return strcmp(buf, s.buf) >= 0;
}

String String :: reverse(){
    int len = strlen(buf);
    char * temp = new_char_array(len+1);
    String rev(temp);
    reverse_cpy(rev.buf, buf);
    delete_char_array(temp);
    return rev;
}

String String :: operator + (const String s){
    char * temp = addArrays(buf, s.buf);
    String added(temp);
    delete_char_array(temp);
    return added;
}

String String :: operator += (const String s){
    *this = *this + s;
    return *this;
}

void String :: final_report_on_allocations(){
    cout << "alloacations: " << allocations << endl;
    if (allocations > 0)
	cerr << "Memory Leak in class String" << endl;
    if (allocations < 0)
	cerr << "Too many delete[] in class String" << endl;
    if (allocations == 0)
	cout << "Allocations match deallocations" << endl;
}

void String :: print(ostream & out){
    out << buf;
}

void String :: read(istream & in){
    char a[256];
    in.getline(a, 256);
    delete_char_array(buf);
    buf = strdup(a);
}

//DESTRUCTOR
String :: ~String(){
    delete_char_array(buf);
}

//CONSOLE
ostream & operator << (ostream & out, String str){
    str.print(out);
    return out;
}

istream & operator >> (istream & in, String & str){
    str.read(in);
    return in;
}
