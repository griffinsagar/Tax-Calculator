#include <iostream>
#include <iomanip>
#include "TaxVT.h"

using namespace std;

// Function to validate user input
template<class T>
bool getUserInput(T& variable)
{
   if (!(cin >> variable))
   {
        cout << "Invalid input." << endl;
        cin.clear();
        string junk;
        getline(cin, junk);
        return false;
   }
   cout << endl;
   return true;
}

int main()
{
    bool running = true;
    TaxVT user;

    cout << "----------Vermont Personal Income Tax Calculator----------" << endl;

    while (running)
    {
        double usrIncome;
        int usrStatus = 0;

        cout << "Please enter your 2019 income: $ ";

        while(!getUserInput(usrIncome))
        {
            cout << "Please enter a floating point number: ";
        }

        cout << "Filing status options" << endl
             << "   1. Single" << endl
             << "   2. Married, joint" << endl
             << "   3. Married, separate" << endl
             << "   4. Head of Household" << endl
             << "Please enter your filing status: ";

        // Restrict user input to integers between 1 and 4
        while (!getUserInput(usrStatus) || (usrStatus < 1 || usrStatus > 4))
        {
            cout << "Please enter an integer shown above: ";
        }

        switch (usrStatus)
        {
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
        }

        cout << fixed << setprecision(2);
        cout << "2019 Taxes owed: $" << user.getTaxes() << endl;
        cout << "Effective Tax Rate: " << user.getTaxRate() * 100 << "%" << endl << endl;

        cout << "Would you like to try again? Y/N: ";

        // Ask if user wants to continue (default) or end (must enter N)
        char c;
        getUserInput(c);
        if (c == 'N' || c == 'n')
        {
            running = false;
        }
    }
    return 0;
}
