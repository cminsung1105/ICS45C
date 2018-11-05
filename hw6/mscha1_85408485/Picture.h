#include "Shape.h"
#include <iostream>

using namespace std;

class Picture {
    private:
    	struct ListNode{
	    Shape * info;
	    ListNode * next;
	    ListNode(Shape * newInfo, ListNode * newNext = nullptr)
	        : info(newInfo), next(newNext)
	    {
	    }	
	    
	};
	ListNode * head;

    public:
	Picture()
	    :head(nullptr)
	{
	}

	void add(Shape * sp){
	    head = new ListNode(sp, head);
	}

	void drawAll(){
	    for (ListNode * p = head; p != nullptr; p = p->next)
		p->info->draw();  
	}

	double totalArea(){
	    double total = 0;
	    for (ListNode * p = head; p != nullptr; p = p->next)
		total += p->info->area();
	    return total;
	}

	~Picture(){
	    ListNode * temp;
	    while (head){
		temp = head;
		delete temp;
		head = head->next;
	    }    
	}
	
};
