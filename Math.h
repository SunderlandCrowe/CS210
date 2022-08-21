#pragma once

#include <vector>
#include "DataValues.h"
#include "ProfileValue.h"

using namespace std;

class Math {

public:
    Math();
    ProfileValue calculateYearlyTotal(DataValues& t_data, bool t_monthlyDep = false);

private:
    vector<vector<double>> yearlyTotal(double t_openAmount, double t_depositAmount, int t_intRate, int t_years);
};

