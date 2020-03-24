#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"


template <class T>
void Add(ds::dn::Node<T>*& link,const T& value)
{
	if(link == NULL)
	{
		link = new ds::dn::Node<T>(value);
	}
	else
	{
		ds::dn::Node<T>* node = new ds::dn::Node<T>(value);
		node->SetNext(link);
		node->SetPrev(link->GetPrev());

		if(node->GetPrev() != NULL)
			node->GetPrev()->SetNext(node);

		node->GetNext()->SetPrev(node);
	}
}

ds::dn::Node<int>* GenerateList(int n)
{
    int nc = (n <= 0)?(10):(n);
    ds::dn::Node<int>* root = new ds::dn::Node<int>(rand() % 99 + 1);
    ds::dn::Node<int>* tmp = root;
    for(int i = 1;i < nc;i += 1)
    {
        tmp->SetNext(new ds::dn::Node<int>(rand() % 99 + 1));
        tmp->GetNext()->SetPrev(tmp);
        tmp = tmp->GetNext();
    }

    return root;
}

template <class T>
void Print(ds::dn::Node<T>* root)
{
    for(ds::dn::Node<T>* t = root;t != NULL;t = t->GetNext())
    {
        std::cout << t->GetData() << " ";
    }
}

int main()
{
	srand(time(NULL));

	return 0;
}
