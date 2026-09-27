#include "continent_analysis.h"
#include <algorithm>

// Constructor: save the data
Continent_analysis::Continent_analysis(const vector<Country_class>& data)
    : countries(data) {}

// ---------------------------------------------------------------
// Helper: linear search inside groups (same idea as the rest of
// the project where std::map is not used)
// ---------------------------------------------------------------
int Continent_analysis::findContinentIndex(const string& name) const {
    for (size_t i = 0; i < groups.size(); i++) {
        if (groups[i].name == name) {
            return (int)i;
        }
    }
    return -1;
}

// ---------------------------------------------------------------
// Helper: sort continents alphabetically
// ---------------------------------------------------------------
void Continent_analysis::sortAlphabetically() {
    sort(groups.begin(), groups.end(),
        [] (const ContinentStats& a, const ContinentStats& b) {
            return a.name < b.name;
        });
}

// ---------------------------------------------------------------
// Helper: print a single continent row
// ---------------------------------------------------------------
void Continent_analysis::printOneContinent(const ContinentStats& s) const {
    if (s.countryCount == 0) return;

    double avgPop     = (double)s.totalPop     / s.countryCount;
    double avgDensity = s.totalDensity         / s.countryCount;
    double avgGrowth  = s.totalGrowth          / s.countryCount;

    cout << left  << setw(20) << s.name
         << right << setw(12) << s.countryCount
         << setw(18) << s.totalPop
         << setw(18) << fixed << setprecision(0) << avgPop
         << setw(15) << fixed << setprecision(2) << avgDensity
         << setw(15) << fixed << setprecision(2) << avgGrowth << "%"
         << endl;
}

// ---------------------------------------------------------------
// Main function: group + calculate + print
// ---------------------------------------------------------------
void Continent_analysis::generate_report() {

    groups.clear();

    // ---------- PHASE 1: GROUPING & ACCUMULATING ----------
    for (size_t i = 0; i < countries.size(); i++) {
        const string& currentContinent = countries[i].get_continent();

        int idx = findContinentIndex(currentContinent);

        if (idx == -1) {
            // Brand-new continent, create a fresh notebook entry
            ContinentStats newGroup;
            newGroup.name         = currentContinent;
            newGroup.countryCount = 1;
            newGroup.totalPop     = countries[i].get_population_2023();
            newGroup.totalDensity = countries[i].get_population_density();
            newGroup.totalGrowth  = countries[i].get_growth_rate();

            groups.push_back(newGroup);
        }
        else {
            // Existing continent: accumulate
            groups[idx].countryCount++;
            groups[idx].totalPop     += countries[i].get_population_2023();
            groups[idx].totalDensity += countries[i].get_population_density();
            groups[idx].totalGrowth  += countries[i].get_growth_rate();
        }
    }

    // ---------- PHASE 2: ALPHABETICAL SORT ----------
    sortAlphabetically();

    // ---------- PHASE 3: PRINT TABLE ----------
    cout << "\n=========================== CONTINENT ANALYSIS ===========================\n";
    cout << left  << setw(20) << "Continent"
         << right << setw(12) << "Countries"
         << setw(18) << "Total Pop."
         << setw(18) << "Avg Pop."
         << setw(15) << "Avg Density"
         << setw(15) << "Avg Growth"
         << endl;
    cout << string(98, '-') << endl;

    for (size_t i = 0; i < groups.size(); i++) {
        printOneContinent(groups[i]);
    }

    cout << string(98, '-') << endl;

    // ---------- PHASE 4: WORLD SUMMARY ----------
    long long grandPop     = 0;
    int       totalCountries = 0;

    for (size_t i = 0; i < groups.size(); i++) {
        grandPop       += groups[i].totalPop;
        totalCountries += groups[i].countryCount;
    }

    cout << "Total continents analysed : " << groups.size()   << endl;
    cout << "Total countries analysed  : " << totalCountries  << endl;
    cout << "Total world population    : " << grandPop        << endl;
    cout << "==========================================================================\n";
}

// ---------------------------------------------------------------
// Override from Base_class
// ---------------------------------------------------------------
void Continent_analysis::display_details() const {
    cout << "Continent analysis engine ready with "
         << countries.size() << " countries loaded." << endl;
}