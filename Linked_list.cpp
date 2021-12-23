/*Ori Bachar 208254516
Bar Shaya 318469772*/
#include "Linked_list.h"

Linked_list::Linked_list()
{
	this->SetHead(NULL);
	this->SetTail(NULL);
}

Node* Linked_list::GetHead() const
{
	return this->head;
}

Node* Linked_list::GetTail() const
{
	return this->tail;
}

void Linked_list::SetHead(Node* n)
{
	this->head = n;
}

void Linked_list::SetTail(Node* n)
{
	this->tail = n;
}

//add a Node to the Linked List
void Linked_list::addNode(int key)
{
	Node* temp = new Node(key); //create a new node

	if (this->head == NULL) //if the linked list is empty
	{
		this->head = temp;

		this->tail = temp;
	}
	else
	{
		this->tail->SetNext(temp);

		this->tail = temp;
	}
}

//checking if the Linked List is a snake(return NULL) or snail(return the first Node in the circle) 
Node* Linked_list::SnakeOrSnail()
{
	Node* p1, * p2;
	int count = 1;
	if (this == NULL || this->GetHead()->GetNext() == NULL || this->GetHead()->GetNext()->GetNext() == NULL) //if the pointer is NULL - snake 
		return NULL;
	p1 = this->GetHead()->GetNext();
	p2 = this->GetHead()->GetNext()->GetNext();
	while (p2 != NULL && p1 != p2)//	//if p1 and p2 points to the same Node - snail
	{
		if (p2->GetNext() == NULL || p2->GetNext()->GetNext() == NULL) //if the pointer is NULL - snake 
			return NULL;
		p1 = p1->GetNext();
		p2 = p2->GetNext()->GetNext();
	}

	if (p2 == NULL) //if the pointer is NULL - snake 
		return NULL;


	while (p2->GetNext() != p1)  //counting the circle's length 
	{
		p2 = p2->GetNext();
		count++;
	}
	//set the pointers to the head of the list 
	p1 = this->GetHead();
	p2 = this->GetHead();
	//p2 is in the place of the length Node in the linked list
	for (int i = 0; i < count; i++)
	{
		p2 = p2->GetNext();
	}
	while (p1->GetNext() != p2->GetNext()) //find the first Node in the snail's circle
	{
		p1 = p1->GetNext();
		p2 = p2->GetNext();
	}
	return p2->GetNext();
}

//build snake by linked list of nodes
Linked_list& Linked_list::BuildSnake()
{
	srand(time(NULL));
	Linked_list snake;
	int s = rand() % (100 - 1 + 1) + 1; // null (0.01)
	while (s != 100)
	{
		int key = rand() % (20 - 1 + 1) + 1; //random key between 1-20
		snake.addNode(key);
		s = rand() % (100 - 1 + 1) + 1;
	}
	int key = rand() % (20 - 1 + 1) + 1; //random key between 1-20
	snake.addNode(key);
	return snake;
}

//build snail by linked list of nodes
Linked_list& Linked_list::BuildSnail()
{
	srand(time(NULL));
	Linked_list snail;
	int key;
	int s = rand() % (66 - 1 + 1) + 1; // null (0.015)
	while (s != 66)
	{
		key = rand() % (20 - 1 + 1) + 1; //random key between 1-20
		snail.addNode(key);
		s = rand() % (100 - 1 + 1) + 1;
	}
	key = rand() % (20 - 1 + 1) + 1; //random key between 1-20
	snail.addNode(key);
	Node* temp = snail.GetTail();
	cout << "(Linked_list)Head circle node address: " << snail.GetTail() << endl; //print the Head circle node address
	s = rand() % (50 - 1 + 1) + 1; // null (0.02)
	while (s != 50)
	{
		key = rand() % (20 - 1 + 1) + 1; //random key between 1-20
		snail.addNode(key);
		s = rand() % (100 - 1 + 1) + 1;
	}
	key = rand() % (20 - 1 + 1) + 1; //random key between 1-20
	snail.addNode(key);
	snail.GetTail()->SetNext(temp);
	return snail;
}


void Linked_list::printSnake()
{
	Node* temp = this->GetHead();
	int count = 0;
	while (temp != NULL)
	{
		count++;
		cout << temp->GetKey() << " -> ";
		temp = temp->GetNext();
	}
	cout << "NULL" << endl;
	cout << "the size of the snake is : " << count << endl;
}


void Linked_list::printSnail()
{
	Node* p1 = this->GetHead();
	Node* p2 = this->SnakeOrSnail();
	int count = 0, countloop = 0;
	while (p1 != p2) //print the snail until the circle
	{
		count++;
		cout << p1->GetKey() << " -> ";
		p1 = p1->GetNext();
	}
	cout << "|> " << p1->GetKey() << " -> "; //the first Node in the circle 
	count++;
	countloop++;
	p2 = p2->GetNext();
	while (p1 != p2->GetNext())
	{
		count++;
		countloop++; //count the length of the circle
		cout << p2->GetKey() << " -> ";
		p2 = p2->GetNext();
	}
	cout << p2->GetKey() << " <| " << endl; //the last Node in the circle 
	count++;
	countloop++;
	cout << "the size of the snail is: " << count << endl;
	cout << "the size of the circle is: " << countloop << endl;

}
