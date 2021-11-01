#ifndef WHILE_CIKLAS_H_INCLUDED
#define WHILE_CIKLAS_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

void WhileCiklo1Uzduotis(){
    cout << "Uzduotis:\n";
    cout << "Įvedamas bet koks skaičius. Parašyti programą, kuri apskaičiuotų įvesto skaičiaus skaitmenų didesnių už 3 ir mažesnių už 9 bet nelygių 5 sandaugą.Apskaičiuokite, kiek tokių skaičių yra.\n\n";

    int number, num, each, left = 0, check = 0, first = 1, second, last;
    string leftNums;

    cout << "Iveskite skaiciu: "; cin >> number;

    num = number;

    while (number != 0) {
        check++;

        each = number % 10;

        if (each > 3 && each < 9 && each != 5) {
            left = left * 10;
            left = left + each;

            if (check <= 1 && left > 0) {
                first = left;
            }
            else {
                second = each;
            }

            if(check == 2) {
                last = first * second;
            }
            if (check > 2) {
                last = last * second;
            }

        }
        else {
            second = 1;
        }

        number /= 10;
    }
    leftNums = to_string(left);

    cout << "Skaiciaus " << num << " skaitmenu, didesniu uz 3, mazesniu uz 9 ir nelygiu 5 sandauga: " << last << "\n";
    cout << "Viso skaitmenu, didesniu uz 3, mazesniu uz 9 ir nelygiu 5 yra: " << leftNums.length() << "\n";
}

void WhileCiklo2Uzduotis() {
    cout << "Uzduotis:\n";
    cout << "Duotas natūralusis skaičius N. Skaitmenys numeruojami iš dešinės į kairę. Raskite didžiausią skaitmenį ir nustatykite jo numerį (jei skaitmuo kartojasi, tai pasirenkame tą skaitmenį kurio eilės numeris mažesnis).\n\n";

    int N, rNum = 0, r, didz = 0, nr = 1, check = 0;

    cout << nr<<"\nIveskite skaiciu: "; cin >> N;


    while(N != 0) {
        check++;

        r = N%10;
        rNum = rNum*10 + r;
        N /= 10;

        if (r > didz) {
            didz = r;
            nr = check;
        }
    }

    cout << "Didziausias skaicius: " << didz << "\n";
    cout << "Skaiciaus eiles Nr: " << nr << "\n\n";

}

#endif // WHILE_CIKLAS_H_INCLUDED
