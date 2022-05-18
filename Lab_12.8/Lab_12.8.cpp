#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

struct Elem
{
	Elem* next,
		* prev;
	int info;
};


void Enqueue(Elem*& first, Elem*& last, int value)
{
	Elem* tmp = new Elem;
	tmp->info = value; // 2
	tmp->next = NULL; // 3
	if (last != NULL)
		last->next = tmp; // 4
	tmp->prev = last; // 5
	last = tmp; // 6
	if (first == NULL)
		first = tmp; // 7
}

void PrintBegin(Elem* begin)
{
	while (begin != NULL)
	{
		cout << begin->info << "\t";
		begin = begin->next;
	}
	cout << endl;
}

void PrintEnd(Elem* last)
{
	while (last != NULL)
	{
		cout << last->info << "\t";
		last = last->prev;
	}
	cout << endl;
}

void Remove(Elem *& first,Elem*& last,int value) 
{
	while (first != NULL)
	{
		if (first->info == value)
		{
			Elem* next = first->next; // 1
			Elem* prev = first->prev; // 2
			delete first; // 3
			next->prev = prev; // 4
			first = next;
		}
		else
		{
			break;
		}
	}
	Elem* L = first;
	while (L != NULL)
	{
		if (L->info == value)
		{
			Elem* next = L->next; // 1
			Elem* prev = L->prev; // 2
			//delete L; // 3
			if (L->next==NULL)
			{
				delete L;
				prev->next = next;
				return;
			}
			else
			{
				delete L;
				next->prev = prev; // 4
				prev->next = next; // 5
				L = next;
			}
		}
		else
		{
			L = L->next;
		}
	}

}

void Add(Elem*& first, Elem*& last, int value)
{
	Elem* tmp;
	if (first!=NULL)
	{
		tmp = new Elem; // 1
		tmp->info = value; // 2
		tmp->prev = first->prev; // 3
		tmp->next = first; // 4
		first->prev = tmp; // 5
		first = tmp;
	}
	Elem* L = first;
	while (L!=NULL)
	{
		if (L->info == 4)
		{
			tmp = new Elem; // 1
			tmp->info = value; // 2
			tmp->next = L->next; // 3
			L->next = tmp; // 4
			tmp->next->prev = tmp; // 5
			tmp->prev = L;
			L = L->next;
		}
		if (L->next == NULL)
		{
			tmp = new Elem; // 1
			tmp->info = value; // 2
			tmp->next = L->next; // 3
			L->next = tmp; // 4
			tmp->prev = L;
			break;
		}
		L = L->next;
		//if (L->next==NULL)
		//{
		//	tmp = new Elem; // 1
		//	tmp->info = value; // 2
		//	tmp->next = L->next; // 3
		//	L->next = tmp; // 4
		//	tmp->prev = L;
		//}
	}
	//cout << L->info << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* first = NULL,
		* last = NULL;
	int a[]{ 1,1,6,5,1,4,6,56,1 };
	for (int i = 0; i < 9; i++)
	{
		Enqueue(first, last, a[i]);
	}
	PrintBegin(first);
	cout << endl;
	PrintEnd(last);
	cout << endl;
	Remove(first, last, 1);
	PrintBegin(first);
	cout << endl;
	Add(first, last, -5);
	PrintBegin(first);
	return 0;
}
