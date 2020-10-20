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

    /* Schedule X - Filing Singly
     * Requires: income (double)
     * Returns: Calculated income tax according to tax bracket
     * */
    static double scheduleX(double income);
    /* Schedule Y-1 - Filing Jointly, Married
     * Requires: income (double)
     * Returns: Calculated income tax according to tax bracket
     * */
    static double scheduleY1(double income);
    /* Schedule Y-2 - Filing Separate, Married
     * Requires: income (double)
     * Returns: Calculated income tax according to tax bracket
     * */
    static double scheduleY2(double income);
    /* Schedule Z - Filing as Head of Household
     * Requires: income (double)
     * Returns: Calculated income tax according to tax bracket
     * */
    static double scheduleZ(double income);

    /* Uses the tax bracket functions and filing status to calculate taxes.
     * Returns: Calculated income tax according to tax bracket */
    double getTaxes() const;
    /* Finds the effective tax rate based on income tax and taxable income from this
     * fiscal year.
     * Returns: Calculated percentage (btw. 0 and 1)
     * */
    double getTaxRate() const;
};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
