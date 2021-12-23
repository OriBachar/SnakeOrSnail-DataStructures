#pragma once
#include<iostream>
#include <ctime>
using namespace std;

class Node
{
	int key; 
	Node* next; //the next Node in the list

public: 
	Node(int key);
	int GetKey() const;
	Node* GetNext() const;
	void SetKey(int key);
	void SetNext(Node* next);

};

