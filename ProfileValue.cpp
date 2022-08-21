#include <vector>
#include "ProfileValue.h"

using namespace std;

ProfileValue:: ProfileValue() {}

const vector<int>& ProfileValue::getYears() const 
{
    return years;
}

const vector<double>& ProfileValue::getYearEndBalances() const
{
    return yearEndBalances;
}

const vector<double>& ProfileValue::getEarnedInterests() const
{
    return earnedInterests;
}

void ProfileValue::setYears(const vector<int>& t_years)
{
    years = t_years;
}

void ProfileValue::setEndBalances(const vector<double>& t_yearEndBalances) 
{
    yearEndBalances = t_yearEndBalances;
}

void ProfileValue::setEarnedInterests(const vector<double>& t_yearEndEarnedInterests) 
{
    earnedInterests = t_yearEndEarnedInterests;
}