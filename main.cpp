#include <iostream>
#include <string>
using namespace std;

int Granite[100][100];
int i = 0, j = 0;

struct Tari
{
    int index;
    string nume;
    int id_culoare;
} A[100];


void Citire_Tari()
{
    string tara;
    cout << "Introduceti tara: " << endl;
    while(getline(cin, tara))
    {
        if (tara.empty()) break;
        cout << "Introduceti tara: " << endl;
        A[i].nume = tara;
        A[i].index = i + 1;
        i++;
    }
}

int main()
{
   Citire_Tari();

    for (int k = 0; k < i; k++)
    {
        cout << "Tara NR: " << A[k].index << ":-" << A[k].nume << endl;
    }

    return 0;
}