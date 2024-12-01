#include <iostream>
#include <string>
using namespace std;

int Granite[100][100];
int i=0,j=0;

struct tari
{
  int index;
  string nume;
}A[100];

int main()
{
    int nr_tari, nr_culori;
    string tara;
    cout<<"Da-ti un numar de tari:"<<endl;;
    cin>>nr_tari;
    for(int k=0;k<nr_tari;k++)
    {
        cout<<"Introduceti urmatoarea tara: "<<endl;
        getline(cin, tara);
        A[i].nume=tara;
        A[i].index=k+1;
        i++;
    }

    for(int k=0;k<i;k++)
    {
        cout<<"Nr: "<<A[k].index<<" Numele: "<<A[k].nume<<endl; 
    }

    
    return 0;
}