#include "TaxVT.cpp"
#include <iostream>

using namespace std;

int main() {
    TaxVT griffin(10000);

    cout << "2019 Taxes owed: " << griffin.getTaxes();

    return 0;
}
