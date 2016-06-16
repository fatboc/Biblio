#include <iostream>
#include <string>
#include "Book.hpp"

using namespace std;

class Category
{
    string name;
	int id;
    Book *head;
	Category *next;

public:
    Category(string name1, int id1);
    ~Category();
	friend void cat_print();
	friend int cat_export();
	friend int cat_import();
	void print();

	string getName()
	{
		return (name);
	}
	Book * getHead()
	{
		return(head);
	}
	Category * getNext()
	{
		return next;
	}
	int getID()
	{
		return id;
	}
	void setHead(Book * tete)
	{
		head = tete;
	}
	void setName(string nom)
	{
		name = nom;
	}
	void setNext(Category * prochain)
	{
		next = prochain;
	}
};

