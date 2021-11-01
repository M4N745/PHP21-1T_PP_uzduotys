#ifndef MASYVAI_H_INCLUDED
#define MASYVAI_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "explode.h"

using namespace std;

void Masyvai_Is_Skirtingu_Eiluciu (){
    cout << "Uzduotis:\n";

    string choice;

    cout << "(Uzduotis labai ilga, rodyti? [T - taip, N - ne)"; cin >> choice;
    if (choice == "t" || choice == "T"){
        cout << "Tekstinėje byloje pirmoje eilutėje yra išvardinti masyvo A elementai, o antroje - masyvo B elementai. Masyve A ir masyve B elementų yra po vienodai. Nuskaityti šiuos masyvus, ir išvesti juos į rezultatų bylą. Sukurti naują masyvą C, kuris gaunamas iš masyvo A ir B atitinkamų narių sumos, prieš tai masyvą A surikiavus mažėjimo tvarka, o masyvą B –didėjimo.\n";
        cout << "Rezultatų byloje turi būti atspausdinti surikiuoti masyvai A ir B, ir masyvas C.";
    }
    cout << "\n\n\n\n";

    ifstream read("./txt/masyvai_is_skirtingu_eiluciu/duom.txt");
    ofstream write("./txt/masyvai_is_skirtingu_eiluciu/rez.txt");

    string duom;
    int i = 0;
    int A[5], B[5], C[5];

    while(getline(read, duom)){
        auto split = explode(duom, ' ');

        if (i == 0){
            for (int ii = 0; ii <= 4; ii++){
                A[ii] = atoi(split[ii].c_str());

                if( ii == 4){
                    int n = sizeof(A)/sizeof(A[0]);
                    sort(A, A + n, greater<int>());
                }
            }
        }
        else {
            for (int ii = 0; ii <= 4; ii++){
                B[ii] = atoi(split[ii].c_str());

                if (ii == 4){
                    int n = sizeof(B)/sizeof(B[0]);
                    sort(B, B + n);

                }
            }
        }
        i++;
    }
    read.close();

    for (int ii = 0; ii <= 4; ii++){
        C[ii] = A[ii] + B[ii];
    }

    //A masyvo irasymas:
    write << "A masyvas: ";
    for (int ii = 0; ii <= 4; ii++){
        write << A[ii] << " ";
    }
    write << "\n";
    //B masyvo irasymas:
    write << "B masyvas: ";
    for (int ii = 0; ii <= 4; ii++){
        write << B[ii] << " ";
    }
    write << "\n";
    //C masyvo irasymas:
    write << "C masyvas: ";
    for (int ii = 0; ii <= 4; ii++){
        write << C[ii] << " ";
    }
    write.close();


    cout << "A[0] (" << A[0] << ") + B[0] (" << B[0] << ") = C[0] (" << C[0] << ")\n";
    cout << "A[1] (" << A[1] << ") + B[1] (" << B[1] << ") = C[1] (" << C[1] << ")\n";
    cout << "A[2] (" << A[2] << ") + B[2] (" << B[2] << ") = C[2] (" << C[2] << ")\n";
    cout << "A[3] (" << A[3] << ") + B[3] (" << B[3] << ") = C[3] (" << C[3] << ")\n";
    cout << "A[4] (" << A[4] << ") + B[4] (" << B[4] << ") = C[4] (" << C[4] << ")\n";

}

#endif // MASYVAI_H_INCLUDED
