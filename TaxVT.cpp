#include "TaxVT.h"

TaxVT::TaxVT(double p_income, filing_status p_filing)
{
    this->f_income = p_income;
    this->f_filing = p_filing;
    this->f_tax_owed = get_taxes();
    this->f_tax_rate = f_tax_owed / p_income;
}

TaxVT::TaxVT() : TaxVT(0, single) {}

double TaxVT::schedule_X(double p_income)
{
    if (p_income > 200200)
    {
        return 12968 + ((p_income - 200200) * 0.0875);
    }
    else if (p_income > 96000)
    {
        return 5049 + ((p_income - 39600) * .0760);
    }
    else if (p_income > 75000)
    {
        return 3663 + ((p_income - 75000) * 0.0660);
    }
    else if (p_income > 39600)
    {
        return 1327 + ((p_income - 39600) * 0.0660);
    }
    else
    {
        return p_income * 0.0335;
    }
}

double TaxVT::schedule_Y1(double p_income)
{
    if (p_income > 243750)
    {
        return 14776 + ((p_income - 243750) * 0.0875);
    }
    else if (p_income > 159950)
    {
        return 8407 + ((p_income - 159950) * 0.0760);
    }
    else if (p_income > 75000)
    {
        return 2800 + ((p_income - 75000) * 0.0660);
    }
    else if (p_income > 66150)
    {
        return 2216 + ((p_income - 66150) * 0.0660);
    }
    else
    {
        return p_income * 0.0335;
    }
}

double TaxVT::schedule_Y2(double p_income)
{
    if (p_income > 121875)
    {
        return 7388 + ((p_income - 121875) * 0.0875);
    }
    else if (p_income > 79975)
    {
        return 4203 + ((p_income - 79975) * 0.0760);
    }
    else if (p_income > 75000)
    {
        return 3875 + ((p_income - 75000) * 0.0660);
    }
    else if (p_income > 33075)
    {
        return 1108 + ((p_income - 33075) * 0.0660);
    }
    else
    {
        return p_income * 0.0335;
    }
}

double TaxVT::schedule_Z(double p_income)
{
    if (p_income > 221950)
    {
        return 13372 + ((p_income - 221950) * 0.0875);
    }
    else if (p_income > 137050)
    {
        return 7320 + ((p_income - 13750) * 0.0760);
    }
    else if (p_income > 75000)
    {
        return 3224 + ((p_income - 75000) * 0.0660);
    }
    else if (p_income > 53100)
    {
        return 1779 + ((p_income - 53100) * 0.0660);
    }
    else {
        return p_income * 0.0035;
    }
}

double TaxVT::get_taxes() const
{
   switch (f_filing)
   {
       case single:
           return schedule_X(f_income);
       case married_joint:
           return schedule_Y1(f_income);
       case married_separate:
           return schedule_Y2(f_income);
       case head_of_house:
           return schedule_Z(f_income);
       default:
           return 0;
   }
}

double TaxVT::get_tax_rate() const
{
    return f_tax_rate;
}