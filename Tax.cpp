#include "Tax.h"

Tax::Tax(int income) {
    this->income = income;
    this->taxOwed = getTaxes();
    this->taxRate = taxOwed / income;
}

// Filing singly
double Tax::getTaxes() {
    if (income > 200200) {
        return 12968 + ((income - 200200) * 8.75)
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