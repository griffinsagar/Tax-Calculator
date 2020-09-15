#include "TaxVT.h"

TaxVT::TaxVT(double income, filingStatus filing) {
    this->income = income;
    this->filing = filing;
    this->taxOwed = getTaxes();
    this->taxRate = taxOwed / income;
}

TaxVT::TaxVT() : TaxVT(0, single) {}

// Filing singly
double TaxVT::scheduleX() const {
    if (income > 200200) {
        return 12968 + ((income - 200200) * 8.75);
    } else if (income > 96000) {
        return 5049 + ((income - 39600) * 7.60);
    } else if (income > 75000) {
        return 3663 + ((income - 75000) * 6.60);
    } else if (income > 39600) {
        return 1327 + ((income - 39600) * 6.60);
    } else {
        return income * 3.35;
    }
}

// Filing separate, married
double TaxVT::scheduleY1() const {}

// Filing together, married
double TaxVT::scheduleY2() const {}

// Filing as head of household
double TaxVT::scheduleZ() const {}