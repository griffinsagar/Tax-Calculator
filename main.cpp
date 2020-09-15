#include <iostream>
#include "TaxVT.h"

using namespace std;

int main() {
    TaxVT griffin(75000, single);

    cout << "2019 Taxes owed: " << griffin.getTaxes() << endl;

    cout << "Effective tax rate: " << griffin.getTaxRate() << endl;

    return 0;
}
