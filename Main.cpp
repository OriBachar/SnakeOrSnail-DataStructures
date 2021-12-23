#include "Linked_list.h"

int main()
{
	srand(time(NULL));
	Linked_list s;
	int r = rand() % (2 - 1 + 1) + 1; // 1-snake 2-snail (0.5:0.5)
	if (r == 1)
	{
		cout << "snake" << endl;
		s = s.BuildSnake();
	}
	else
	{
		cout << "snail" << endl;
		s = s.BuildSnail();
	}

	if (s.SnakeOrSnail() == NULL) //check if the Linked List is a snake 
		s.printSnake();
	else //the Linked List is a snail 
	{
		cout << "(Main)Head circle node address: "<< s.GetTail()->GetNext() << endl; //print the Head circle node address
		s.printSnail();
	}
}
