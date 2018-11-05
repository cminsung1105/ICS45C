#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

template
    <typename T>
class SetList
{
  private:
    struct ListNode
    {
	T info;
	ListNode * next;
	ListNode(T newInfo, ListNode * newNext = nullptr)
	   : info(newInfo), next(newNext)
	{}
	
	static void deleteList(ListNode * L)
	{
	    if (L != nullptr)
	    {
	    	deleteList(L->next);
		delete L;
	    }
	}

    };

    ListNode * head;

  public:
    struct iterator
    {
	typedef std::forward_iterator_tag iterator_category;
	typedef iterator self_type;
	typedef T value_type;
	typedef T& reference;
	typedef ListNode* pointer;
	typedef ptrdiff_t difference_type;

      private:
	pointer buf;

      public:
	iterator(pointer ptr) : buf(ptr){}
	self_type operator ++ (){buf = buf->next; return *this;}	
	self_type operator ++ (int postfix){self_type copy = *this;
	    buf = buf->next; return copy;}
	reference operator * (){return buf->info;}
	pointer operator -> (){return buf;}
	bool operator == (const self_type & rhs) const 
	    {return buf == rhs.buf;} 
	bool operator != (const self_type & rhs) const 
	    {return buf != rhs.buf;}
    };
    
    SetList()
	: head(nullptr)
    {
    }    
    
    void insert(const T & t)
    {
	head = new ListNode(t, head);
    }

    void print()
    {
	for (ListNode * p = head; p != nullptr; p = p -> next)
	    cout << p->info;
	cout << endl;
    }

    int count(string s)
    {
	int count = 0;
	for (ListNode * p = head; p != nullptr; p = p->next){
	    if (p->info == s){
	   	++count;
	    } 
	}
	return count;
    }

    int size() const
    {
	return ListNode::length(head);
    }

    iterator begin()
    {
	return iterator(head);
    }

    iterator end()
    {
    	return iterator(nullptr);
    }

    ~SetList()
    {
	ListNode::deleteList(head);
    }

};

