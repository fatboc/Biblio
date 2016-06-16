#include <iostream>
#include <string>
#include "Client.hpp"

using namespace std;

class Book
{
    string title;
    string author;
    bool available;
    int id;
	int published;
    Client *lender;
    Book *next;
	time_t borrowed;

public:
    Book(string title1, string author1, int id1, int pub, int bor);
	Book(string title1, string author1, int id1, int pub, int bor, Client * lend);
    ~Book();
	friend void book_print();
	friend int book_export(int cat_id);
	friend int book_import(int cat_id);
	void print();

	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}
	bool getAvailability()
	{
		return available;
	}
	int getID()
	{
		return id;
	}
	int getPublished()
	{
		return published;
	}
	Client * getLender()
	{
		return lender;
	}
	time_t getBorrowed()
	{
		return borrowed;
	}
	Book * getNext()
	{
		return next;
	}
	void setTitle(string nom)
	{
		title = nom;
	}
	void setAuthor(string autheur)
	{
		author = autheur;
	}
	void setAvailability(bool disponible)
	{
		available = disponible;
	}
	void setID(int idenetite)
	{
		id = idenetite;
	}
	void setPublished(int edition)
	{
		published = edition;
	}
	void setLender(Client * preteur)
	{
		lender = preteur;
	}
	void setBorrowed(time_t borrow)
	{
		borrowed = borrow;
	}
	void setNext(Book * prochain)
	{
		next = prochain;
	}
};

