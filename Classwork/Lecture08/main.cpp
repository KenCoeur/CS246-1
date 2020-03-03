#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "LinkedList.h"

int main()
{
	srand(time(NULL));
	ds::sn::LinkedList<int> list;
	int idx, value, i;

	//Insert Testing
	std::cout << "Inserting into a list\n\n";

	for(i = 1;i <= 5;i += 1)
	{
		if(rand() % 2 == 1)
		{
			list.InsertFirst(rand() % 100 + 1);
		}
		else
		{
			list.InsertLast(rand() % 100 + 1);
		}
		std::cout << "Insert " << i << "\n";
		std::cout << "list: " << list << "\n";
		std::cout << "first: " << list.First() << "\n";
		std::cout << "last: " << list.Last() << "\n\n"; 
	}

	std::cout << "Enter a value to add to the list: ";
	std::cin >> value;
	std::cout << "Enter the position to add " << value << " to the list: ";
	std::cin >> idx;

	if(list.InsertAt(idx,value))
	{
		std::cout << "\nInsert " << i << "\n";
		std::cout << "list: " << list << "\n";
		std::cout << "first: " << list.First() << "\n";
		std::cout << "last: " << list.Last() << "\n\n"; 
	}
	else
	{
		std::cout << "\nThe index was invalid\n\n";
	}
	
	//Search Testing
	std::cout << "Searching a list\n\n";

	i = 1;
	while(i <= 2)
	{
		std::cout << list << "\n\n";
		std::cout << "Enter a value from the list above: ";
		std::cin >> value;
		idx = list.IndexOf(value);

		if(idx != -1)
		{
			std::cout << "The index of " << value << " is " << idx << "\n\n";
			i += 1;
		}
		else
		{
			std::cout << "Are you blind?! Try again.\n\n";
		}
	} 

	//Access Testing
	std::cout << "Accessing a list\n\n";

	while(true)
	{
		std::cout << list << "\n\n";
		std::cout << "Enter the index of value of the list above that you want to modify: ";
		std::cin >> idx;

		if(idx >= 0 && idx < list.Size())
		{
			std::cout << "Enter the new value of the element: ";
			std::cin >> value;
			list[idx] = value;
			std::cout << "new list: " << list << "\n\n";
			break;
		}
		else
		{
			std::cout << "There are " << list.Size() << " elements in the list.\nLearn to count. Try again\n\n";
		}
	} 

	//Remove Testing
	std::cout << "Removing from a list\n\n";

	ds::sn::LinkedList<int> clist = list;

	i = 1;
	while(!clist.IsEmpty())
	{
		if(rand() % 2 == 1)
		{
			clist.RemoveFirst();
		}
		else
		{
			clist.RemoveLast();
		}
		std::cout << "Remove " << i << "\n";
		std::cout << "list: " << clist << "\n";
		if(!clist.IsEmpty())
		{
			std::cout << "first: " << clist.First() << "\n";
			std::cout << "last: " << clist.Last() << "\n\n";
		}
		i += 1; 
	}

	std::cout << "\n\n" << list << "\n\n";

	std::cout << "Enter a value to remove from the list: ";
	std::cin >> value;
	
	if(list.Contains(value))
	{
		list.Remove(value);
		std::cout << "\nRemove " << i << "\n";
		std::cout << "list: " << list << "\n";
		std::cout << "first: " << list.First() << "\n";
		std::cout << "last: " << list.Last() << "\n\n"; 
	}
	else
	{
		std::cout << "\nThe value was invalid\n\n";
	}

	return 0;
}
