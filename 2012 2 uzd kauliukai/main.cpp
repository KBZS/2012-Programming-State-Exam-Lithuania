#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct diev
{
    string vard;
    int taskai=0;
};

void nuskaitymas();
void skaiciavimai();

int n, k;


diev D[1000];

int main()
{
    nuskaitymas();
    skaiciavimai();
    return 0;
}

void nuskaitymas() // skaitau is failo
{
    char eil[10];
    int temp=0;
    ifstream fd("U2.txt");
    fd >> n >> k;
    fd.ignore();
    if(n >= 2 && n <= 50 && k >= 1 && k <= 10)
    {
        for(int i=0; i<n; i++)
        {
            fd.get(eil, 10);
            D[i].vard = eil;
            fd.ignore();
            for(int j=0; j<k; j++)
            {
                fd >> temp;
                if(temp%2==0)
                {
                    D[i].taskai = temp + D[i].taskai;
                }
                else
                {
                    D[i].taskai = D[i].taskai - temp;
                }
            }
            fd.ignore();
        }
    fd.close();
    }
}
void skaiciavimai() // skaiciuoju ir isvedu rezultatus
{
    int maxt=0;
    int nr;
    ofstream fr("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        if(D[i].taskai > maxt)
        {
            maxt = D[i].taskai;
            nr = i;
        }
    }
    fr << D[nr].vard << D[nr].taskai << endl;
    fr.close();
}
