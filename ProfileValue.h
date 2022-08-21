#pragma once
#include <vector>

using namespace std;

class ProfileValue {

public:
    ProfileValue();

    const vector<int>& getYears() const;
    const vector<double>& getYearEndBalances() const;
    const vector<double>& getEarnedInterests() const;

    void setYears(const vector<int>& years);
    void setEndBalances(const vector<double>& yearEndBalances);
    void setEarnedInterests(const vector<double>& yearEndEarnedInterests);

private:
    vector<int> years;
    vector<double> yearEndBalances;
    vector<double> earnedInterests;

};