#ifndef SALYGOS_IF_UZDUOTIS_H_INCLUDED
#define SALYGOS_IF_UZDUOTIS_H_INCLUDED

#include <iostream>

using namespace std;

int IfUzduotis () {
    cout << "Uzduotis:\nDuoti du skaiciai. Didesniojo skaiciaus reiksme reikia priskirti kintamajam DID, o mazesniojo - kintamajam MAZ. Jei skaiciai lygus isveskite atitinkama pranesima.\n\n";

    int pirmas, antras, DID, MAZ;

    cout << "Iveskite pirmaji skaiciu: "; cin >> pirmas;
    cout << "Iveskite antraji skaiciu: "; cin >> antras;

    if (pirmas == antras) {
        cout << "Abu skaiciai lygus.";
    }
    else {
        if (pirmas > antras){
            DID = pirmas; MAZ = antras;
        }
        else{
            DID = antras; MAZ = pirmas;
        }

        cout << "\n\nRezultatas:\n\nDID kintamojo reiksme: " << DID << "\nMAZ kintamojo reiksme: " << MAZ << "\n\n";
    }
}



#endif // SALYGOS_IF_UZDUOTIS_H_INCLUDED
