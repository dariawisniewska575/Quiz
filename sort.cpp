#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Sort
{
    string imie, ma, punktow;
    int pkt;
};

void sortowanie (Sort *&s)
{
    ifstream plik("zapis.txt");
    ofstream wyniki("wyniki.txt");
    int lp;
    plik >> lp;
    s = new Sort[lp];

    for(int i=0; i<lp; i++)
    {
        plik >> s[i].imie >> s[i].ma >> s[i].pkt >> s[i].punktow;
    }
    for(int i=0; i<lp; i++)
    {
        for(int j=1; j<lp-i; j++)
        {
            if(s[j-1].pkt<=s[j].pkt)
                swap(s[j-1], s[j]);
        }
    }
    for(int i=0; i<lp; i++)
    {
        wyniki << s[i].imie << " "<< s[i].ma << " " <<  s[i].pkt << " " << s[i].punktow << endl;
    }
}
int main()
{
    Sort *s;
    sortowanie(s);
    return 0;
}
