#include <iostream>
#include <string>
using namespace std;

int Granite[100][100];
int n = 0, m = 0;

struct Tari
{
    int index;
    string nume;
    int id_culoare;
} A[100];

int Verificare_Tara(string tara)
{
    for (int i = 1; i <= n; i++)
    {
        if (A[i].nume == tara)
            return i;
    }
    return 0;
}

void Citire_Tari()
{
    string tara;
    cout << "Introduceti tara: " << endl;
    while (getline(cin, tara))
    {
        if (tara.empty()) break;
        cout << "Introduceti tara: " << endl;
         n++;
        A[n].nume = tara;
        A[n].index = n;
    }
}
void Setare_Granite(string tara1, string tara2)
{
    int aux1 = Verificare_Tara(tara1);
    int aux2 = Verificare_Tara(tara2);
    if (aux1 > 0 && aux2 > 0) Granite[aux1][aux2] = Granite[aux2][aux1] = 1;
}

void Vecini()
{
    string tara, vecin;
    int opt1 = 0, opt2 = 0, ok;
    while (opt1 != 3)
    {
        switch (opt1)
        {
            cout << "==== MENIU ====" << endl;
            cout << "1. Selectare tara pentre a adauga vecini" << endl;
            cout << "2. Afișare tari si vecini" << endl;
            cout << "3. Iesire" << endl;
            cout << "Alegeti o optiune: " << endl;
            cin >> opt1;

        case 1:
        {
            cout << "Introduceti tara:" << endl;
            cin >> tara;
            if (Verificare_Tara(tara) == -1)
            {
                cout << "Tara introdusa gresit sau nu exista.Incercati iar." << endl;
                break;
            }
            opt2 = 0;
            while (opt2 != 4)
             {
                cout << "\n==== MENIU ȚARĂ: " << tara << " ====" << endl;
                cout << "1. Adăugare vecin țară" << endl;
                cout << "2. Ștergere vecin țară" << endl;
                cout << "3. Afișare vecini țară" << endl;
                cout << "4. Ieșire" << endl;
                cout << "Introduceți opțiunea dorită: "<<endl;
                cin >> opt2;

                switch (opt2) 
                {
                 case 1:
                  { 
                    cout << "Introduceti tara cu care vreti sa se invecineze: "<<endl;
                    cin >> vecin;

                    if (Verificare_Tara(vecin) == 0) cout << "Tara introdusa gresit sau nu exista.Incercati iar." << endl;
                    else
                    {
                        Setare_Granite(tara, vecin);
                        cout << "A fost adaugata tara: " << vecin << " ca vecin pentru  " << tara << "." << endl;
                    }
                    break;
                  }
                  case 2:
                  {
                    cout<<"Introduceti vecinul pe care doriti sa il stergeti:"<<endl;
                    cin>>vecin;
                    int ind1,ind2;
                    ind1=Verificare_Tara(tara);
                    ind2=Verificare_Tara(vecin);
                    if(ind2==0)
                    {
                        cout<<"Vecin introdus gresit sau nu exista.Incercati iar."<<endl;
                        break;
                    }
                    if(Granite[ind1][ind2]==0)
                    {
                        cout<<vecin<<" nu se invecineaza cu "<<tara<<".Incercati iar."<<endl;
                        break;
                    }
                    Granite[ind1][ind2]=Granite[ind2][ind1]=0;
                    cout<<vecin<<" a fost ster cu succes din lista vecinilor tarii: "<<tara<<endl;
                     
                  }
                  case 3:
                  {
                    int ind1=Verificare_Tara(tara);
                    cout<<tara<<"se invecineaza cu: ";
                    for (int j = 1; j <= n; j++) {
                        if (Granite[ind1][j]) {
                            cout << A[j].nume << ", ";
                            ok=1;
                        }
                    }
                    if (ok==1) cout << "Nimeni";
                    cout << endl;
                    break;
                  }
                  case 4:
                  {
                    cout<<"Ati iesit cu succes din meniu"<<endl;
                    break;
                  }
                  default:
                  {
                    cout<<"Ati selectat o optiune invalida.Incercati iar"<<endl;
                  }
                  
                }
             }
        }
        case 2:
        {
            cout << "==== LISTA TARIRI SI VECINII FIECAREIA ====" << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << A[i].nume << " se invecineaza cu: ";
                for (int j = 1; j <= n; j++)
                {
                    if (Granite[i][j])
                    {
                        cout << A[j].nume << ", ";
                        ok=1;
                    }
                }
                if (ok==1)  cout << "Nimeni.";
                cout << endl;
            }
            break;
        }

        case 3:
        {
            cout<<"Ati parasit programul cu succes."<<endl;
            break;
        }
        default:
        {
            cout<<"Ati indrodus o optiune invlida.Incercati iar.";
        }
        }
    }
}

int main()
{
    Citire_Tari();
    Vecini();

    for (int k = 1; k <= n; k++)
    {
        cout << "Tara NR: " << A[k].index << ":-" << A[k].nume << endl;
    }

    return 0;
}