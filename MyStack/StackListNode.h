#ifndef SLISTNODE_H
#define  SLISTNODE_H

template<typename Nodetype> 
class MyStack;

template<typename Nodetype>
class SListNode
{
	friend class MyStack< Nodetype > ;
public:
	SListNode(const Nodetype &);
	Nodetype getData() const;

private:
	Nodetype data;
	SListNode<Nodetype> *nxtPtr;


};

template<typename Nodetype>
SListNode<Nodetype>::SListNode(const Nodetype &x) : data(x), nxtPtr(0)
{

}

template<typename Nodetype>
Nodetype SListNode<Nodetype>::getData() const
{
	return data;
}

#endif