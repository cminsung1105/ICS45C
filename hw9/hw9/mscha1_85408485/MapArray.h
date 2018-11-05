#include <map>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

template
    <typename Key, typename Info>

class MapArray
{
  private:
    int length;
    pair<Key, Info> * buf; 

  public:
    MapArray()
        : length(0), buf(nullptr)
    {
    };

    Info& operator [] (const Key & k)
    {
	int i = find(k);
	if (i != -1)
	{
	    return buf[i].second;
	}	
	else
	{
	    length++;
	    pair<Key, Info> * temp = buf;
	    buf = new pair<Key, Info>[length];
 	    pair<Key, Info> new_pair = make_pair(k, 0);
	    int j;
	    for (j = 0; j < length-1; j++)
	    {
		if (temp[j].first < new_pair.first)
		{
		    buf[j] = temp[j];
		}
		else
		    break;
	    }
 	    buf[j] = new_pair;
	    int n = j;
	    for (n = n+1; n < length; n++)
		buf[n] = temp[n-1];
	    delete[] temp;
	    return buf[j].second;
	}
    }

    int find (const Key & k)
    {
	for (int i = 0; i < length; i++)
	{
	    if (buf[i].first == k)
	    {
		return i;
	    }
	}
	return -1;
    }

    struct iterator
    {
	typedef random_access_iterator_tag iterator_category;
	typedef iterator self_type;
	typedef pair<Key, Info> value_type;
	typedef pair<Key, Info>& reference;
	typedef pair<Key, Info>* pointer;

      private:
	pointer ibuf;

      public:
	iterator(pointer ptr): ibuf(ptr){};
	self_type operator++ () {++ibuf; return *this;};
	self_type operator++ (int postfix){self_type copy = *this; ibuf++; 
	    return copy;}
	self_type operator-- () {--ibuf; return *this;}
	self_type operator-- (int postfix) {self_type copy = *this; ibuf--;
	    return copy;}
	self_type operator - (int right) {ibuf -= right; return *this;}
	self_type operator + (int right) {ibuf += right; return *this;}
	bool operator < (const self_type & rhs)const 
	    {return ibuf < rhs.ibuf;}
	reference operator * (){return *ibuf;}
	pointer operator -> () {return ibuf;}
	bool operator == (const self_type & rhs) const 
	    {return ibuf == rhs.ibuf;}
	bool operator != (const self_type & rhs) const
	    {return ibuf != rhs.ibuf;}
    };

    iterator begin()
    {
	return iterator(buf);
    }

    iterator end()
    {
	return iterator(buf + length);
    }	

    ~MapArray()
    {
	if(buf)
	    delete[] buf;
    }

};

