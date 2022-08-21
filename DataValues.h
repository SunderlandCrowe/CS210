#pragma once

#include <vector>
#include <string>
using namespace std;

class DataValues {
public:
    DataValues();

    const vector<string>& getUserInputs() const;

    double getInitialInvestment() const;
    double getMonthlyDep() const;
    double getYear() const;
    double getNumYears() const;

    void setInitialInvestment(double initialInvestAmt);
    void setMonthlyDep(double monthlyDep);
    void setYear(double annualInt);
    void setNumYears(double numYears);
    void promptUser();

private:
    vector<string> m_userInputs;

    double m_initInvestment;
    double m_mDep;
    double m_aYear;
    double m_numYears;

    void printHeader();

    vector<double> storedInputs();

    bool checkInput();
};