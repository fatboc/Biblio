#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iostream>
#include<fstream>
#include <limits>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Category.hpp"


using namespace std;


class Book;
class Client;
class Category;

static time_t now = time(0);

extern Client *head;
extern Book *first;
extern Category *beginning;


//search
void book_id_search();
void book_title_search();
void book_author_search();
void client_id_search();
void client_name_search(int which);
void cat_id_search();
void cat_name_search();
bool iequals(const string& a, const string& b);

//niceties
void bookSearch();
void catSearch();
int chooseActivity();
void clientSearch();
void importAll();
void Manage(int what);
void start();
int startImport();
void AllExport();
void book_view();
void client_view();

//menus
void book_menu(Book *book);
void overdues(int mode);
void cat_menu(Category * cat);
void client_menu(Client * client);
void edit_client(string name, int which_one, Client * client);
void edit_client(int id, Client * client);
void change_client(Client * client);
void change_book(Book * book);
void change_cat(Category * cat);
void edit_book(string name, int which_one, Book * book);
void edit_book(int id, int which_one, Book * book);
void remove_cat(Category * cat);
void remove_book(Book * book);
void remove_client(Client * client);

//lending
bool will_do (Client* client);
void lend(Book *book);
void borrow(Client * client);
Client * which_one(int name);
Book * find_it(int id);
Book * find_it(string title);
void show_lended(Client * client);
void book_menu(Book * book);
void book_return(Book * book);
void show_lended(Client * client);

//functions
void stahp();
void add_client();
void add_cat();
int add_book();
int client_export();
int client_import();
int book_export(int cat_id);
int cat_export();
int cat_import();
void book_print();
void cat_print();
int book_import(int cat_id);
void c_book_print(bool avail);