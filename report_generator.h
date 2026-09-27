#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include "country_class.h"
#include "base_class.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class ReportGenerator : public Base_class {
private:
    vector<Country_class> countries;
    
    // Helper functions to do the math
    long long getTotalPopulation();
    double getAveragePopulation();
    double getMedianPopulation();
    double getStandardDeviation();
    void findExtremes(string& maxCountry, string& minCountry, 
                      string& maxContinent, string& minContinent,
                      string& maxDensity, string& maxGrowth, 
                      string& maxIncrease);

public:
    ReportGenerator(const vector<Country_class>& data);
    
    // The main function that writes the report
    void generate_report();
    
    // Override from Base_class
    void display_details() const override;
};

#endif