#ifndef DO_WHILE_H_INCLUDED
#define DO_WHILE_H_INCLUDED

#include <iostream>
#include <string>
#include "math.h"

using namespace std;

void do_while_uzduotis() {
    cout << "Uzduotis:\n";

    string choice;

    cout << "(Uzduotis labai ilga, rodyti? [T - taip, N - ne)"; cin >> choice;
    if (choice == "t" || choice == "T"){
        cout << "Programuotojui moka a litų atlyginimą. Darbdavys pažadėjo kiekvieną mėnesį padidinti atlyginimą x litų, parašykite programą (būtinai naudodami ciklą while), kuri surastų:\n\n";

        cout << "* koks atlyginimas bus po metų;\n";
        cout << "* koks atlyginimas bus po n mėnesių;\n";
        cout << "* po kiek mėnesių jo atlyginimas bus daugiau nei dvigubai didesnis;\n";
        cout << "* po kiek mėnesių jo atlyginimas bus nemažesnis už b litų;\n";
    }

    int n, i = 0, ii, check = 0;
    double a, x, b, aa, xx, bb, cc = 0.00;

    cout << "Programuotojas uzdirba: "; cin >> a;
    cout << "Programuotojui pazadeta padidinti atlyginima kiekviena menesi: "; cin >> x;

    cout << "Po kiek menesiu, norite patikrinti atlyginima? "; cin >> n;
    cout << "Iveskite b suma: "; cin >> b;
    cout << "\n-------------------------------------------------\n\n";

    //kokia alga bus po metu:
    aa = a;
    xx = x;
    do {
        aa = aa + xx;
        i++;
        if (i == 12) {
            cout << "Alga po metu: " << aa << "\n";
            aa = a;
            xx = x;
        }
    }
    while ( i != 12);
    // ------

    //kokia alga bus po n men:
    ii = n;
    do {
        aa = aa + xx;
        ii--;
        if (ii == 0) {
            cout << "Alga po " << n << " men.  bus: " << aa << "\n";
            aa = a;
        }
    }
    while (ii != 0);
    // -----

    // po kiek men alga bus dvigubai didesne:
    do {
        aa = aa + xx;
        cc = aa / 2;

        check++;

        if (cc > a) {
            cout << "Po " << check << " men, alga bus dvigubai didesne\n";
            aa = a;
            check = 0;
        }
    }
    while (cc <= a);
    // ------

    do {
        aa = aa + xx;
        check++;

        if (aa > b) {
            cout << "Po " << check << " men. alga bus ne mazesne uz " << b << " litu.\n";
        }

    }
    while (aa < b + 1);
}

#endif // DO_WHILE_H_INCLUDED
