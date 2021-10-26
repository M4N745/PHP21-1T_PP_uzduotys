#ifndef FOR_CIKLAS_H_INCLUDED
#define FOR_CIKLAS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int ciklasFor2Uzduotis(){
    cout << "Uzduotis:\n";
    cout << "Loterijos bilieto numeriai šešiaženkliai skaičiai (1-asis  000001,  kuri  atitinka skaičius1).  Laimingas laikomas toks bilietas, kurio numerio skaitmenų suma dalosi iš 13. Atspausdinkite visus laimingus bilietus ir suskaičiuokite kiek jų yra.\n\n";

    double viso = 0, check;

    //checkinti ar skaicius dalinas is 13 ir po to padauginti skaiciu ir patikrinti ar jie sutampa

    cout << viso;

    for (int i = 000001; i <= 999999; i++) {
        check = i / 13;
        if((i / 13 * 13) == i){
            cout << "Laimingas bilietas: " << i << "\n";
            viso++;
        }
    }
    cout << "\nViso laimingu bilietu: " << viso << "\n";
}


int ciklasFor3Uzduotis () {
    cout << "Uzduotis:\n";

    string choice;

    cout << "(Uzduotis labai ilga, rodyti? [T - taip, N - ne)"; cin >> choice;

    if (choice == "t" || choice == "T"){
        cout << "Mažylis, Karlsonas ir namų tvarkytoja Frekenboklabai mėgsta aviečių uogienę. Virtuvės spintelėje yra stiklainis su n šaukštelių uogienės. Visi trys smaližiai nepastebimai po vieną nueina į virtuvę ir suvalgo tam tikrą kiekį uogienės: Mažylis –2 šaukštelius, Karlsonas –5 šaukštelius, o Frekenbok 3 šaukštelius (žinoma, jei uogienės dar yra). Jų apsilankymus virtuvėje fiksuoja spintelėje esantis jutiklis. Sudarykite programą, kuri apskaičiuotų uogienės likutį, ir kiek suvalgė kiekvienas smaližius: Mažylis, Karlsonas ir Frekenbok (šaukšteliais). Mažylį žymėkime skaičiumi 1, Karlsoną –2,  o  Frekenbok –3. Pirmiausia reikia įvesti skaičių n, paskui –apsilankymų virtuvėje skaičių m, o tada –skaičius, atitinkančius virtuvėje apsilankiusius asmenis.\n\n";
    }

    const int mz = 2;
    const int fr = 3;
    const int kr = 5;

    string text;
    int maxKiekis, maxVizitu;
    string apsilankymai;

    int rezMZ = 0, rezFR = 0, rezKR = 0;



    int check = 0;

    ifstream read("./txt/forCiklas/duom.txt");

    while (getline (read, text)) {
      check++;
      if (check == 1){
        maxKiekis = atoi( text.c_str() );
      }
      if (check == 2) {
        maxVizitu = atoi( text.c_str() );
      }
      if (check == 3){
        apsilankymai = text;
      }
    }

    read.close();


    cout << "\n\nYra uogienes: " << maxKiekis << "\n";
    cout << "Numatomu apsilankymu skaicius: " << maxVizitu << "\n";
    cout << "Apsilankymai: " << apsilankymai << "\n\n";

    for (int i = 0; i <= apsilankymai.length(); i++){
        if (apsilankymai[i] == '1') { //Mazylio kodas
            if (maxKiekis >= mz) {
                rezMZ = rezMZ + mz;
                maxKiekis = maxKiekis - mz;
            }
            else {
                rezMZ = rezMZ + maxKiekis;
                maxKiekis = 0;
            }
        }
        if (apsilankymai[i] == '2'){ //Karlsono kodas
            if (maxKiekis >= kr){
                rezKR = rezKR + kr;
                maxKiekis = maxKiekis - kr;
            }
            else{
                rezKR = rezKR + maxKiekis;
                maxKiekis = 0;
            }
        }
        if (apsilankymai[i] == '3'){ //Frekenbok kodas
            if (maxKiekis >= fr) {
                rezFR = rezFR + fr;
                maxKiekis = maxKiekis - fr;
            }
            else{
                rezFR = rezFR + maxKiekis;
                maxKiekis = 0;
            }
        }
    }

    ofstream write("./txt/forCiklas/rez.txt");
    if (maxKiekis == 0) {
        write << "Uogienes neliko\n";
    }
    else {
        write << "Uogienes liko "<< maxKiekis << " saukstas (-ai / -u)\n";
    }
    write << "Mazyliui teko: " << rezMZ << "\n";
    write << "Karlsonui teko: " << rezKR << "\n";
    write << "Panelei Frekenbok teko: " << rezFR;
    write.close();


    if (maxKiekis == 0) {
        cout << "Uogienes neliko\n";
    }
    else {
        cout << "Uogienes liko "<< maxKiekis << " saukstas (-ai / -u)\n";
    }
    cout << "Mazyliui teko: " << rezMZ << "\n";
    cout << "Karlsonui teko: " << rezKR << "\n";
    cout << "Panelei Frekenbok teko: " << rezFR << "\n";
    cout << "Liko uogienes: " << maxKiekis << "\n";

}


#endif // FOR_CIKLAS_H_INCLUDED
