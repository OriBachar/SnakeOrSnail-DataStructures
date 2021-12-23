/*Ori Bachar 208254516
Bar Shaya 318469772*/
#pragma once
#include<iostream>
#include <ctime>
#include "Node.h"
using namespace std;

class Linked_list
{
private:
	Node* head;//the first Node in the Linked List
	Node* tail; //the last Node in the Linked List

public:
	Linked_list(); //constructor 
	Node* GetHead() const;
	Node* GetTail() const;
	void SetHead(Node * n);
	void SetTail(Node* n);
	void addNode(int key); //add a Node to the Linked List
	Node* SnakeOrSnail(); //checking if the Linked List is a snake(return NULL) or snail(return the first Node in the circle) 
	Linked_list& BuildSnake(); //build snack by linked list of nodes
	Linked_list& BuildSnail();//build snail by linked list of nodes
	void printSnake(); //print snake
	void printSnail(); //print snail
	
};

