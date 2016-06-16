#include "Header.hpp"

using namespace std;

Client *head;
Book *first;
Category *beginning;

void stahp() //flushes the buffer, restores its state and ignores input until end of line
{
	cout.flush();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Book::Book(string title1, string author1, int id1, int pub, int bor)//Book constructor
{
	this->title = title1;
	this->author = author1;
	this->available = true;
	this->id = id1;
	this->published = pub;
	this->lender = NULL;
	this->borrowed = bor;
	this->next = NULL;

	print();
}

Book::Book(string title1, string author1, int id1, int pub, int bor, Client * lend)//Book constructor
{
	this->title = title1;
	this->author = author1;
	this->available = false;
	this->id = id1;
	this->published = pub;
	this->lender = lend;
	this->borrowed = bor;
	this->next = NULL;

	print();
}

void Book::print()//Prints information about given Book object
{
	cout.setf(ios::boolalpha);
	cout << "BOOK DATA:" << endl;
	cout << "Title: " << title << "; Author: " << author << "; ID: ";
	cout << id << "; Year of publishing: " << published << "; Available: ";
	cout << available;
	if (available == false)
	{
		cout << "; Lender ID: " << lender->getID();
		cout << "; Date of borrowing: " << ctime(&borrowed);
	}
	cout << endl;
}

Book::~Book()//Book destructor
{
	cout << "Deleting book no. " << id << endl;
	cout << "Delete completed." << endl;
}

Client::Client(string name1, string name2, string adress1, int id1)//Client constructor
{
	this->surname = name1;
	this->name = name2;
	this->adress = adress1;
	this->id = id1;
	this->next = NULL;

	print();
}

Client::~Client()//Client destructor
{
	cout << "Deleting client " << surname << " " << name << endl;
	cout << "Delete completed." << endl;
}

void Client::print()//Prints information about given Book object
{
	cout << "CLIENT DATA:" << endl;
	cout << "Surname: ";
	cout << surname << "; Name: " << name << "; Adress: ";
	cout << adress << "; ID: " << id << endl;
}

Category::Category(string name1, int id1)//Category constructor
{
	this->name = name1;
	this->id = id1;
	this->head = NULL;
	this->next = NULL;

	print();
}

Category::~Category()//Category destructor
{
	cout << "Deleting cat. no. " << id << endl;
	cout << "Delete completed." << endl;
}

void Category::print()//Prints information about given Category object
{
	cout << "CATEGORY DATA:" << endl;
	cout << "Name: " << name << "; ID: " << id << endl;
}

void add_client()//Allows user to add a new client
{
	system("cls");
	string surname, name, adress;
	int id;
	cout << "Please enter new client's surname:" << endl;
	cin >> surname;
	cout << "Please enter new client's first name:" << endl;
	cin >> name;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Please enter new client's address:" << endl;
	getline(cin, adress);
	cout << "Please enter new client's ID number:" << endl;
	cin >> id;

	if (head != NULL)
	{
		Client * tmp = head;
		if (id == tmp->getID())
		{
			cout << "That ID number already exists. Please try again." << endl;
			system("pause");
			return;
		}
	}

	Client *new_client = new Client(surname, name, adress, id);

	if (head == NULL)
		head = new_client;

	else
	{
		Client *tmp = head;
		while (tmp->getNext() != NULL)
			tmp = tmp->getNext();

		tmp->setNext(new_client);
	}
	system("pause");
}
int add_book()//Allows user to add a new book
{
	system("cls");
	string title, author;
	int id, pub, cat;
	cout << "Please enter new book's title:" << endl;
	stahp();
	getline(cin, title);
	cout << "Please enter new book's author:" << endl;
	getline(cin, author);
	cout << "Please enter new book's year of publishing:" << endl;
	cin >> pub;
	cout << "Please enter new book's ID number:" << endl;
	cin >> id;
	cout << "Please enter the ID of the category to which the book belongs:" << endl;
	stahp();
	cin >> cat;

	Category * tmp1 = beginning;
	int check = 0;

	while (tmp1 != NULL)
	{
		Book * tmp = tmp1->getHead();
		while (tmp != NULL)
		{
			if (id == tmp->getID())
			{
				cout << "That ID number already exists. Please try again." << endl;
				system("pause");
				return (-1);
			}
			tmp = tmp->getNext();
		}
		tmp1 = tmp1->getNext();
	}

	Book *new_book = new Book(title, author, id, pub, 0);

	//Since a book must belong to a category, program now searches for it.

	tmp1 = beginning;

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
		system("pause");
		delete new_book;
		return(-1);
	}

	else
	{
		first = tmp1->getHead();

		if (first == NULL)
			tmp1->setHead(new_book);

		else
		{
			Book *tmp = first;
			while (tmp->getNext() != NULL)
				tmp = tmp->getNext();

			tmp->setNext(new_book);
		}
		return(0);
	}
}

void add_cat()//Allows user to add new category
{
	system("cls");
	string name;
	int id;
	cout << "Please enter new category's name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Please enter new category's ID number:" << endl;
	cin >> id;

	Category *tmp = beginning;
	while (tmp != NULL)
	{
		if (tmp->getID() == id)
		{
			cout << "That ID number already exists. Please try again." << endl;
			system("pause");
			return;
		}
		tmp = tmp->getNext();
	}

	Category *new_cat = new Category(name, id);

	if (beginning == NULL)
		beginning = new_cat;

	else
	{
		tmp = beginning;
		while (tmp->getNext() != NULL)
			tmp = tmp->getNext();

		tmp->setNext(new_cat);
	}
	system("pause");
}

int client_import()//imports client data from a file
{
	string name, surname, adress;
	int id=0;
	int i=0;
	vector <int> book;


	ifstream in("clients");

	if(!in)
	{
		cerr << "Cannot open clients file.\n";
		return 1;
	}
    Client * tmp = head;
	{

		while (in)
		{
			int k = book.size();
			while (k != 0)
			{
				book.pop_back();
				k--;
			}
			char c;
			in.get(c);
			if (c == EOF)
				break;
			else
				in.putback(c);
			in >> surname >> name >> id;

			do
			{
				in.get(c);

				if (c == '\n')
				{
					in.putback(c);
					break;
				}

				else
				{
					int bid;
					in >> bid;
					book.push_back(bid);
				}

			} while (c!='\n');
			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(in, adress);
			if (tmp!=NULL)
				if (tmp->id == id)
					break;
			Client *another_one = new Client(surname, name, adress, id);
			if (tmp == NULL)
			{
				head = another_one;
				tmp = head;
				i++;
			}
			else
			{
				tmp->next = another_one;

				tmp = tmp->next;
				tmp->next = NULL;
				i++;
			}

			if (book.size() != 0)
			{
				Category *tmp1 = beginning;
				Book *tmp;

				for (int j = 0; j < book.size(); j++)
				{
					while (tmp1 != NULL)
					{
						tmp = tmp1->getHead();

						while (tmp != NULL)
						{
							if (tmp->getID() == book[i])
							{
								another_one->borrowed.push_back(tmp);
								break;
							}
							tmp = tmp->getNext();
						}
						tmp1 = tmp1->getNext();
					}
				}
			}
		}
	}
	in.clear();
	in.close();

	if (book.size() != 0)
	{

		Category *tmp1 = beginning;
		Book *tmp2;



		int i = 0;
		while (i < book.size())
		{
			while (tmp1 != NULL)
			{
				tmp2 = tmp1->getHead();

				while (tmp2 != NULL)
				{
					if (tmp2->getID() == id)
					{
						tmp->setBorrowed(tmp2);
					}
					tmp2 = tmp2->getNext();
				}
				tmp1 = tmp1->getNext();
			}
			i++;
		}
	}

	cout << i << " clients' data imported." << endl << endl;
	return 0;
}

int client_export()//exports client data to a file
{
    int i=0;

	ofstream out("clients");

	if(!out)
	{
		cerr << "Cannot open clients file.\n";
		return 1;
	}

	out.clear();

	Client *tmp = head;

	while (tmp != NULL)
	{
		out << tmp->surname << " " << tmp->name << " " << tmp->id;
		int j = 0;
		while (j < tmp->borrowed.size())
		{
			out << " " << tmp->borrowed[j]->getID();
			j++;
		}
		out << endl << tmp->adress << endl;
		tmp = tmp->next;
		i++;
	}

	out.close();

	cout << i << " clients' data exported." << endl << endl;

	return 0;
}

void client_print()//Prints all clients' data
{
    Client *tmp = head;

    cout << "CLIENT LIST" << endl << endl;

    while (tmp!=NULL)
    {
        tmp->print();
        tmp = tmp->next;
    }

    cout << "END OF LIST" << endl << endl;
}

int book_import(int cat_id)//imports book data from a file, one separate category at a time
{
	string title, author;
	int published=0;
	int id = 0;
	int i = 0;
	bool available =0;
	int lender_id=0;
	time_t borrowed=0;

	string category = to_string(cat_id);

	ifstream in(category.c_str());

	if (!in)
	{
		cerr << "Cannot open books file.\n";
		return 1;
	}

	in.setf(ios::boolalpha);

	Book *tmp = first;

	int counter = 0;
	{
		char c;
		in.get(c);
		while (c != EOF)
		{
			in.clear();
			int check = 0;
				Client * tmp2 = NULL;

				in.putback(c);
				getline(in, title);
				getline(in, author);
				in >> id >> available >> lender_id >> borrowed >> published;

				in.clear();

				if (tmp != NULL)
					if (tmp->id == id)
					{
						check = 1;
						counter++;
						if (counter > 3)
							return(i);
					}
				

				if (lender_id != 0)
				{
					tmp2 = head;
					int ch, i = 0;

					while (tmp2 != NULL)
					{
						if (tmp2->getID() == lender_id)
						{
							break;
						}
						tmp = tmp->getNext();
					}
				}
				if (check == 0)
				{
					Book *yet_another_one = new Book(title, author, id, published, 0);

					if (tmp2 != NULL)
					{
						yet_another_one->borrowed = borrowed;
						yet_another_one->lender = tmp2;
						yet_another_one->available = false;
						tmp2->setBorrowed(yet_another_one);
					}


					if (tmp == NULL)
					{
						Category * tmp1 = beginning;
						while (tmp1 != NULL)
						{
							if (tmp1->getID() == cat_id)
							{
								i++;
								tmp1->setHead(yet_another_one);
								tmp = tmp1->getHead();
								break;
							}
							tmp1 = tmp1->getNext();
						}
					}
					else
					{
						tmp->next = yet_another_one;

						tmp = tmp->next;
						tmp->next = NULL;
						i++;
					}
				}
				in.ignore(numeric_limits<streamsize>::max(), '\n');
				in.get(c);
		}
	}
	in.clear();
	in.close();
	cout << i << " books' data imported." << endl << endl;
	return i;
}
int book_export(int cat_id)//exports book data to a file, one category at a time
{
	string category = to_string(cat_id);

	int i=0;

	ofstream out(category.c_str());

	if(!out)
	{
		cerr << "Cannot open books file.\n";
		return 1;
	}

	out.setf(ios::boolalpha);

	out.clear();

	Book *tmp = NULL;

	Category * tmp1 = beginning;
	while (tmp1 != NULL)
	{
		if (tmp1->getID() == cat_id)
		{
			tmp = tmp1->getHead();
			break;
		}
		tmp1 = tmp1->getNext();
	}

	while (tmp != NULL)
	{
		out << tmp->title << endl << tmp->author << endl << tmp->id <<" ";
		out << tmp->available << " ";
		if (tmp->available)
			out << "0 0 ";
		else
			out << tmp->lender->getID()<< " " << tmp->borrowed << " ";
		out << tmp->published << endl;
		tmp = tmp->next;
		i++;
	}

	out.close();

	cout << i << " books' data exported." << endl << endl;

	return i;
}

int cat_export()
{
    int i=0;
    int j=0;

	ofstream out("categories.txt");

	if (!out)
	{
		cerr << "Cannot open categories file.\n";
		return 1;
	}

	out.clear();

	Category *tmp = beginning;

	while (tmp != NULL)
	{
		out << tmp->name << endl;
		out << tmp->id << endl;
		j+=book_export(tmp->id);
		tmp = tmp->next;
		i++;
	}

	out.close();

	cout << i << " categories' and " << j << " books' data exported." << endl <<endl;

	return 0;
}
int cat_import()
{
	string name;
	int id;
	int i = 0, j = 0;

	ifstream in("categories");

	if (!in)
	{
		cerr << "Cannot open categories file.\n";
		return 1;
	}

	Category *tmp = beginning;

	{

		while (in)
		{
			in.clear();
			char c;
			in.get(c);
			if (c == EOF)
				break;
			else
				in.putback(c);
			getline(in, name);
			in >> id;

			if (tmp != NULL)
				if (tmp->id == id)
					break;

			Category *again_another_one = new Category(name, id);
			
			if (tmp == NULL)
			{
				beginning = again_another_one;
				tmp = beginning;
				i++;
			}
			else
			{
				tmp->next = again_another_one;

				tmp = tmp->next;
				tmp->next = NULL;
				i++;
			}
			j += book_import(id);

			in.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}
	in.clear();
	in.close();

	cout << i << " categories' and " << j << " books' data imported." << endl <<endl;

	return 0;
}

void book_print()//Prints data of all books from all categories
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
				tmp->print();
				tmp = tmp->next;
			}

		tmp1 = tmp1->getNext();
	}
	cout << endl << "END OF LIST" << endl << endl;
}

void c_book_print(bool avail)//Prints data of all books from all categories with a condition
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
			if (tmp->getAvailability()==avail)
				tmp->print();
			tmp = tmp->getNext();
		}

		tmp1 = tmp1->getNext();
	}
	cout << endl << "END OF LIST" << endl << endl;
}

void cat_print()//Prints all cats. data
{
	Category *tmp = beginning;

	cout << endl << "CATEGORY LIST" << endl << endl;

	while (tmp != NULL)
	{
		tmp->print();
		tmp = tmp->next;
	}

	cout << "END OF LIST" << endl << endl;
}