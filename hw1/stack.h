#include <iostream>
using namespace std;

#define STACK_CAPACITY 1000

class Stack{
  private:
    int count;
    char stk[STACK_CAPACITY];
  
  public:
    Stack(){
      count = 0;
    } 

    void push (char c){
      if (isFull()){
	cerr << "push on a full stack";
      }
      else {
	stk[count] = c;
	++count;
      }
    }

    char pop(){
      if (isEmpty()){
	cerr << "pop on an empty stack";
      }
      return stk[--count];
    }

    char top(){
      if (isEmpty()){
	cerr << "top of an empty stack";
      }
      return stk[count-1];
    }

    bool isFull(){
      return count >= STACK_CAPACITY;
    }

    bool isEmpty(){
      return count <= 0;
    }

    ~Stack(){
    }
};
