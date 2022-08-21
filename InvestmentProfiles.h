#pragma once
#include <vector>
#include "DataValues.h"
#include "Math.h"
#include "ProfileValue.h"

using namespace std;

class InvestmentProfiles {
public:
    InvestmentProfiles();

    void investmentReport(ProfileValue& t_without, ProfileValue& t_with);

    bool additionalSessionCheck();

private:
    void printTitle();
    void annualReport(ProfileValue& t_data);

};