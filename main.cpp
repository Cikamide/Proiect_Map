#include <iostream>
#include <string>
using namespace std;

int Granite[100][100];
int n = 0, m=0;

struct Tari
{
    int index;
    string nume;
    int id_culoare;
} A[100];

int Verificare_Tara(string tara)
{
    for(int i=0;i<n;i++)
    {
      if(A[i].nume==tara) return i;
    }
    return -1;
}

void Citire_Tari()
{
    string tara;
    cout << "Introduceti tara: " << endl;
    while(getline(cin, tara))
    {
        if (tara.empty()) break;
        cout << "Introduceti tara: " << endl;
        A[n].nume = tara;
        A[n].index = n + 1;
        n++;
    }
}
void Setare_Granite(string tara1, string tara2)
{
   int aux1=Verificare_Tara(tara1);
   int aux2=Verificare_Tara(tara2);
   Granite[aux1][aux2] = Granite[aux2][aux1] = 1;
}

void Vecini()
{
    
}



int main()
{
   Citire_Tari();
   Vecini();

    for (int k = 0; k < n; k++)
    {
        cout << "Tara NR: " << A[k].index << ":-" << A[k].nume << endl;
    }

    return 0;
}