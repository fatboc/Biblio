#include "Header.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{


	start();

	if (startImport() == 1)
		return 0;

	system("pause");

	int i=0;

	do
	{
		system("cls");
		i = chooseActivity();
	}
	while (i != 1);

	system("pause");
    return 0;
}
