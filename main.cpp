#include <string>
#include <iostream>
#include "DataValues.h"
#include "Math.h"
#include "InvestmentProfiles.h"
#include "ProfileValue.h"

using namespace std;

void startApp() {
    bool restart = true;

    try {
        do {
            // Get user input
            DataValues userData;
            userData.promptUser();

            Math calculations;
            ProfileValue acctWithNoMonthlyDep = calculations.calculateYearlyTotal(userData);
            ProfileValue acctWithMonthlyDep = calculations.calculateYearlyTotal(userData, true);

            InvestmentProfiles balanceAndInterestReport;
            balanceAndInterestReport.investmentReport(acctWithNoMonthlyDep, acctWithMonthlyDep);

            // ask to continue or quit
            restart = balanceAndInterestReport.additionalSessionCheck();
        } while (restart);
    }
    catch (runtime_error& rule) {
        cout << "Oops! Something went wrong. Exception: " << rule.what() << endl;
    }
}

int main() {

    startApp();

    return 0;
}