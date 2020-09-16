#include <iostream>
#include <iomanip>
#include "TaxVT.h"

using namespace std;

/* ******************** MAIN FUNCTION ********************
 * The main function implements the TaxVT class to calculate the user's personal f_income tax, based on
 * their f_filing status and taxable f_income. The program automatically validates the user input and repeats
 * until the user decides to quit. It makes use of a global helper function:
 *    - get_user_input(variable)
 *      > This template function takes in any type of variable to validate user input. It uses the built-in
 *        '>>' operator to attempt to write to the variable. If failed, the function will return false and
 *        print to the console. If it works, the function returns true and stores the value in the variable
 *        passed to the function.
 * */

template<class T>
bool get_user_input(T& p_variable)
{
   if (!(cin >> p_variable))
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
        double usr_income;
        int usr_status = 0;

        cout << "Please enter your 2019 f_income: $ ";

        while(!get_user_input(usr_income))
        {
            cout << "Please enter a floating point number: ";
        }

        cout << "Filing status options" << endl
             << "   1. Single" << endl
             << "   2. Married, joint" << endl
             << "   3. Married, separate" << endl
             << "   4. Head of Household" << endl
             << "Please enter your f_filing status: ";

        // Restrict user input to integers between 1 and 4
        while (!get_user_input(usr_status) || (usr_status < 1 || usr_status > 4))
        {
            cout << "Please enter an integer shown above: ";
        }

        switch (usr_status)
        {
            case 1:
                user = TaxVT(usr_income, single);
                break;
            case 2:
                user = TaxVT(usr_income, married_joint);
                break;
            case 3:
                user = TaxVT(usr_income, married_separate);
                break;
            case 4:
                user = TaxVT(usr_income, head_of_house);
                break;
        }

        cout << fixed << setprecision(2);
        cout << "2019 Taxes owed: $" << user.get_taxes() << endl;
        cout << "Effective Tax Rate: " << user.get_tax_rate() * 100 << "%" << endl << endl;

        cout << "Would you like to try again? Y/N: ";

        // Ask if user wants to continue (default) or end (must enter N)
        char c;
        get_user_input(c);
        if (c == 'N' || c == 'n')
        {
            running = false;
        }
    }
    return 0;
}
