// Idea from : https://www.reddit.com/r/dailyprogrammer/comments/cdieag/20190715_challenge_379_easy_progressive_taxation/

#ifndef M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H
#define M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H

// Enum to keep track of the tax filing status
enum filingStatus {single, marriedJoint, marriedSeparate, headOfHouse};

/* TaxVT Class
 * This class calculates the personal income tax using VT Tax tables.
 * (https://tax.vermont.gov/sites/tax/files/documents/RateSched.pdf) */
class TaxVT {
private:
    // Taxable income for fiscal year
    double income;
    // Calculated taxes owed for the fiscal year
    double taxOwed;
    // Calculated effective tax rate
    double taxRate;
    // Taxpayer filing status
    filingStatus filing;
public:
    // Default constructor - NOTE: income cannot be changed, new instance is required
    TaxVT(double income, filingStatus filing);

    // No-arg constructor
    TaxVT();

    /* TAX TABLES for 2019 */
    // Filing as single
    static double scheduleX(double income);
    // Filing as married, jointly
    static double scheduleY1(double income);
    // Filing as married, separate
    static double scheduleY2(double income);
    // Filing as head of household
    static double scheduleZ(double income);

    // Get taxes owed for fiscal year
    double getTaxes() const;
    // Get effective tax rate calculated for fiscal year
    double getTaxRate() const;
};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
