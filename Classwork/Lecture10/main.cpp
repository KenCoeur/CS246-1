#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Queue.h"

int main()
{
	srand(time(NULL));
	std::string letters = "abcdefghijklmnopqrstuvwxyz";

	ds::da::Queue<char> S;
	ds::sn::Queue<char> T;

	for(int i = 0;i < 26;i += 1)
	{
		S.Enqueue(letters[i]);
		T.Enqueue(letters[i]);
	}

	std::cout << "alphabet: " << letters << "\n"; 
	std::cout << "alphabet in reverse generated by S: ";

	while(!S.IsEmpty())
	{
		std::cout << S.Peek();
		S.Dequeue();
	}

	std::cout << "\n";  

	std::cout << "alphabet in reverse generated by T: ";

	while(!T.IsEmpty())
	{
		std::cout << T.Peek();
		T.Dequeue();
	}

	std::cout << "\n";  

	return 0;
}
