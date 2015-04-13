#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "StackListNode.h"

using namespace std;

template<typename Nodetype>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void push(const Nodetype);
	bool pop(Nodetype &);
	void peek() const;
	bool isFull() const;
	bool isEmpty() const;
	void setMax(const Nodetype &);
private:
	SListNode<Nodetype> *firstPtr;
	SListNode<Nodetype> *lastPtr;

	SListNode<Nodetype> *getNewNode( const Nodetype) ;
	Nodetype varCount = 0;
	Nodetype varMax;
};

template < typename Nodetype >
MyStack<Nodetype>::MyStack( ) :firstPtr(0), lastPtr(0)
{

}


template<typename Nodetype>
MyStack<Nodetype>::~MyStack()//destructor
{
	if (!(isEmpty()))
	{
		while (!(firstPtr==lastPtr))
		{
			SListNode<Nodetype> *tmpPtr = firstPtr;
			firstPtr = (*firstPtr).nxtPtr;
			delete tmpPtr;
		}

		if (firstPtr == lastPtr)
		{
			firstPtr = 0;
			lastPtr = 0;
		}

		cout << "Stack is completly removed form memory space ...";
	}
	else
	{
		cout << "The Stack was never created ...";
	}
}

template < typename Nodetype >
void MyStack<Nodetype>::setMax(const Nodetype &info)
{
	varMax = info;
}
template<typename Nodetype>
void MyStack<Nodetype>::push(const Nodetype value)
{
	SListNode<Nodetype> *newPtr = getNewNode(value);

		if (!(isFull()))

		{
			if (isEmpty())
			{
				firstPtr = lastPtr = newPtr;

			}
			else
			{
				lastPtr->nxtPtr = newPtr;
				lastPtr = lastPtr->nxtPtr;
				//lastPtr->data = value;
				//cout << "Data was pushed on the Stack";
				
			}
			++varCount;
			
		}
		else
		{
			cout << "The Stack is full ... try popping";
		}

}
template<typename Nodetype>
bool MyStack<Nodetype>::pop( Nodetype &value)
{
	if (!(isEmpty()))
	{
		if (firstPtr == lastPtr)
		{
			firstPtr = lastPtr = 0;
			--varCount;
		}
		else
		{
			SListNode<Nodetype> *currentPtr = firstPtr;
			while (!(currentPtr->nxtPtr == lastPtr))
			{
				currentPtr = currentPtr->nxtPtr;
			}

			SListNode<Nodetype> *tempPtr = lastPtr;
			lastPtr = currentPtr;
			currentPtr->nxtPtr = 0;
			value = tempPtr->data;
			delete tempPtr;

			cout << "Data was popped off the Stack";
			
			--varCount;
		}

		return true;
	}
	else
	{
		//cout << "The Stack is Empty ...";
		return false;
	}

	
}

template<typename Nodetype>
bool MyStack<Nodetype>::isFull() const
{
	return ((varCount+1) > varMax);

}

template<typename Nodetype>
bool MyStack<Nodetype>::isEmpty() const
{
	return (firstPtr == 0);
}

template<typename Nodetype>
SListNode<Nodetype> *MyStack<Nodetype>::getNewNode(const Nodetype value)
{
	return new SListNode<Nodetype>(value);
}

template<typename Nodetype>
void MyStack<Nodetype>::peek() const
{
	if (isEmpty())
	{
		cout << "The Stack is empty \n\n";
		return;
	}
	SListNode<Nodetype> *currentPtr = firstPtr;
	cout << "The Stack is : ";
	while (currentPtr != 0)
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nxtPtr;
	}
	if (isFull())
	{
		cout << "\n\nThe Stack is full dear, pop some data out..\n\n";
	}

}

#endif
