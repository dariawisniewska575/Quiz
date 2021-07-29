//autorem programu jest Daria Wisniewska
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;
struct Sort
{
    string imie, ma, punktow;
    int pkt;
};

struct Dane
{
    string imie;
};
struct Zapisywanie
{
    Dane *dane;
    int osoby;
    int maxi;
};
struct Warzywa
{
    string pyt_warzywa_nazwa, pyt_warzywa_kod, pyt_warzywa_odp, pyt_warzywa_odp_uzytkownika;
};
struct Bulki
{
    string pyt_bulki_nazwa, pyt_bulki_kod, pyt_bulki_odp, pyt_bulki_odp_uzytkownika;
};
struct Pytania
{
    string nazwa_pytania, prawidlowa_odpowiedz, odpowiedz_uzytkownika, odpa, odpb, odpc, odpd;
    Bulki *bulki;
    Warzywa *warzywa;
    string wprowadz, wprowadzona_prawidlowa, wprowadzona_uzytkownika;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int suma = 0;
};
char znak()
{
    return _getch();
}

void wczytaj_osoby(Zapisywanie &z)
{

    ifstream pliki("zapis.txt");
    if(!pliki)
        cout << "Blad otwarcia pliku";
    pliki >> z.osoby;
    z.maxi=2+z.osoby;
    z.dane= new Dane [z.maxi];
    for(int i=0; i<z.osoby; i++)
    {
        pliki >> z.dane[i].imie;
    }


}
void zapisz(Zapisywanie &z, Pytania *&p)
{
    ofstream zapisz("zapis.txt");
    zapisz << z.osoby << endl;
    for(int i=0; i<z.osoby; i++)
    {
        zapisz << z.dane[i].imie << " ma " << p[0].suma << " punktow" << endl;
    }
}
void skasuj(Zapisywanie &z)
{
    delete [] z.dane;
}
void dodaj(Zapisywanie &z, Pytania *&p)
{

    if(z.maxi==z.osoby)
    {
        zapisz(z, p);
        skasuj(z);
        wczytaj_osoby(z);
    }

    string imie;
    cout << "Podaj imie";
    cin >> imie;
    z.osoby++;
    z.dane[z.osoby-1].imie=imie;
    zapisz(z, p);
}
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
void wczytaj(Pytania *&p)
{

    fstream plik ("dane.txt");
    if(!plik)
    {
        cout << "Blad wczytania pliku";

    }

    p = new Pytania[20];
    for(int i=0; i<10; i++)
    {
        getline(plik, p[i].nazwa_pytania);
        getline(plik, p[i].odpa);
        getline(plik, p[i].odpb);
        getline(plik, p[i].odpc);
        getline(plik, p[i].odpd);
        getline(plik, p[i].prawidlowa_odpowiedz);
    }

    p[10].bulki = new Bulki[4];
    for(int i=0; i<4; i++)
    {
        getline (plik, p[10].bulki[i].pyt_bulki_nazwa);
    }
        for(int i=0; i<4; i++)
    {
        getline (plik, p[10].bulki[i].pyt_bulki_kod);
    }
        for(int i=0; i<4; i++)
    {
        getline (plik, p[10].bulki[i].pyt_bulki_odp);
    }
    p[11].warzywa = new Warzywa[5];
    for(int i=0; i<5; i++)
    {
        getline(plik, p[11].warzywa[i].pyt_warzywa_nazwa);
    }
    for(int i=0; i<5; i++)
    {
        getline(plik, p[11].warzywa[i].pyt_warzywa_kod);
    }
    for(int i=0; i<5; i++)
    {
        getline(plik, p[11].warzywa[i].pyt_warzywa_odp);
    }
    for(int i=11; i<18; i++)
    {
        getline(plik, p[i].wprowadz);
        getline(plik, p[i].wprowadzona_prawidlowa);
    }
}
void wypisz(Pytania *&p)
{
    for(int i=0; i<10; i++)
    {

        cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
        cout << "UWAGA! Uwazaj na przy wpisywaniu odpowiedzi.\nNacisniecie danego klawisza powoduje automatyczne wybranie odpowiedzi" << endl;
        cout << "Wcisnij klawisz P, aby uzyskac podpowiedz" << endl;
        cout << i+1 << ". " << p[i].nazwa_pytania << endl;
        cout << p[i].odpa << endl;
        cout << p[i].odpb << endl;
        cout << p[i].odpc << endl;
        cout << p[i].odpd << endl;
        cout << "Twoja odpowiedz to:" << endl;
        char litera = znak();
        if(litera=='p')
        {
            system("cls");
            if(p[i].prawidlowa_odpowiedz=="a")
            {
                cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                cout <<"Jesli nadal nie jestes pewny swojej odpowiedzi, wcisnij ponownie klawisz P " << endl;
                cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                cout << p[i].odpa << endl;
                cout << p[i].odpb << endl;
                cout << p[i].odpd << endl;
                cout << "Twoja odpowiedz to: ";
                cout << "Czy to dziala???";
                char litera = znak();
                system("cls");
                if(litera=='p')
                {
                    cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                    cout << "Odpowiedz zatwierdz klawiszem enter" << endl;
                    cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                    cout << p[i].odpa << endl;
                    cout << p[i].odpb << endl;
                    cout << "Twoja odpowiedz to: ";
                    cin >> p[i].odpowiedz_uzytkownika;
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1++;
                    system("cls");
                }

                else if (litera=='a')
                {
                    p[i].odpowiedz_uzytkownika="a";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;

                }
                else if (litera=='b')
                {

                    p[i].odpowiedz_uzytkownika="b";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='c')
                {

                    p[i].odpowiedz_uzytkownika="c";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='d')
                {

                    p[i].odpowiedz_uzytkownika="d";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else
                {
                    cout << "Nie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
                    znak();
                    system("cls");
                }

            }
            else if(p[i].prawidlowa_odpowiedz=="b")
            {
                cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                cout <<"Jesli nadal nie jestes pewny swojej odpowiedzi, wcisnij ponownie klawisz P " << endl;
                cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                cout << p[i].odpb << endl;
                cout << p[i].odpc << endl;
                cout << p[i].odpd << endl;
                cout << "Twoja odpowiedz to: ";
                char litera = znak();
                system("cls");
                if(litera=='p')
                {
                    cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                    cout << "Odpowiedz zatwierdz klawiszem enter" << endl;
                    cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                    cout << p[i].odpb << endl;
                    cout << p[i].odpd << endl;
                    cout << "Twoja odpowiedz to: ";
                    cin >> p[i].odpowiedz_uzytkownika;
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1++;
                    system("cls");
                }
                else if (litera=='a')
                {
                    p[i].odpowiedz_uzytkownika="a";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='b')
                {

                    p[i].odpowiedz_uzytkownika="b";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='c')
                {

                    p[i].odpowiedz_uzytkownika="c";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='d')
                {

                   p[i].odpowiedz_uzytkownika="d";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else
                {
                    cout << "Nie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
                    znak();
                    system("cls");
                }

            }
            else if(p[i].prawidlowa_odpowiedz=="c")
            {
                cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                cout <<"Jesli nadal nie jestes pewny swojej odpowiedzi, wcisnij ponownie klawisz P " << endl;
                    cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                    cout << p[i].odpa << endl;
                    cout << p[i].odpb << endl;
                    cout << p[i].odpc << endl;
                    cout << "Twoja odpowiedz to: ";
                char litera = znak();
                system("cls");
                if(litera=='p')
                {
                    cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                    cout << "Odpowiedz zatwierdz klawiszem enter" << endl;
                    cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                    cout << p[i].odpa << endl;
                    cout << p[i].odpc << endl;
                    cout << "Twoja odpowiedz to: ";
                    cin >> p[i].odpowiedz_uzytkownika;
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1++;
                    system("cls");
                }

                else if (litera=='a')
                {

                    p[i].odpowiedz_uzytkownika="a";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='b')
                {

                    p[i].odpowiedz_uzytkownika="b";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='c')
                {

                    p[i].odpowiedz_uzytkownika="c";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='d')
                {

                    p[i].odpowiedz_uzytkownika="d";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else
                {
                    cout << "Nie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
                    znak();
                    system("cls");
                }

            }
            else if(p[i].prawidlowa_odpowiedz=="d")
            {
                cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                cout <<"Jesli nadal nie jestes pewny swojej odpowiedzi, wcisnij ponownie klawisz P " << endl;
                cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                cout << p[i].odpb << endl;
                cout << p[i].odpc << endl;
                cout << p[i].odpd << endl;
                cout << "Twoja odpowiedz to: ";
                char litera = znak();
                system("cls");
                if(litera=='p')
                {
                    cout << "Dopasuj prawidlowa odpowiedz do pytania " << endl;
                    cout << i+1 << ". " << p[i].nazwa_pytania << endl;
                    cout << p[i].odpc << endl;
                    cout << p[i].odpd << endl;
                    cout << "Twoja odpowiedz to: ";
                    cin >> p[i].odpowiedz_uzytkownika;
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1++;
                    system("cls");
                }
                else if (litera=='a')
                {

                    p[i].odpowiedz_uzytkownika="a";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='b')
                {

                    p[i].odpowiedz_uzytkownika="b";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='c')
                {

                    p[i].odpowiedz_uzytkownika="c";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else if (litera=='d')
                {

                    p[i].odpowiedz_uzytkownika="d";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                        p[0].p1+=2;
                }
                else
                {
                    cout << "Nie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
                    znak();
                    system("cls");
                }

            }

        }
        else if (litera=='a')
        {
            p[i].odpowiedz_uzytkownika="a";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                p[0].p1+=3;
        }
        else if (litera=='b')
        {
            p[i].odpowiedz_uzytkownika="b";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                p[0].p1+=3;
        }
        else if (litera=='c')
        {
            p[i].odpowiedz_uzytkownika="c";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                p[0].p1+=3;
        }
        else if (litera=='d')
        {
            p[i].odpowiedz_uzytkownika="d";
                    if(p[i].odpowiedz_uzytkownika==p[i].prawidlowa_odpowiedz)
                p[0].p1+=3;
        }

        else
        {
            cout << "Nie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
            znak();
            system("cls");
        }
        system("cls");

    }
    cout << "Udalo Ci sie zdobyc " << p[0].p1 << " puntow na 30 mozliwych" << endl;
    cout << "Nacisnij dowolny klawisz, aby kontynuowac";
    znak();
    system("cls");




    cout << "Dopasuj kody" << endl;;
    for(int i=0; i<5; i++)
    {

        cout << p[11].warzywa[i].pyt_warzywa_nazwa << endl;
    }
        for(int i=0; i<5; i++)
    {
        cout << p[11].warzywa[i].pyt_warzywa_kod << endl;
    }
    cout << "Wcisnij klawisz P, aby uzyskac podpowiedz" << endl;
    cout << "UWAGA! Uzywajac podpowiedzi nie dostajesz punktow!" << endl;
    char litera;
    for(int i=0; i<5; i++)
    {

        cout << i+1 << ". ";
        litera=znak();

        if(litera=='p')
            cout << p[11].warzywa[i].pyt_warzywa_odp << endl;
        else if (litera=='a')
        {
            cout <<  "a" << endl;
            p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="a";
             if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                p[0].p3+=3;
        }
        else if (litera=='b')
        {
            cout <<  "b" << endl;
            p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="b";
             if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                p[0].p3+=3;
        }
        else if (litera=='c')
        {
            cout <<  "c" << endl;
           p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="c";
             if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                p[0].p3+=3;
        }
        else if (litera=='d')
        {
            cout <<  "d" << endl;
            p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="d";
             if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                p[0].p3+=3;
        }
        else if (litera=='e')
        {
            cout <<  "e" << endl;
            p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="e";
             if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                p[0].p3+=3;
        }
        else
        {
            cout << "\nNie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
            litera=znak();
            if(litera=='p')
            cout << p[11].warzywa[i].pyt_warzywa_odp << endl;
            else if (litera=='a')
            {
                cout <<  "a" << endl;
                p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="a";
                if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                    p[0].p3+=3;
            }
            else if (litera=='b')
            {
                cout <<  "b" << endl;
                p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="b";
                 if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                    p[0].p3+=3;
            }
            else if (litera=='c')
            {
                cout <<  "c" << endl;
               p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="c";
                 if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                    p[0].p3+=3;
            }
            else if (litera=='d')
            {
                cout <<  "d" << endl;
                p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="d";
                 if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                    p[0].p3+=3;
            }
            else if (litera=='e')
            {
                cout <<  "e" << endl;
                p[11].warzywa[i].pyt_warzywa_odp_uzytkownika="e";
                 if(p[11].warzywa[i].pyt_warzywa_odp==p[11].warzywa[i].pyt_warzywa_odp_uzytkownika)
                    p[0].p3+=3;
            }

        }
    }
    system ("cls");
    cout << "Udalo Ci sie zdobyc " << p[0].p3 << " puntow na 15 mozliwych" << endl;
    cout << "Nacisnij dowolny klawisz, aby kontynuowac";
    znak();
    system("cls");


    cout << "Dopasuj kody" << endl;
    for(int i=0; i<4; i++)
    {

        cout << p[10].bulki[i].pyt_bulki_nazwa << endl;
    }
        for(int i=0; i<4; i++)
    {
        cout << p[10].bulki[i].pyt_bulki_kod << endl;
    }
    cout << "Wcisnij klawisz P, aby uzyskac podpowiedz" << endl;
    cout << "UWAGA! Uzywajac podpowiedzi nie dostajesz punktow!" << endl;

    for(int i=0; i<4; i++)
    {
        cout << i+1 << ". ";
        char litera=znak();

        if(litera=='p')
            cout << p[10].bulki[i].pyt_bulki_odp << endl;
        else if (litera=='a')
        {
            cout <<  "a" << endl;
            p[10].bulki[i].pyt_bulki_odp_uzytkownika="a";
             if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                p[0].p2+=3;
        }
        else if (litera=='b')
        {
            cout << "b" << endl;
            p[10].bulki[i].pyt_bulki_odp_uzytkownika="b";
            if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                p[0].p2+=3;
        }
        else if (litera=='c')
        {
            cout << "c" << endl;
            p[10].bulki[i].pyt_bulki_odp_uzytkownika="c";
            if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                p[0].p2+=3;
        }
        else if (litera=='d')
        {
            cout << "d" << endl;
            p[10].bulki[i].pyt_bulki_odp_uzytkownika="d";
            if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                p[0].p2+=3;
        }

        else
        {
            cout << "\nNie ma takiej odpowiedzi! Sprobuj ponownie." << endl;
            litera=znak();
            if(litera=='p')
            cout << p[10].bulki[i].pyt_bulki_odp << endl;
            else if (litera=='a')
            {
                cout <<  "a" << endl;
                p[10].bulki[i].pyt_bulki_odp_uzytkownika="a";
                 if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                    p[0].p2+=3;
            }
            else if (litera=='b')
            {
                cout << "b" << endl;
                p[10].bulki[i].pyt_bulki_odp_uzytkownika="b";
                if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                    p[0].p2+=3;
            }
            else if (litera=='c')
            {
                cout << "c" << endl;
                p[10].bulki[i].pyt_bulki_odp_uzytkownika="c";
                if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                    p[0].p2+=3;
            }
            else if (litera=='d')
            {
                cout << "d" << endl;
                p[10].bulki[i].pyt_bulki_odp_uzytkownika="d";
                if(p[10].bulki[i].pyt_bulki_odp==p[10].bulki[i].pyt_bulki_odp_uzytkownika)
                    p[0].p2+=3;
            }

        }


    }
    system ("cls");
    cout << "Udalo Ci sie zdobyc " << p[0].p2 << " puntow na 12 mozliwych" << endl;
    cout << "Nacisnij enter, aby kontynuowac";
    znak();
    system("cls");


    cout << "Wpisz kody na klawiaturze" << endl;
     for (int i=11; i<18; i++)
     {
        cout << "Wcisnij klawisz P, aby uzyskac podpowiedz" << endl;
        cout << "UWAGA! Uzywajac podpowiedzi dostajesz punkt mniej!" << endl;
        cout << "Wcisnij klawisz G, aby uzupelnic odpowiedz" << endl;
        cout << p[i].wprowadz << endl;
        char litera=znak();
        if(litera=='p')
        {

            cout << "Pierwsza liczba kodu to: " << p[i].wprowadzona_prawidlowa[0] << endl;
            cin >> p[i].wprowadzona_uzytkownika;
            if(p[i].wprowadzona_uzytkownika==p[i].wprowadzona_prawidlowa)
                p[0].p4++;
        }
        else if(litera=='g')
        {

            cin >> p[i].wprowadzona_uzytkownika;
            if(p[i].wprowadzona_uzytkownika==p[i].wprowadzona_prawidlowa)
                p[0].p4+=2;
        }
    }

    cout << "Udalo Ci sie zdobyc " << p[0].p4 << " puntkow na 14 mozliwych" << endl;
    cout << "Nacisnij enter, aby kontynuowac";
    znak();
    system("cls");
    p[0].suma=p[0].p1+p[0].p2+p[0].p3+p[0].p4;
    cout << "To juz koniec tego quizu!\nUdalo Ci sie zdobyc " << p[0].suma << " punktow na 71 mozliwych!\n";
    cout << "Nacisnij dowolny klawisz, aby kontynuowac";
    znak();
    system("cls");

}

int main()
{
    Pytania *p;
    Zapisywanie z;
    Sort *s;
    wczytaj(p);

    cout << "Witaj w quizie, ktory sprawdzi Twoja \nznajomosc kodow na pieczywo, owoce i warzywa\n"
            "Czekaja na Ciebie 3 etapy.\n"
            "Dobrze zastanow sie nad odpowiedzia! Raz wybranej odpowiedzi nie mozna cofnac.\n"
            "Ps. Uzywaj klawiszy numerycznych po prawej stronie klawiatury, \npowinno byc latwiej ;)\n"
            "Gotowy? To zaczynamy!\nNacisnij enter, aby kontynuowac";
    znak();
    system("cls");
    wypisz(p);
    wczytaj_osoby(z);
    dodaj(z, p);
    zapisz(z, p);
    skasuj(z);
    sortowanie(s);
    cout << "Dziekuje za udzial w quizie!";
    return 0;
}
