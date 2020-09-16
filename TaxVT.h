/* ******************** TaxVT CLASS ********************
 * TaxVT is a class that calculates a user's personal income tax using the VT
 * state tax tables. This class has the following fields:
 *    - income (double)
 *    - tax_owed (double)
 *    - tax_rate (double)
 *    - filing (filing_status^)
 * And the following methods:
 *    - TaxVT(income, filing)
 *       > This default constructor takes the income and filing fields, calculating the taxes owed
 *         and the effective tax rate.
 *    - TaxVT()
 *       > This no-arg constructor sets the income to 0, filing_status to 'single', calculating
 *         the taxes owed and effective tax rate.
 *    - get_taxes()
 *       > This function is used by the constructor to calculate tax using income and filing status.
 *         It makes use of the static helper functions to perform the calculations. It returns a
 *         double value.
 *    - get_tax_rate()
 *       > This function is used by the constructor to calculate the effective tax rate for the user. It
 *         returns a percentage as a double (between 0 and 1).
 *    - schedule_X(), schedule_Y1(), schedule_Y2(), schedule_Z()
 *       > These helper functions correspond to the tax brackets, and are used to quickly calculate
 *         tax and return the value as a double.
 * There is also a helper enum used:
 *    - filing_status
 *      > This enum is used to restrict the filing status to one of the four options: single (Schedule X),
 *        married_joint (Schedule Y1), married_separate (Schedule Y2), and head_of_house (Schedule Z).
 *
 * The idea for this class came from: https://www.reddit.com/r/dailyprogrammer/comments/cdieag/20190715_challenge_379_easy_progressive_taxation/
 * */

#ifndef M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H
#define M1OEP_STYLE_ERRORS_GSAGAR_TAXVT_H

enum filing_status {single, married_joint, married_separate, head_of_house};

class TaxVT
{
private:
    double income;
    double tax_owed;
    double tax_rate;
    filing_status filing;
public:
    TaxVT(double income, filing_status filing);
    TaxVT();

    static double schedule_X(double income);
    static double schedule_Y1(double income);
    static double schedule_Y2(double income);
    static double schedule_Z(double income);

    double get_taxes() const;
    double get_tax_rate() const;
};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
