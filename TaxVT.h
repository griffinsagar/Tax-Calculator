// Idea from : https://www.reddit.com/r/dailyprogrammer/comments/cdieag/20190715_challenge_379_easy_progressive_taxation/

#ifndef M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H
#define M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H

// Enum to keep track of the tax filing status
enum filing_status {single, married_joint, married_separate, head_of_house};

/* TaxVT Class
 * This class calculates the personal income tax using VT Tax tables.
 * (https://tax.vermont.gov/sites/tax/files/documents/RateSched.pdf) */
class TaxVT
{
private:
    // Taxable income for fiscal year
    double income;
    // Calculated taxes owed for the fiscal year
    double tax_owed;
    // Calculated effective tax rate
    double tax_rate;
    // Taxpayer filing status
    filing_status filing;
public:
    // Default constructor - NOTE: income cannot be changed, new instance is required
    TaxVT(double income, filing_status filing);

    // No-arg constructor
    TaxVT();

    /* TAX TABLES for 2019 */
    // Filing as single
    static double schedule_X(double income);
    // Filing as married, jointly
    static double schedule_Y1(double income);
    // Filing as married, separate
    static double schedule_Y2(double income);
    // Filing as head of household
    static double schedule_Z(double income);

    // Get taxes owed for fiscal year
    double get_taxes() const;
    // Get effective tax rate calculated for fiscal year
    double get_tax_rate() const;
};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
