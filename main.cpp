#include <iostream>
#include "TaxVT.h"

using namespace std;

int main() {
    TaxVT griffin(75000, single);

    cout << "2019 Taxes owed: " << griffin.getTaxes();

    return 0;
}
