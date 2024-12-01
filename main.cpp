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
    for(int i=0;i<n;n++)
    {
      if(A[i].nume==tara) return 1;
    }
    return 0;
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
    for(int i=0;i<n;i++)
    {
      if(tara1==A[i].nume)
      {
        for(int j=0;j<n;j++)
        {
            if(tara2==A[j].nume)
            {
              Granite[i][j]=Granite[j][i]=1;
            } 
        }
      }
    }
}

void Vecini()
{
    string tara, vecini;
    cout<<"Introduceti tara a carei vecini vreti sa ii numiti: "<<endl;
    cin>>tara;
    if(Verificare_Tara(tara)==0)
    {
        cout<<"Tara indrodusa gresit sau nu exista.Incercati iar."<<endl;
        void Vecini();
    }
    cout<<"Care sunt tarile cu care vrei ca "<<tara<<" sa se invecineze: "<<endl;

    while(cin>>vecini)
    {
        if(Verificare_Tara(vecini)==0) cout<<"Tara indrodusa gresit sau nu exista.Incercati iar";
        Setare_Granite(tara, vecini);
    }
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