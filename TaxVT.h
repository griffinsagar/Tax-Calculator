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
public:
    TaxVT(double income, filingStatus filing);

    TaxVT();

    static double scheduleX(double income); // Filing singly
    static double scheduleY1(double income); // Married filing together
    static double scheduleY2(double income); // Married filing separate
    static double scheduleZ(double income); // Head of household filing

    double getTaxes() const;

};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
