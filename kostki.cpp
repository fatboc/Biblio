#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int i, n, j;
    char ans;

    srand(time(NULL));

    cout << "Wcisnij dowolny klawisz by rozpoczac program.\n";

    while ((ans=getchar())!='`')
    {
        if (ans=='`')
            break;
        cout << "Wcisnij ` aby zamknac prgram, lub wpisz liczbe kostek, ktorymi chcesz rzucic:\n";
        cin >> i;

        for (j=0; j<i; j++)
        {
            n=rand()%6 +1;
            cout << "Kostka nr " << j+1 << ": " << n << "\n";
        }

    }

    return(0);
}
