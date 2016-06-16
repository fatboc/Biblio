#include <iostream>
#include <vector>
#define MAX_BOOK 3

using namespace std;

class Book;

class Client
{
    string surname;
    string name;
    string adress;
    int id;
	vector <Book*> borrowed;//change this to a vector storing objects
    Client *next;

public:
    Client(string name1, string name2, string adress1, int id1);
    ~Client();
    void print();
    friend void client_print();
    friend int client_export();
    friend int client_import();

	string getSurname()
	{
		return surname;
	}
	string getName()
	{
		return name;
	}
	string getAdress()
	{
		return adress;
	}
	int getID()
	{
		return id;
	}
	vector <Book*> getBorrowed()
	{
		return borrowed;
	}
	Client * getNext()
	{
		return next;
	}
	void setSurname(string nom)
	{
		surname = nom;
	}
	void setName(string prenom)
	{
		name = prenom;
	}
	void setAdress(string adresse)
	{
		adress = adresse;
	}
	void setID(int identite)
	{
		id = identite;
	}
	void setBorrowed(Book* book)
	{
		if (borrowed.size() >= MAX_BOOK)
			cout << "The client already borrowed three books!" << endl;
		else
			borrowed.push_back(book);
	}
	void setNext(Client * prochain)
	{
		next = prochain;
	}
};


