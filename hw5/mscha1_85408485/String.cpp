#include <iostream>
#include "String.h"

using namespace std;

//CONSTRUCTORS
String::String(const char * s) {
    head = ListNode::stringToList(s);
}

String::String(const String & s){
    head = String::ListNode::copy(s.head);
}

//STATIC METHODS

String::ListNode * String::ListNode::find(char c, ListNode * L){
    return !L || L->info == c ? L : find(c, L->next);
}

String::ListNode * String::ListNode::reverse(ListNode * L) {
    ListNode * result = nullptr;
    for (ListNode * p = L; p != nullptr; p = p->next) 
	result = new ListNode(p->info, result);
    return result;
}

String::ListNode * String::ListNode::stringToList(const char * s) {
    return !*s ? 0 : new ListNode(*s, stringToList(s + 1));
}

void String::ListNode::deleteList(ListNode * L){
    if (L != nullptr){
	deleteList(L->next);
        delete L;
    }
} 

int String::ListNode::compare(ListNode * L1, ListNode * L2){
    if (L1 == nullptr && L2 == nullptr)
	return 0;
    else if (L1 == nullptr)
	return -L2-> info;
    else if (L2 == nullptr)
	return L1 -> info;
    else if (L1->info == L2->info)
	return compare (L1->next, L2->next);
    else
	return L1->info - L2->info;
}

String::ListNode * String::ListNode::copy(ListNode * L){
    return !L ? nullptr : new ListNode(L->info, copy(L->next));
}

String::ListNode * String::ListNode::append(ListNode * L1, ListNode * L2){
    return !L1 ? copy(L2) : new ListNode(L1->info, append(L1->next, L2));
}

int String::ListNode::length(ListNode * L){
    return !L ? 0 : 1 + length(L->next);
}

//PUBLIC METHODS
String String::operator = (const String & s){
    head = String::ListNode::copy(s.head);
    return *this;
}

char & String::operator [] (const int index){
    String::ListNode * temp = head;    
    if (inBounds(index)){
        for (int i = 0; i < index; i++){
    	    temp = temp->next;
        }
        return temp->info;
    }
    else 
	cerr << "INDEX OUT OF BOUNDS" << endl;
   	return temp->info;
}

int String::indexOf(char c){
    int count = 0;
    for (String::ListNode * p = head; p != nullptr; p = p->next){
	if (p->info == c)
	    return count;
	++count;
    }
    return -1;
}

int String::size(){
    return ListNode::length(head);
}

void String::print(ostream & out) {
    for (String::ListNode * p = head; p != nullptr; p = p->next)
	out << p->info;
}

void String::read(istream & in){
    char a[256];
    in.getline(a, 256);
    head = String::ListNode::stringToList(a);
}


bool String::operator == (const String & s){
    return ListNode::compare(head, s.head) == 0; 
}

bool String::operator < (const String & s){
    return ListNode::compare(head, s.head) < 0;     
}

String String::operator + (const String & s){
    String temp;
    temp.head = String::ListNode::append(head, s.head);
    return temp;
}

String String::operator += (const String & s){
    head = String::ListNode::append(head, s.head);
    return *this;
}

String String::reverse(){
    String rev;
    rev.head = String::ListNode::reverse(head);
    return rev;
}

String::~String(){
    String::ListNode::deleteList(head);
}

ostream & operator << (ostream & out, String str) {
    str.print(out);
    return out;
}

istream & operator >> (istream & in, String & str){
    str.read(in);
    return in;
}
