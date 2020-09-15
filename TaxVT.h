// Idea from : https://www.reddit.com/r/dailyprogrammer/comments/cdieag/20190715_challenge_379_easy_progressive_taxation/
// 2019 Vermont State Income Tax Rates: https://tax.vermont.gov/sites/tax/files/documents/RateSched.pdf

#ifndef M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H
#define M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H

enum filingStatus {single, marriedJoint, marriedSeparate, headOfHouse};

class TaxVT {
private:
    double income;
    double taxOwed;
    double taxRate;
    filingStatus filing;
    double scheduleX() const; // Filing singly
    double scheduleY1() const; // Married filing together
    double scheduleY2() const; // Married filing separate
    double scheduleZ() const; // Head of household filing
public:
    TaxVT(double income, filingStatus filing);

    TaxVT();

    double getTaxes();

    double getTaxRate();
};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
