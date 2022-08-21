#include <string_view>
#include <iostream>
#include <iomanip>
#include "InvestmentProfiles.h"
#include "Math.h"
#include "ProfileValue.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END = "Year End Balance";
const char* YEAR_INT = "Year End Interest";

// Constructor
InvestmentProfiles::InvestmentProfiles() 
{

}

// Prints the title of the whole report
void InvestmentProfiles::printTitle() 
{
    cout << string(64, '=') << endl;
    cout << setw(8) << YEAR << setw(26) << YEAR_END << setw(27) << YEAR_INT << endl;
    cout << string(64, '-') << endl;
}

// Prints out the titles of each report without and with interest
void InvestmentProfiles::investmentReport(ProfileValue& t_without, ProfileValue& t_with)
{
    cout << "     Balance and Interest Without Additional Monthly Deposits     \n" << endl;
    annualReport(t_without);

    cout << "     Balance and Interest With Additional Monthly Deposits     \n" << endl;
    annualReport(t_with);
}

void InvestmentProfiles::annualReport(ProfileValue& data)
{
    // sets local variables
    vector<int> years = data.getYears();
    vector<double> yearEndBalances = data.getYearEndBalances();
    vector<double> yearEndEarnedInterests = data.getEarnedInterests();

    printTitle();

    // Loops ProfilesValues to list each year end balance and earned interest
    for (int i = 0; i < years.size(); ++i) 
    {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterests.at(i) << fixed << setprecision(2) << endl;
    }
    cout << endl << endl;
}

// Checks to see if the user wants to repeat the prompt
bool InvestmentProfiles::additionalSessionCheck() {
    string text;

    cout << "Press enter to test other investment profiles (press 'q' to quit)\n";
    getline(cin, text);

    if (text.empty()) 
    {
        return true;
    }
    else if (text.at(0) == 'q')
    {
        return false;
    }
}
