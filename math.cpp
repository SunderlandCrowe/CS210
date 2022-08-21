#include <iostream>
#include <vector>
#include "Math.h"
#include "ProfileValue.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

// Constructor
Math::Math() {}



ProfileValue Math::calculateYearlyTotal(DataValues& t_userInputs, bool t_monthlyDep) {
    double principal = t_userInputs.getInitialInvestment();
    double deposit = t_userInputs.getMonthlyDep();
    int interest = t_userInputs.getYear();
    int amtYears = t_userInputs.getNumYears();
    vector<int> years;
    vector<vector<double>> yearEndBals;

    ProfileValue investmentDetails;

    try {

        // reuturn years
        for (int i = 0; i < amtYears; ++i) {
            years.push_back(i + 1);
        }

        if (t_monthlyDep == false) {
            // Calculate without monthly deposit
            yearEndBals = yearlyTotal(principal , 0, interest, amtYears);
        }
        else {
            // Calculate monthly deposits
            yearEndBals = yearlyTotal(principal, deposit, interest, amtYears);
        }

        // set variables
        investmentDetails.setYears(years);
        investmentDetails.setEarnedInterests(yearEndBals.at(0));
        investmentDetails.setEndBalances(yearEndBals.at(1));

        return investmentDetails;
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }

}

//calculates both the balance and interest for each year and stores value in vector
vector<vector<double>> Math::yearlyTotal(double openAmount, double depositAmount, int t_intRate, int t_years) {
    vector<vector<double>> balanceAndInts;
    vector<double> Interest;
    vector<double> BalWithInterest;
    double newBal;
    double yearEndInt = 0;
    double precIntRate = (t_intRate / 100.00) / 12.00;
    double intTracker = 0;
    double intOnly = 0;

    for (int i = 0; i < (t_years * 12); ++i) { //calculates monthly increases
        yearEndInt += ((intTracker + openAmount) + (depositAmount * (i + 1))) * precIntRate;
        intTracker = yearEndInt;
        if (((i + 1) % 12) == 0) {
            Interest.push_back(yearEndInt - intOnly); 
            intOnly = yearEndInt;
            newBal = openAmount + (depositAmount * (i + 1)) + yearEndInt; 
            BalWithInterest.push_back(newBal); 
        }
    }

    if (newBal > MAX_AMOUNT) {
        throw runtime_error("Unable to complete calculation. Amount too large.");
    }

    balanceAndInts.push_back(Interest); // Interest
    balanceAndInts.push_back(BalWithInterest); // Interest and balance

    // Pass vectors back to fill out InvestmentInfo objects
    return balanceAndInts;
}