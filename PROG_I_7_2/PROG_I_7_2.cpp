#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct fordulo {
    int lott, kapott;
    string nev1, nev2;
};

int main()
{
    int i, j, db = 0, nyert = 0;
    fordulo A[8];

    ifstream be("merkozes.txt"); //Adat file megnyitása
    //File megnyitasa es a megnyitas ellenorzese
    if (be.fail()) {
        cout << "Hiba a file megnyitasa soran!" << endl;
        system("pause");
        exit(1);
    }
    //adatok olvasása a megadott hosszig vagy a file tényleges végéig
    for ( i = 0; i < 8 && !be.eof(); i++)
    {
        be >> A[i].lott;
        be >> A[i].kapott;
        be >> A[i].nev1;
        be >> A[i].nev2;
        db++;
        cout << A[i].lott << " "
            << A[i].kapott << " "
            << A[i].nev1 << " "
            << A[i].nev2 << endl;

    }

    cout << "\nA forduloban " << db << " merkozest jatszottak!" 
        << endl;
    be.close();

    //Mennyi csapat nyert otthon?
    for ( i = 0; i < db; i++)
    {
        if (A[i].lott > A[i].kapott) nyert++;
    }
    cout << nyert << " csapat gyozott az otthonaban!" << endl;
    //Volt e dontetlen
    i = 0;
    while (i < db && A[i].lott != A[i].kapott) 
    { 
        i++;
    }
    if (i < db) cout << "\nVolt dontetlen merkozes!" << endl;
    else cout << "\nNem volt dontetlen merkozes" << endl;

    //Mennyi golt lott az Eger
    i = 0;
    while (i < db && !(A[i].nev1 == "eger" || A[i].nev2 == "eger"))
        i++;
    if (A[i].nev1 == "eger")
        cout << endl << A[i].lott << " golt lott az eger " << endl;

    system("pause");

}   
