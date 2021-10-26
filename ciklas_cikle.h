#ifndef CIKLAS_CIKLE_H_INCLUDED
#define CIKLAS_CIKLE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>


//custom funkcija teksto redagavimui
#include "explode.h"

using namespace std;


void CiklasCikle(){
    cout << "Uzduotis:\n";

    string choice;

    cout << "(Uzduotis labai ilga, rodyti? [T - taip, N - ne)"; cin >> choice;

    if (choice == "t" || choice == "T"){
        cout << "Radiotechnikos parduotuvėje vadybininkas daro užsakymą. Tekstinio failo duom.txt pirmoje eilutėje įrašė, kelių tipų tkomponentus reikiaužsakyti. Toliau seka teilučių, kurių kiekvienoje įrašyta, kiek skirtingų vieno tipo komponentų sreikia  užsakyti  ir  po sskaičių dvejetų. Pirmasis dvejeto skaičius rodo komponentų skaičių (sveikasis skaičius) kir komponento vieneto kainą vk(realusis  skaičius). Parašykite programą, kuri tekstiniame  faile rez.txt išvestų kiekvieno tipo bendrą komponentų skaičių ir jų kainą dviejų skaitmenų po kablelio tikslumu. Vienam komponentui skiriama viena eilutė. Paskutinėje eilutėje turi būti išvestas bendras įsigytų komponentų skaičius ir jų kaina dviejų skaitmenų po kablelio tikslumu.\n\n";
    }
    cout << "\n\n";

    int kiekis = 0, i = 0, index, kFirst, kSecond, t;
    int firstPlus = 0, SecondPlus = 0;


    int FinalPlus = 0;
    string finalKiekis;
    double finalSuma = 0.00, lastSuma;

    double suma = 0.00, fSuma, sSuma = 0.00;
    string text, duom;

    ifstream read("./txt/ciklas_cikle/duom.txt");
    ofstream write("./txt/ciklas_cikle/rez.txt");

    while (getline(read, duom)) {
        if(i == 0) {t = atoi(duom.c_str());}
        i++;

        text = duom;
        auto split = explode(duom, ' ');
        index = atoi(split[0].c_str());

        if(i != 1){
            for (int a = 0; a <= index * 2; a++){

                if(atoi(split[0].c_str()) > 1){
                    if(a == 1){
                        kFirst = atoi(split[a].c_str());
                    }
                    else {
                        if ( a%2 != 0){
                            kSecond = atoi(split[a].c_str());
                        }
                    }
                    if (a == 3) {
                        kiekis = kFirst + kSecond;
                    }
                    if (a > 3 && (a % 2) != 0){
                        kiekis = kiekis + kSecond;
                    }
                }
                else {
                    kiekis = atoi(split[1].c_str());
                }

                if(atoi(split[0].c_str()) > 1){

                }
                else {
                    suma = atoi(split[2].c_str()) * atoi(split[1].c_str());
                }
            }

            finalKiekis += to_string(kiekis) +"|";


        }


        if (i != 1){
            for (int c = 0; c <= index+2; c++){
                double first, second, firstSuma, secondSuma = 0.00;

                if (index == 1){
                    finalSuma = stod(split[1].c_str()) * stod(split[2].c_str());
                }
                else {

                    int d = c++;

                    if(stod(split[d+1].c_str()) != 0.00){
                        if(c == 0){
                            first = stod(split[1].c_str());
                            second = stod(split[2].c_str());
                        }
                        else{
                            first = stod(split[d+1].c_str());
                            second = stod(split[d+2].c_str());
                        }

                        suma = first * second;

                        if (c == 0) {
                            firstSuma = suma;
                        }
                        else if (c != 0 && index > 1){
                            secondSuma = suma;
                        }
                        if(c == 1) {
                            finalSuma = firstSuma + secondSuma;
                        }
                        else if( c > 1){
                            finalSuma = finalSuma + secondSuma;
                        }
                        else if (index == 1){
                            finalSuma = firstSuma;
                        }
                    }
                }
            }
        }


        if( i != 0 && i != 1){
            cout << i-1 << "-ojo tipo komponentu reikes uzsakyti " << kiekis << ". Ju kaina " << finalSuma << "\n";
            write << i-1 << "-ojo tipo komponentu reikes uzsakyti " << kiekis << ". Ju kaina " << finalSuma << "\n";

        }

        if (i <= 1) {
            fSuma = finalSuma;
        }
        if (i > 1) {
            sSuma = finalSuma;
        }
        if (i == 1){
            lastSuma = fSuma + sSuma;
        }
        if ( i > 1){
            lastSuma = lastSuma + sSuma;
        }
    }

    read.close();

    auto kiekisForExplode = explode(finalKiekis, '|');

    for (int b = 0; b <= t-1; b++){
        if(b == 0){
            firstPlus = atoi(kiekisForExplode[0].c_str());
        }
        else {
            SecondPlus = atoi(kiekisForExplode[b].c_str());
        }
        if ( b == 1){
            FinalPlus = firstPlus + SecondPlus;

        }
        if ( b > 1) {
            FinalPlus = FinalPlus + SecondPlus;
            kiekis = FinalPlus;

        }
    }


    cout << "\nIs viso uzsakyti reikes " << kiekis << " komponentus, kuriu suma " << lastSuma << ".\n";
    write << "\nIs viso uzsakyti reikes " << kiekis << " komponentus, kuriu suma " << lastSuma << ".\n";
    write.close();
}

#endif // CIKLAS_CIKLE_H_INCLUDED
