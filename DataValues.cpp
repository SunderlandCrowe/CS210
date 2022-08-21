#include <iostream>
#include <vector>
#include "DataValues.h"

using namespace std;

// Default constructor
DataValues::DataValues() {
    DataValues::m_userInputs = {
        "Initial Investment Amount:  ",
                "Monthly Deposit:  ",
                "Annual Interest:  ",
                "Number of years:  "
    };
};

const vector<string>& DataValues::getUserInputs() const 
{
    return m_userInputs;
}

double DataValues::getInitialInvestment() const 
{
    return m_initInvestment;
}

double DataValues::getMonthlyDep() const
{
    return m_mDep;
}

double DataValues::getYear() const
{
    return m_aYear;
}

double DataValues::getNumYears() const
{
    return m_numYears;
}

void DataValues::setInitialInvestment(double t_initialInvestment) 
{
    m_initInvestment = t_initialInvestment;
}


void DataValues::setMonthlyDep(double t_mDep) 
{
    m_mDep = t_mDep;
}


void DataValues::setYear(double t_aYear) 
{
    m_aYear = t_aYear;
}



void DataValues::setNumYears(double t_numYears) 
{
    m_numYears = t_numYears;
}

// Print prompt header for user input
void DataValues::printHeader() 
{
    cout << string(36, '*') << endl;
    cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

// Print prompt for user
void DataValues::promptUser() 
{
    vector<double> depositInfo;
    char quit = 'a';  
    while (quit != 'q') 
    {

        try 
        {
            printHeader();
            depositInfo = storedInputs();

        }
        // Catch invalid input
        catch (invalid_argument& except) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << except.what() << endl;
        }

        // Check that depositDetails vector is full and user decides to continue
        if (depositInfo.size() == 4 && checkInput()) 
        {
            setInitialInvestment(depositInfo.at(0));
            setMonthlyDep(depositInfo.at(1));
            setYear(depositInfo.at(2));
            setNumYears(depositInfo.at(3));

            quit = 'q';
        }
    }
}

//
vector<double> DataValues::storedInputs() 
{
    vector<double> replies; 
    vector<string> prompts = getUserInputs();

    for (int i = 0; i < prompts.size(); ++i) {
        string prompt = prompts.at(i);
        double userInput;
        cout << prompt;
        cin >> userInput;

        // Check for valid user input
        if (!cin || userInput < 0.01) {
            throw invalid_argument("\n\n Letters and any super tiny numbers, especially those that are less than a cent, are not, ALLOWED \n\n");
        }

        // Add user input to replies
        replies.push_back(userInput);
    }
    return replies; // List and matches promts and responses then returns them
}

bool DataValues::checkInput()
{
    cout << "Press enter to continue . . .\n\n\n";
    return cin.get() == '\n';
}