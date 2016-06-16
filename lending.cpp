#include "Header.hpp"

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool will_do(Client * client)//checks if a client can borrow more books
{

	vector <Book*> borrowed = client->getBorrowed();


	for (int i = 0; i < borrowed.size(); i++)
	{
		if (borrowed[i] != NULL)
		{
			Book * tmp = borrowed[i];
			if (now - tmp->getBorrowed() > 60)//one minute to overdue
				return(false);
		}
	}

	if (borrowed.size() >= MAX_BOOK)
		return(false);

		return true;
}

void lend(Book *book)
{
	system("cls");

	Client * tmp;

	int name;

	cout << "Please enter ID number of the client you wish to lend the book to:" << endl;
	cin >> name;

	tmp = which_one(name);

	if (!will_do(tmp))
    {
        cout << "The client needs to return book(s) first." << endl;
    }

    else
    {

	if (tmp != NULL)
	{
		book->setLender(tmp);
		book->setAvailability(false);
		book->setBorrowed(now);

		tmp->setBorrowed(book);

		cout << "Book nr. " << book->getID() << " was lent to " << tmp->getSurname() << " " << tmp->getName() << endl;
	}
    }
	system("pause");
}

Client * which_one(int name)
{
	Client * tmp = head;
	static Client * list[50];
	int ch, i = 0;

	system("cls");
	cout << "Searching..." << endl;


	while (tmp != NULL)
	{
		if (tmp->getID() == name)
		{
			list[i] = tmp;
			i++;
			cout << "Result no." << i << endl;
			tmp->print();
		}
		tmp = tmp->getNext();
	}

	if (i == 0)
	{
		system("cls");
		cout << "No such ID was found." << endl;
		cout << "Please try again." << endl;
		return (NULL);
	}

	cout << "Which of the clients do you want to lend the book to? (enter a number)" << endl;


	cin >> ch;
	ch--;
	if (ch > 49 || list[ch] == NULL)
	{
		cout << "Invalid response. Please start again." << endl;
		return (NULL);
	}
	else
		return(list[ch]);
}

void borrow(Client * client)
{
	system("cls");

	if (!will_do(client))
    {
        cout << "The client needs to return book(s) first." << endl;
    }

    else
{


	Book * tmp = NULL;

	string name;
	int id;

	cout << "Please enter ID number or title of the book you wish to lend:" << endl;
	stahp();
	getline(cin, name);

	if (is_number(name))
	{
		const char * c = name.c_str();
		id = atoi(c);
		tmp = find_it(id);
	}
	else
		tmp = find_it(name);

	if (tmp != NULL)
	{
		if (tmp->getAvailability() == false)
		{
			cout << "The book is already lended. Please return it first or choose a different one." << endl;
			return;
		}
		tmp->setLender(client);
		tmp->setAvailability(false);

		tmp->setBorrowed(now);

		client->setBorrowed(tmp);

		cout << "Book nr. " << tmp->getID() << " was lent to " << client->getSurname() << " " << client->getName() << endl;
	}

	else
		cout << "The book was not found. Please try again." << endl;
}
	system("pause");
}

Book * find_it(int id)
{

	Category *tmp1 = beginning;
	Book *tmp;
	static Book * list[50];

	system("cls");
	cout << "Searching..." << endl;

	int i = 0;

	while (tmp1 != NULL)
	{
		tmp = tmp1->getHead();

		while (tmp != NULL)
		{
			if (tmp->getID() == id)
			{
				list[i] = tmp;
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
		system("cls");
		cout << "No such ID was found." << endl;
		cout << "Please try again" << endl;
		return (NULL);
	}

	else
	{
		cout << "Which of the results do you want to lend? (enter a number)" << endl;

		int ch;
		cin >> ch;
		ch--;
		if (ch > 49 || list[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
			return (NULL);
		}

		else
			return (list[ch]);
	}
}

Book * find_it(string title)
{
	Category *tmp1 = beginning;
	Book *tmp;
	static Book * list[50];

	system("CLS");
	cout << "Searching..." << endl;

	int i = 0;

	while (tmp1 != NULL)
	{
		tmp = tmp1->getHead();

		while (tmp != NULL)
		{
			if (iequals(tmp->getTitle(), title))
			{
				list[i] = tmp;
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
		system("cls");
		cout << "No such ID was found." << endl;
		cout << "Please try again" << endl;
		return (NULL);
	}

	else
	{
		cout << "Which of the results do you want to lend? (enter a number)" << endl;

		int ch;
		cin >> ch;
		ch--;
		if (ch > 49 || list[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
			return (NULL);
		}

		else
			return (list[ch]);
	}
}

void show_lended(Client * client)
{
	system("cls");
	int i = 0;
	
	vector <Book*> borrowed = client->getBorrowed();

	try
	{
		for (i = 0; i < borrowed.size(); i++)
		{
			cout << "Result no. " << i+1 << endl;
			borrowed[i]->print();
		}
	}
	catch (...)
	{
		cout << "Something went wrong. Please try again." << endl;
		return;
	}

	if (i != 0)
	{
		cout << "Which of the books do you want to manage? (enter a number)" << endl;

		stahp();
		int ch;
		cin >> ch;
		ch--;
		if (borrowed[ch] == NULL)
		{
			cout << "Invalid response. Please start again." << endl;
			return;
		}

		else
			book_menu(borrowed[ch]);
	}
	system("pause");
}

void book_return(Book *book)
{
	Client *lender = book->getLender();
	vector <Book *> borrowed = lender->getBorrowed();

	for (int i = 0; i < MAX_BOOK; i++)
	{
		Book * tmp = borrowed[i];
		if (tmp == book)
			break;
	}

	book->setLender(NULL);
	book->setAvailability(true);
	book->setBorrowed(0);

	cout << "Book no. " << book->getID() << " was returned successfully." << endl;
}
