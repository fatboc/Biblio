#include <iostream>
#include <limits>
#include <cstdlib>
#include "Header.hpp"

using namespace std;



void overdues(int mode)//a dummy function, might need it one day
{
	if (mode == 1)
	{
		Category *tmp1 = beginning;
		Book *tmp;

		cout << endl << "BOOK LIST" << endl << endl;

		while (tmp1 != NULL)
		{
			cout << "CATEGORY " << tmp1->getID() << endl;
			tmp = tmp1->getHead();

			while (tmp != NULL)
			{
				if (tmp->getBorrowed() != 0 && now - tmp->getBorrowed() > 60)
					tmp->print();
				tmp = tmp->getNext();
			}

			tmp1 = tmp1->getNext();
		}
		cout << endl << "END OF LIST" << endl << endl;
	}

	if (mode == 2)
	{
		Client *tmp2 = head;

		cout << "CLIENT LIST" << endl << endl;

		while (tmp2 != NULL)
		{
			vector <Book *> book;
			int c = 0;
			book = tmp2->getBorrowed();

			for (int i = 0; i < book.size(); i++)
			{
				Book * tmp = book[i];
				if ((now - tmp->getBorrowed()) > 60)
					c = 1;
			}

			if (c==1)
				tmp2->print();
			tmp2 = tmp2->getNext();
		}

		cout << "END OF LIST" << endl << endl;
	}
}

void book_menu(Book *book)
{
	cout << endl;

	cout << "What would you like to do with the book?" << endl << endl;
	
	if (book->getAvailability() == true)
	{
		cout << "1. Lend to a client" << endl;
		cout << "2. Edit" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Nothing, go back" << endl;

		char ch;

		stahp();
		ch = getchar();

		switch (ch)
		{
		case '1':
			lend(book);
			break;
		case'2':
			change_book(book);
			break;
		case'3':
			remove_book(book);
			break;
		case'4':
			break;
		default:
			cout << "Please provide a valid response." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			book_menu(book);
			break;
		}
	}

	else
	{
		cout << "1. Return the book" << endl;
		cout << "2. Edit" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Nothing, go back" << endl;

		char ch;

		stahp();
		ch = getchar();

		switch (ch)
		{
		case '1':
			book_return(book);
			break;
		case'2':
			change_book(book);
			break;
		case'3':
			remove_book(book);
			break;
		case'4':
			break;
		default:
			cout << "Please provide a valid response." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			book_menu(book);
			break;
		}

	}
}

void client_menu(Client * client)
{
	cout << endl;

	cout << "What would you like to do with the client?" << endl << endl;
	cout << "1. Lend him a book" << endl;
	cout << "2. View his borrowed books" << endl;
	cout << "3. Edit" << endl;
	cout << "4. Delete" << endl;
	cout << "5. Nothing, go back" << endl;

	char ch;

	stahp();
	ch = getchar();

	switch (ch)
	{
	case '1':
		borrow(client);
		break;
	case'2':
		show_lended(client);
		break;
	case'3':
		change_client(client);
		break;
	case'4':
		remove_client(client);
		break;
	case'5':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		client_menu(client);
		break;
	}
}

void cat_menu(Category * cat)
{
	cout << endl;

	cout << "What would you like to do with the category?" << endl << endl;
	cout << "1. Edit" << endl;
	cout << "2. Delete (Only, if it's already empty)" << endl;
	cout << "3. Nothing, go back" << endl;

	char ch;

	stahp();
	ch = getchar();

	switch (ch)
	{
	case '1':
		change_cat(cat);
		break;
	case'2':
		remove_cat(cat);
		break;
	case'3':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cat_menu(cat);
		break;
	}
}

void change_client(Client * client)
{
	system("CLS");
	cout << "Which of the following would you like to edit?" << endl;
	cout << "1. Client's ID" << endl;
	cout << "2. Client's first name" << endl;
	cout << "3. Client's surname" << endl;
	cout << "4. Client's address" << endl;
	cout << "5. None. Go back" << endl;

	char ch;
	stahp();
	ch = getchar();
	string new_name;

	switch (ch)
	{
	case'1':
		system("CLS");
		cout << "Please enter new ID:" << endl;
		int new_id;
		cin >> new_id;
		edit_client(new_id, client);
		break;
	case'2':
		system("CLS");
		cout << "Please enter client's first name:" << endl;
		cin >> new_name;
		edit_client(new_name, 1, client);
		break;
	case'3':
		system("CLS");
		cout << "Please enter client's surname:" << endl;
		cin >> new_name;
		edit_client(new_name, 2, client);
		break;
	case'4':
		system("CLS");
		cout << "Please enter client's address:" << endl;
		getline(cin, new_name);
		edit_client(new_name, 3, client);
		break;
	case '5':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		change_client(client);
		break;
	}
}

void edit_client(int id, Client * client)
{
	Client * tmp = head;
	int check = 0;
	while (tmp!=NULL)
	{
		if (tmp->getID() == id)
		{
			check = 1;
			break;
		}
		tmp = tmp->getNext();
	}

	if (check == 0)
	{
		client->setID(id);
		client->print();
	}

	else
		cout << "This ID is already in use. Please try again" << endl;

	system("pause");
}
void edit_client(string name, int which_one, Client * client)
{
	switch (which_one)
	{
	case 1:
		client->setName(name);
		client->print();
		break;
	case 2:
		client->setSurname(name);
		client->print();
		break;
	case 3:
		client->setAdress(name);
		client->print();
		break;
	}

	system("pause");
}

void change_book(Book * book)
{
	system("CLS");
	cout << "Which of the following would you like to edit?" << endl;
	cout << "1. Book's title" << endl;
	cout << "2. Book's author" << endl;
	cout << "3. Book's year of publishing" << endl;
	cout << "4. Book's category" << endl;
	cout << "5. None. Go back" << endl;

	char ch;
	stahp();
	ch = getchar();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string new_name;
	int id2;

	switch (ch)
	{
	case'1':
		system("CLS");
		cout << "Please enter title:" << endl;
		getline(cin, new_name);
		edit_book(new_name, 1, book);
		break;
	case'2':
		system("CLS");
		cout << "Please enter book's author:" << endl;
		getline(cin, new_name);
		edit_book(new_name, 2, book);
		break;
	case'3':
		system("CLS");
		cout << "Please enter book's year of publishing:" << endl;
		cin >> id2;
		edit_book(id2, 1, book);
		break;
	case'4':
		system("CLS");
		cout << "Please enter category's id:" << endl;
		cin >> id2;
		edit_book(id2, 2, book);
		break;
	case '5':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		change_book(book);
		break;
	}
}

void edit_book(int id, int which_one, Book * book)
{
	switch (which_one)
	{
	case 1:
		book->setPublished(id);
		book->print();
		break;
	case 2:
		Category * tmp1 = beginning;
		int check;
		while (tmp1 != NULL)
		{
			if (tmp1->getID() == id)
			{
				check = 1;
				break;
			}
			tmp1 = tmp1->getNext();
		}

		if (check != 1)
		{
			cout << "Such a category was not found. Please try again." << endl;
			system("pause");
			break;
		}

		else
		{
			Book * first = tmp1->getHead();

			if (first == NULL)
				first = book;

			else
			{
				Book *tmp = first;
				while (tmp->getNext() != NULL)
					tmp = tmp->getNext();

				tmp->setNext(book);
			}
		}

	}

	system("pause");
}
void edit_book(string name, int which_one, Book * book)
{
	switch (which_one)
	{
	case 1:
		book->setTitle(name);
		book->print();
		break;
	case 2:
		book->setAuthor(name);
		book->print();
	}

	system("pause");
}

void change_cat(Category * cat)
{
	system("CLS");
	cout << "Which of the following would you like to edit?" << endl;
	cout << "1. Category's name" << endl;
	cout << "2. None. Go back" << endl;

	char ch;
	stahp();
	ch = getchar();
	string new_name;

	switch (ch)
	{
	case'1':
		system("CLS");
		cout << "Please enter new name:" << endl;
		stahp();
		getline(cin, new_name);
		cat->setName(new_name);
		cat->print();
		break;
	case'2':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		change_cat(cat);
		break;
	}
}

void remove_cat(Category * cat)
{
	Category *prev = beginning;
	Category *tmp;

	if (cat->getHead() != NULL)
		cout << "You cannot delete a non-empty category! Please try again" << endl;

	else
	{
		if (beginning->getID() == cat->getID())
		{
			if (beginning->getNext() == NULL)
			{
				delete cat;
				beginning = NULL;
			}
			else
			{
				tmp = beginning->getNext();
				delete cat;
				beginning = tmp;
			}
		}
		else
		{
			while (cat->getID() != prev->getNext()->getID())
				prev = prev->getNext();

			tmp = cat->getNext();
			delete cat;
			prev->setNext(tmp);
		}

		cout << "Delete completed" << endl;
	}

	system("pause");
}

void remove_book(Book * book)
{


	Category *tmp1 = beginning;
	Book * prev = tmp1->getHead();
	Book * tmp = NULL;

	while (tmp1 != NULL)
	{

		Book * tmp2 = tmp1->getHead();
		if (tmp2->getID() == book->getID())
		{
			if (tmp2->getNext() == NULL)
			{
				delete book;
				tmp1->setHead(NULL);
			}
			else
			{
				tmp = tmp2->getNext();
				delete book;
				tmp1->setHead(tmp);
			}
			return;
		}

		prev = tmp1->getHead();
		tmp = prev->getNext();

		while (prev->getNext() != NULL)
			{
				if (tmp->getID() == book->getID())
				{
					tmp = tmp->getNext();
					delete book;
					prev->setNext(tmp);
					return;
				}
				prev = prev->getNext();
				tmp = tmp->getNext();
			}
			tmp1 = tmp1->getNext();
		}
		
		

	system("pause");
}

void remove_client(Client * client)
{
	Client *prev = head;
	Client *tmp;

		if (head->getID() == client->getID())
		{
			if (head->getNext() == NULL)
			{
				delete client;
				head = NULL;
			}
			else
			{
				tmp = head->getNext();
				delete client;
				head = tmp;
			}
		}
		else
		{
			while (client->getID() != prev->getNext()->getID())
				prev = prev->getNext();

			tmp = client->getNext();
			delete client;
			prev->setNext(tmp);
		}

	system("pause");
}


