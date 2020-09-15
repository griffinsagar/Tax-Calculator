//
// Created by Griffin on 9/14/20.
//

#ifndef M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
#define M1OEP_STYLE_ERRORS_GSAGAR_TAX_H


class Tax {
private:
    int income;
    double taxOwed;
    double taxRate;
public:
    Tax(int income);

    Tax() : Tax(income = 0) {}

    double getTaxes();

    double getTaxRate();
};


#endif //M1OEP_STYLE_ERRORS_GSAGAR_TAX_H
