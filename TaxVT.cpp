#include "TaxVT.h"

TaxVT::TaxVT(double income, filingStatus filing) {
    this->income = income;
    this->filing = filing;
    this->taxOwed = getTaxes();
    this->taxRate = taxOwed / income;
}

TaxVT::TaxVT() : TaxVT(0, single) {}

// Filing singly
double TaxVT::scheduleX(double income) {
    if (income > 200200) {
        return 12968 + ((income - 200200) * 0.0875);
    } else if (income > 96000) {
        return 5049 + ((income - 39600) * .0760);
    } else if (income > 75000) {
        return 3663 + ((income - 75000) * 0.0660);
    } else if (income > 39600) {
        return 1327 + ((income - 39600) * 0.0660);
    } else {
        return income * 0.0335;
    }
}

// Filing separate, married
double TaxVT::scheduleY1(double income) {
    if (income > 121875) {
        return 7388 + ((income - 121875) * 0.0875);
    } else if (income > 79975) {
        return 4203 + ((income - 79975) * 0.0760);
    } else if (income > 75000) {
        return 3875 + ((income - 75000) * 0.0660);
    } else if (income > 33075){
        return 1108 + ((income - 33075) * 0.0660);
    } else {
        return income * 0.0335;
    }
}

// Filing together, married
double TaxVT::scheduleY2(double income) {
    return 0;
}

// Filing as head of household
double TaxVT::scheduleZ(double income) {
    return 0;
}

// Get Taxes
double TaxVT::getTaxes() {
   if (filing == single) {
       return scheduleX(income);
   }
   return 0;
}

