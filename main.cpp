#include <iostream>
#include <locale>
#include "TaxVT.h"

using namespace std;

template<class T>
bool getUserInput(T& variable) {
    while(!(cin >> variable)) {
        cout << "Invalid input.";
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    cout << endl;
}

int main() {
    bool running = true;

    while (running) {
        double usrIncome;
        int usrStatus;
        cout << "Please enter your 2019 income: $";
        getUserInput(usrIncome);

        cout << "Filing status options" << endl
             << "   1. Single" << endl
             << "   2. Married, joint" << endl
             << "   3. Married, separate" << endl
             << "   4. Head of Household" << endl
             << "Please enter your filing status: ";
        getUserInput(usrStatus);

        TaxVT user;
        switch (usrStatus) {
            case 1:
                user = TaxVT(usrIncome, single);
                break;
            case 2:
                user = TaxVT(usrIncome, marriedJoint);
                break;
            case 3:
                user = TaxVT(usrIncome, marriedSeparate);
                break;
            case 4:
                user = TaxVT(usrIncome, headOfHouse);
                break;
            default:
                running = false;
        }

    }

    return 0;
}
