#include <iostream>
#include <limits>
#include <cstdlib>
#include "Header.hpp"


void client_print();

void start()
{

	cout << "    _     _ _     _ _       _       _" << endl;
	cout << "   | |   (_) |   | (_)     | |     | |" << endl;
	cout << "   | |__  _| |__ | |_  ___ | |_ ___| | ____ _" << endl;
	cout << "   | '_ \\| | '_ \\| | |/ _ \\| __/ _ \\ |/ / _` |" << endl;
	cout << "   | |_) | | |_) | | | (_) | ||  __/   < (_| |" << endl;
	cout << "   |_.__/|_|_.__/|_|_|\\___/ \\__\\___|_|\\_\\__,_|" << endl;

/*	cout << " ____  __  ____  __    __  __  ____  ____  __ _   __  " << endl;
	cout << "(  _ \\(  )(  _ \\(  )  (  )/  \\(_  _)(  __)(  / ) / _\\ " << endl;
	cout << " ) _ ( )(  ) _ (/ (_/\\ )((  O ) )(   ) _)  )  ( /    \\" << endl;
	cout << "(____/(__)(____/\\____/(__)\\__/ (__) (____)(__\\_)\\_/\\_/" << endl;*/

	cout << endl << "Hello!" << endl << endl;
}


void importAll()
{
	client_import();
	cat_import();
}

void bookSearch()
{
	system("cls");
	cout << "How do you wish to search for the book?" << endl;
	cout << "1. By ID" << endl;
	cout << "2. By Title" << endl;
	cout << "3. By Author" << endl;
	cout << "4. I don't, go back" << endl;

	char ch;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ch = getchar();

	switch (ch)
	{
	case'1':
		book_id_search();
		break;
	case'2':
		book_title_search();
		break;
	case'3':
		book_author_search();
		break;
	case'4':
		break;
	default:
		cout << "Please provide a valid response." << endl;

		bookSearch();
		break;
	}


}

void clientSearch()
{
	system("cls");
	cout << "How do you wish to search for the client?" << endl;
	cout << "1. By ID" << endl;
	cout << "2. By surname" << endl;
	cout << "3. By first name" << endl;
	cout << "4. I don't, go back" << endl;

	char ch;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ch = getchar();

	switch (ch)
	{
	case'1':
		client_id_search();
		break;
	case'2':
		client_name_search(1);
		break;
	case'3':
		client_name_search(2);
		break;
	case'4':
		break;
	default:
		cout << "Please provide a valid response." << endl;

		bookSearch();
		break;
	}
    system("pause");
}

void catSearch()
{
	system("cls");
	cout << "How do you wish to search for the category?" << endl;
	cout << "1. By ID" << endl;
	cout << "2. By name" << endl;
	cout << "3. I don't, go back" << endl;

	char ch;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ch = getchar();

	switch (ch)
	{
	case'1':
		cat_id_search();
		break;
	case'2':
	    cat_name_search();
	    break;
    case'3':
        break;
	default:
		cout << "Please provide a valid response." << endl;
		stahp();
		bookSearch();
		break;
	}
system("pause");
}




void Manage(int what)
{
	cout << "Would you like to:" << endl;
	cout << "1. Search existing objects" << endl;
	cout << "2. Add a new one" << endl;
	cout << "3. Go back" << endl;

	char ch;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ch = getchar();

	switch (ch)
	{
	case'1':
		switch (what)
		{
		case 1:
			bookSearch();
			break;
		case 2:
			clientSearch();
			break;
		case 3:
			catSearch();
			break;
		}
		break;
	case '2':
		switch (what)
		{
		case 1:
			add_book();
			break;
		case 2:
			add_client();
			break;
		case 3:
			add_cat();
			break;
		}
		break;
	case '3':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Manage(what);
		break;
	}
system("pause");
}
int startImport()
{
	char c;
	cout << "Do you wish to start? (Y/N)";
	c = getchar();
	if (c == 'n' || c == 'N')
	{
		cout << "Goodbye!"<<endl;
		return (1);
	}
	else if (c == 'y' || c == 'Y')
	{
		importAll();
		return (0);
	}
	else
	{
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		startImport();
		return(2);
	}
}

void AllExport()
{
	try
	{
		client_export();
		cat_export();
	}
	catch (...)
	{
		cout << "Couldn't save data" << endl;
		return;
	}
}

int chooseActivity()
{
	char ch;

	cout << "What would you like to do?" << endl << endl;
	cout << "1. Manage books" << endl;
	cout << "2. Manage clients" << endl;
	cout << "3. Manage categories" << endl;
	cout << "4. View books" << endl;
	cout << "5. View clients" << endl;
	cout << "6. View categories" << endl;
	cout << "7. Save session data" << endl;
	cout << "8. Exit" << endl;

	cout.flush();

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ch = getchar();
	system("CLS");

	switch (ch)
	{
	case '1':
		Manage(1);
		break;
	case '2':
		Manage(2);
		break;
	case '3':
		Manage(3);
		break;
	case '4':
		book_view();
		system("pause");
		break;
	case '5':
		client_view();
		system("pause");
		break;
	case '6':
		cat_print();
		system("pause");
		break;
    case '7':
        AllExport();
        system("pause");
		break;
	case '8':
		return (1);
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		chooseActivity();
		return(-1);
		break;
	}
	return(0);
}

void book_view()
{
	system("cls");

	char ch;

	cout << "How would you like to view the books?" << endl << endl;
	cout << "1. All books" << endl;
	cout << "2. Available books" << endl;
	cout << "3. Lent books" << endl;
	cout << "4. Overdue books" << endl;
	cout << "5. I don't, go back" << endl;
	stahp();

	cin >> ch;

	switch (ch)
	{
	case '1':
		book_print();
		break;
	case '2':
		c_book_print(true);
		break;
	case'3':
		c_book_print(false);
		break;
	case '4':
		overdues(1);
		break;
	case'5':
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		book_view();
		break;
	}
}

void client_view()
{
	system("cls");

	char ch;

	cout << "How would you like to view the clients?" << endl << endl;
	cout << "1. All clients" << endl;
	cout << "2. Clients with books overdue" << endl;
	cout << "3. I don't, go back" << endl;
	stahp();

	cin >> ch;

	switch (ch)
	{
	case '1':
		client_print();
		break;
	case '2':
		overdues(2);
		break;
	case '3' :
		break;
	default:
		cout << "Please provide a valid response." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		client_view();
		break;
	}
}






