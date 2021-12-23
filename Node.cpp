/*Ori Bachar 208254516
Bar Shaya 318469772*/
#include "Node.h"

Node::Node(int key)
{
	this->SetKey(key);
	this->SetNext(NULL);
}

int Node::GetKey() const
{
	return this->key;
}

Node* Node::GetNext() const
{
 	return this->next;
}

void Node::SetKey(int key)
{
	this->key = key;
}

void Node::SetNext(Node* next)
{
	this->next = next;
}

