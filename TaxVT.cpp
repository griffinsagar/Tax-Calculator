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

// Filing jointly, married
double TaxVT::scheduleY1(double income) {
    if (income > 243750) {
        return 14776 + ((income - 243750) * 0.0875);
    } else if (income > 159950) {
        return 8407 + ((income - 159950) * 0.0760);
    } else if (income > 75000) {
        return 2800 + ((income - 75000) * 0.0660);
    } else if (income > 66150) {
        return 2216 + ((income - 66150) * 0.0660);
    } else {
        return income * 0.0335;
    }
}

// Filing separate, married
double TaxVT::scheduleY2(double income) {
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

// Filing as head of household
double TaxVT::scheduleZ(double income) {
    if (income > 221950) {
        return 13372 + ((income - 221950) * 0.0875);
    } else if (income > 137050) {
        return 7320 + ((income - 13750) * 0.0760);
    } else if (income > 75000) {
        return 3224 + ((income - 75000) * 0.0660);
    } else if (income > 53100) {
        return 1779 + ((income - 53100) * 0.0660);
    } else {
        return income * 0.0035;
    }
}

// Get Taxes
double TaxVT::getTaxes() const {
   switch (filing) {
       case single:
           return scheduleX(income);
       case marriedJoint:
           return scheduleY1(income);
       case marriedSeparate:
           return scheduleY2(income);
       case headOfHouse:
           return scheduleZ(income);
       default:
           return 0;
   }
}

