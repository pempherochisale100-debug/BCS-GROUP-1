#ifndef CONTINENT_ANALYSIS_H
#define CONTINENT_ANALYSIS_H

#include "country_class.h"
#include "base_class.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// This is our "notebook" for one continent
struct ContinentStats {
    string    name;              // e.g. "Asia"
    int       countryCount = 0;  // How many countries
    long long totalPop     = 0;  // Sum of 2023 populations
    double    totalDensity = 0;  // Sum of densities
    double    totalGrowth  = 0;  // Sum of growth rates
};

class Continent_analysis : public Base_class {
private:
    vector<Country_class>  countries; // The big box of Legos
    vector<ContinentStats> groups;    // Our smaller piles

    // Helper: return index of continent in groups, or -1 if new
    int  findContinentIndex(const string& name) const;

    // Helper: sort groups alphabetically by continent name
    void sortAlphabetically();

    // Helper: print one continent row
    void printOneContinent(const ContinentStats& s) const;

public:
    // Constructor (receives the data from main.cpp)
    Continent_analysis(const vector<Country_class>& data);

    // The main function that does all the work
    void generate_report();

    // Override from Base_class
    void display_details() const override;
};

#endif