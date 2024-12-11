#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int Granite[100][100];
string Culori[100];
int n = 0, m = 0, nrc=0;


struct Tara
{
    int index;
    string nume;
    string culoare;
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

void Citire_Culori()
{
    cout<<"Introduceti numarul de culori cu care doriti sa lucrati:"<<endl;
    cin>>nrc;
    cout<<"Introduceti culorile dorite"<<endl;
    cin.ignore();
    for(int i=1;i<=nrc;i++)
    {
        cout<<i<<"-";
        getline(cin, Culori[i]);
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
        cout <<"\n==== MENIU ====" << endl;
        cout << "1. Selectare tara pentre a adauga vecini" << endl;
        cout << "2. Afișare tari si vecini" << endl;
        cout << "3. Iesire" << endl;
        cout << "Alegeti o optiune: " << endl;
        cin >> opt1;
        switch (opt1)
        {
        case 1:
        {
            cout << "Introduceti tara:" << endl;
            cin >> tara;
            if (Verificare_Tara(tara) == 0)
            {
                cout << "Tara introdusa gresit sau nu exista.Incercati iar." << endl;
                break;
            }
            opt2 = 0;
            while (opt2 != 4)
             {
                cout << "\n==== MENIU TARA: " << tara << " ====" << endl;
                cout << "1. Adaugare vecin tara" << endl;
                cout << "2. Ștergere vecin tara" << endl;
                cout << "3. Afisare vecini tara" << endl;
                cout << "4. Iesire" << endl;
                cout << "Alegeti o optiune: "<<endl;
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
                    cout<<vecin<<" a fost sters cu succes din lista vecinilor tarii: "<<tara<<endl;
                    break;
                  }
                  case 3:
                  {
                    ok=0;
                    int ind1=Verificare_Tara(tara);
                    cout<<tara<<" se invecineaza cu: ";
                    for (int j = 1; j <= n; j++) {
                        if (Granite[ind1][j]) {
                            cout << A[j].nume << " ";
                            ok=1;
                        }
                    }
                    if (ok==0) cout << "Nimeni";
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
             break;
        }
        case 2:
        {
            cout << "==== LISTA TARI SI VECINI ====" << endl;
            for (int i = 1; i <= n; i++)
            {
                ok=0;
                cout << A[i].nume << " se invecineaza cu: ";
                for (int j = 1; j <= n; j++)
                {
                    if (Granite[i][j])
                    {
                        cout << A[j].nume << " ";
                        ok=1;
                    }
                }
                if (ok==0)  cout << "Nimeni.";
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
            cout<<"Ati indrodus o optiune invlida.Incercati iar."<<endl;
        }
        }
    }
}

int Colorare_Tara(int index_tara, string culoare)
{
    for(int vecin=1;vecin<=n;vecin++)
    {
        if(Granite[index_tara][vecin]!=0 && A[vecin].culoare==culoare) return 0;
    }
    return 1;
}

int Colorare_Harta(int index_tara)
{
    if(A[index_tara].index>n) return 1;
    for(int i=1;i<=nrc;i++)
    {
        if(Colorare_Tara(A[index_tara].index,Culori[i])==1)
        {
            A[index_tara].culoare=Culori[i]; //segmentation
            if((index_tara + 1 <= n) && Colorare_Harta(index_tara+1)) return 1;
            A[index_tara].culoare = "";
        }
    }
    return 0;
}



int main()
{
    memset(Granite, 0, sizeof(Granite));
    Citire_Tari();
    Citire_Culori();
    Vecini();
    // Setare_Granite("Romania", "Ungaria");
    // Setare_Granite("Romania", "Bulgaria");
    // Setare_Granite("Ungaria", "Austria");
    if (Colorare_Harta(1)) {
        cout << "Colorarea hărții a fost realizată cu succes:" << endl;
        for (int i = 1; i <= n; i++) {
            cout << A[i].nume << " -> " << A[i].culoare << endl;
        }
    } else {
        cout << "Nu s-a reușit colorarea hărții." << endl;
    }
    return 0;
}