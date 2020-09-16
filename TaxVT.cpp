#include "TaxVT.h"

TaxVT::TaxVT(double income, filing_status filing)
{
    this->income = income;
    this->filing = filing;
    this->tax_owed = get_taxes();
    this->tax_rate = tax_owed / income;
}

TaxVT::TaxVT() : TaxVT(0, single) {}

double TaxVT::schedule_X(double income)
{
    if (income > 200200)
    {
        return 12968 + ((income - 200200) * 0.0875);
    }
    else if (income > 96000)
    {
        return 5049 + ((income - 39600) * .0760);
    }
    else if (income > 75000)
    {
        return 3663 + ((income - 75000) * 0.0660);
    }
    else if (income > 39600)
    {
        return 1327 + ((income - 39600) * 0.0660);
    }
    else
    {
        return income * 0.0335;
    }
}

double TaxVT::schedule_Y1(double income)
{
    if (income > 243750)
    {
        return 14776 + ((income - 243750) * 0.0875);
    }
    else if (income > 159950)
    {
        return 8407 + ((income - 159950) * 0.0760);
    }
    else if (income > 75000)
    {
        return 2800 + ((income - 75000) * 0.0660);
    }
    else if (income > 66150)
    {
        return 2216 + ((income - 66150) * 0.0660);
    }
    else
    {
        return income * 0.0335;
    }
}

double TaxVT::schedule_Y2(double income)
{
    if (income > 121875)
    {
        return 7388 + ((income - 121875) * 0.0875);
    }
    else if (income > 79975)
    {
        return 4203 + ((income - 79975) * 0.0760);
    }
    else if (income > 75000)
    {
        return 3875 + ((income - 75000) * 0.0660);
    }
    else if (income > 33075)
    {
        return 1108 + ((income - 33075) * 0.0660);
    }
    else
    {
        return income * 0.0335;
    }
}

double TaxVT::schedule_Z(double income)
{
    if (income > 221950)
    {
        return 13372 + ((income - 221950) * 0.0875);
    }
    else if (income > 137050)
    {
        return 7320 + ((income - 13750) * 0.0760);
    }
    else if (income > 75000)
    {
        return 3224 + ((income - 75000) * 0.0660);
    }
    else if (income > 53100)
    {
        return 1779 + ((income - 53100) * 0.0660);
    }
    else {
        return income * 0.0035;
    }
}

double TaxVT::get_taxes() const
{
   switch (filing)
   {
       case single:
           return schedule_X(income);
       case married_joint:
           return schedule_Y1(income);
       case married_separate:
           return schedule_Y2(income);
       case head_of_house:
           return schedule_Z(income);
       default:
           return 0;
   }
}

double TaxVT::get_tax_rate() const
{
    return tax_rate;
}