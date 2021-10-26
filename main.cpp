#include <iostream>

//UZDUOTYS:
#include "salygos_if_uzduotis.h"
#include "FOR_ciklas.h"
#include "while_ciklas.h"
#include "ciklas_cikle.h"

using namespace std;

int main()
{
    cout << "[1] - IF salygos uzduotis\n";
    cout << "[2] - For ciklo pirma uzduotis\n";
    cout << "[3] - For ciklo antra uzduotis\n";
    cout << "[4] - While ciklo pirma uzduotis\n";
    cout << "[5] - While ciklo antra uzduotis\n";
    cout << "[6] - Ciklas cikle\n";

    int select;

    cout << "\n\nPasirinkite uzduoti: "; cin >> select;

    switch (select){
        case 1:
            IfUzduotis();
            break;
        case 2:
            ciklasFor2Uzduotis();
            break;
        case 3:
            ciklasFor3Uzduotis();
            break;
        case 4:
            WhileCiklo1Uzduotis();
            break;
        case 5:
            WhileCiklo2Uzduotis();
            break;
        case 6:
            CiklasCikle();
            break;
        default:
            cout << "\nNetinkamas uzduoties numeris.\n\n";
    }
    return 0;
}
