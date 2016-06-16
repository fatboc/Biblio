#include <iostream>
#include <vector>
#include <cstdlib>
#include "Header.hpp"

//object searching functions; the ones using id's find a single object; the ones using
//names allow to choose from a list of results

bool iequals(const string& a, const string& b)//case insensitive string comparison
{
	unsigned int sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}

//client searching functions
void client_id_search()
{
	cout << "Enter the client's ID:" << endl;
	int name;
	cin >> name;

	Client * tmp = head;
	int ch, i = 0;

	system("CLS");
	cout << "Searching..." << endl;

	while (tmp != NULL)//searching for a client with a given id
	{
		if (tmp->getID() == name)
		{
			i++;
			cout << "Result no." << i << endl;
			tmp->print();
			client_menu(tmp);
			break;
		}
		tmp = tmp->getNext();
	}

	if (i == 0)
	{
		system("CLS");
		cout << "No such ID was found." << endl;
		cout << "Please try again." << endl;
	}
}

void client_name_search(int which)//which - first or second name search
{
	cout << "Enter the client's name:" << endl;
	string name;
	cin >> name;
	Client * tmp = head;
	vector <Client *> list;
	int ch, i = 0;

	system("CLS");
	cout << "Searching..." << endl;

	if (which == 1)
	{
		while (tmp != NULL)
		{
			if (iequals(tmp->getSurname(), name))
			{
				list.push_back(tmp);
				i++;
				cout << "Result no." << i << endl;
				tmp->print();
			}
			tmp = tmp->getNext();
		}
	}

	if (which == 2)
	{
		while (tmp != NULL)
		{
			if (iequals(tmp->getName(), name))
			{
				list.push_back(tmp);
				i++;
				cout << "Result no." << i << endl;
				tmp->print();
			}
			tmp = tmp->getNext();
		}
	}

	if (i == 0)
	{
		system("CLS");
		cout << "No such name was found." << endl;
		cout << "Please try again." << endl;
	}

	else
	{
		cout << "Which of the clients do you want to manage? (enter a number)" << endl;

		cin >> ch;
		ch--;
		i--;
		if (ch > i || list[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
		}
		else
			client_menu(list[ch]);
	}
}

//book searching functions
void book_id_search()
{
	cout << "Enter the book's ID:" << endl;
	int id;
	cin >> id;

	Category *tmp1 = beginning;
	Book *tmp;

	system("CLS");
	cout << "Searching..." << endl;

	int i = 0;

	while (tmp1 != NULL)
	{
		tmp = tmp1->getHead();

		while (tmp != NULL)
		{
			if (tmp->getID() == id)
			{
				i++;
				tmp->print();
				book_menu(tmp);
				return;
			}
			tmp = tmp->getNext();
		}
		tmp1 = tmp1->getNext();
	}

	if (i == 0)
	{
		system("CLS");
		cout << "No such ID was found." << endl;
		cout << "Please try again" << endl;
	}
}

void book_title_search()
{
	cout << "Enter the book's title:" << endl;
	string name;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	Category *tmp1 = beginning;
	Book *tmp;
	vector <Book *> list;

	system("CLS");
	cout << "Searching..." << endl;

	int i = 0;

	while (tmp1 != NULL)
	{
		tmp = tmp1->getHead();

		while (tmp != NULL)
		{
			if (iequals(tmp->getTitle(), name))
			{
				list.push_back(tmp);
				i++;
				cout << "Result no." << i << endl;
				tmp->print();
			}
			tmp = tmp->getNext();
		}
		tmp1 = tmp1->getNext();
	}

	if (i == 0)
	{
		system("CLS");
		cout << "No book with such title was found." << endl;
		cout << "Please try again" << endl;
	}

	else
	{
		cout << "Which of the results do you want to manage? (enter a number)" << endl;

		stahp();
		int ch;
		cin >> ch;
		ch--;
		if (ch > 49 || list[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
		}

		else
			book_menu(list[ch]);
	}
}

void book_author_search()
{
	cout << "Enter the book's author:" << endl;
	string name;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	Category *tmp1 = beginning;
	Book *tmp;
	vector <Book *> list;

	system("CLS");
	cout << "Searching..." << endl;

	int i = 0;

	while (tmp1 != NULL)
	{
		tmp = tmp1->getHead();

		while (tmp != NULL)
		{
			if (iequals(tmp->getAuthor(), name))
			{
				list.push_back(tmp);
				i++;
				cout << "Result no." << i << endl;
				tmp->print();
			}
			tmp = tmp->getNext();
		}
		tmp1 = tmp1->getNext();
	}

	if (i == 0)
	{
		system("CLS");
		cout << "No such ID was found." << endl;
		cout << "Please try again" << endl;
	}

	else
	{
		cout << "Which of the results do you want to manage? (enter a number)" << endl;

		stahp();
		int ch;
		cin >> ch;
		ch--;
		if (ch > 49 || list[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
		}

		else
			book_menu(list[ch]);
	}
}

void cat_id_search()
{
	cout << "Enter category ID: " << endl;

	int cat;
	cin >> cat;

	Category * tmp1 = beginning;
	int check = 0;

	while (tmp1 != NULL)
	{
		if (tmp1->getID() == cat)
		{
			check = 1;
			break;
		}
		tmp1 = tmp1->getNext();
	}

	if (check != 1)
	{
		cout << "Such a category was not found. Please try again." << endl;
	}

	else
	{
		tmp1->print();
		cat_menu(tmp1);
	}
}

void cat_name_search()
{
    cout << "Enter the category's name:" << endl;
	string name;
	cin >> name;
	Category *tmp = beginning;
	vector <Category *> list;
	int ch, i = 0;

	system("CLS");
	cout << "Searching..." << endl;

		while (tmp != NULL)
		{
			if (iequals(tmp->getName(), name))
			{
				list.push_back(tmp);
				i++;
				cout << "Result no." << i << endl;
				tmp->print();
			}
			tmp = tmp->getNext();
		}

	if (i == 0)
	{
		system("CLS");
		cout << "No such name was found." << endl;
		cout << "Please try again." << endl;
	}

	else
	{

		cout << "Which of the categories do you want to manage? (enter a number)" << endl;


		cin >> ch;
		ch--;
		if (ch > 49 || list[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
		}
		else
			cat_menu(list[ch]);
	}
}
