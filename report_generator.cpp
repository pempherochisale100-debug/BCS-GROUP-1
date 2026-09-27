#include "report_generator.h"
#include <iostream>
#include <iomanip>
#include <cmath>    // Needed for sqrt()
#include <algorithm> // Needed for sort()

ReportGenerator::ReportGenerator(const vector<Country_class>& data) 
    : countries(data) {}

// --- HELPER MATH FUNCTIONS ---

long long ReportGenerator::getTotalPopulation() {
    long long total = 0;
    for (size_t i = 0; i < countries.size(); i++) {
        total += countries[i].get_population_2023();
    }
    return total;
}

double ReportGenerator::getAveragePopulation() {
    if (countries.empty()) return 0.0;
    return (double)getTotalPopulation() / countries.size();
}

double ReportGenerator::getMedianPopulation() {
    if (countries.empty()) return 0.0;
    
    // 1. Make a copy and sort it
    vector<Country_class> sorted = countries;
    sort(sorted.begin(), sorted.end(), 
         [](const Country_class& a, const Country_class& b) {
             return a.get_population_2023() < b.get_population_2023();
         });
    
    // 2. Find the middle
    size_t size = sorted.size();
    if (size % 2 != 0) {
        return sorted[size / 2].get_population_2023();
    } else {
        long long mid1 = sorted[(size / 2) - 1].get_population_2023();
        long long mid2 = sorted[size / 2].get_population_2023();
        return (mid1 + mid2) / 2.0;
    }
}

double ReportGenerator::getStandardDeviation() {
    if (countries.empty()) return 0.0;
    
    double mean = getAveragePopulation();
    double sumSquaredDiff = 0.0;
    
    for (size_t i = 0; i < countries.size(); i++) {
        double diff = countries[i].get_population_2023() - mean;
        sumSquaredDiff += diff * diff;
    }
    
    return sqrt(sumSquaredDiff / countries.size());
}

// --- HELPER FUNCTION TO FIND EXTREMES (Most/Least) ---

void ReportGenerator::findExtremes(string& maxCountry, string& minCountry, 
                                  string& maxContinent, string& minContinent,
                                  string& maxDensity, string& maxGrowth, 
                                  string& maxIncrease) {
    if (countries.empty()) return;

    // Initialize with the first country
    maxCountry = minCountry = countries[0].get_name();
    long long maxPop = countries[0].get_population_2023();
    long long minPop = countries[0].get_population_2023();
    
    maxDensity = countries[0].get_name();
    double highestDensity = countries[0].get_population_density();
    
    maxGrowth = countries[0].get_name();
    double highestGrowth = countries[0].get_growth_rate();
    
    maxIncrease = countries[0].get_name();
    long long largestIncrease = countries[0].get_population_2023() - countries[0].get_population_1970();

    // Loop through everyone else
    for (size_t i = 1; i < countries.size(); i++) {
        // Most/Least Populated Country
        if (countries[i].get_population_2023() > maxPop) {
            maxPop = countries[i].get_population_2023();
            maxCountry = countries[i].get_name();
        }
        if (countries[i].get_population_2023() < minPop) {
            minPop = countries[i].get_population_2023();
            minCountry = countries[i].get_name();
        }
        
        // Highest Density
        if (countries[i].get_population_density() > highestDensity) {
            highestDensity = countries[i].get_population_density();
            maxDensity = countries[i].get_name();
        }
        
        // Highest Growth Rate
        if (countries[i].get_growth_rate() > highestGrowth) {
            highestGrowth = countries[i].get_growth_rate();
            maxGrowth = countries[i].get_name();
        }
        
        // Largest Increase since 1970
        long long increase = countries[i].get_population_2023() - countries[i].get_population_1970();
        if (increase > largestIncrease) {
            largestIncrease = increase;
            maxIncrease = countries[i].get_name();
        }
    }
    
    // For Continents, we need to group them quickly
    // (A simple way without using a map)
    string continents[10];
    long long contPops[10] = {0};
    int contCount = 0;
    
    for (size_t i = 0; i < countries.size(); i++) {
        string cName = countries[i].get_continent();
        bool found = false;
        for (int j = 0; j < contCount; j++) {
            if (continents[j] == cName) {
                contPops[j] += countries[i].get_population_2023();
                found = true;
                break;
            }
        }
        if (!found && contCount < 10) {
            continents[contCount] = cName;
            contPops[contCount] = countries[i].get_population_2023();
            contCount++;
        }
    }
    
    // Find max/min continent
    maxContinent = continents[0];
    minContinent = continents[0];
    long long maxContPop = contPops[0];
    long long minContPop = contPops[0];
    
    for (int i = 1; i < contCount; i++) {
        if (contPops[i] > maxContPop) {
            maxContPop = contPops[i];
            maxContinent = continents[i];
        }
        if (contPops[i] < minContPop) {
            minContPop = contPops[i];
            minContinent = continents[i];
        }
    }
}

// --- THE MAIN REPORT GENERATOR ---

void ReportGenerator::generate_report() {
    // 1. Open the file
    ofstream out_file("population_analysis_report.txt");
    
    if (!out_file.is_open()) {
        cout << "ERROR: Could not create the report file." << endl;
        return;
    }
    
    // 2. Do the math
    long long totalPop = getTotalPopulation();
    double avgPop = getAveragePopulation();
    double medianPop = getMedianPopulation();
    double stdDev = getStandardDeviation();
    
    string maxCountry, minCountry, maxContinent, minContinent;
    string maxDensity, maxGrowth, maxIncrease;
    findExtremes(maxCountry, minCountry, maxContinent, minContinent,
                 maxDensity, maxGrowth, maxIncrease);
    
    // 3. Write to the file
    out_file << "====================================================\n";
    out_file << "        POPULATION ANALYSIS REPORT\n";
    out_file << "====================================================\n\n";
    
    out_file << "--- GENERAL STATISTICS ---\n";
    out_file << "Total Countries Analysed : " << countries.size() << "\n";
    out_file << "Total World Population   : " << totalPop << "\n";
    out_file << "Average Population       : " << fixed << setprecision(0) << avgPop << "\n";
    out_file << "Median Population        : " << fixed << setprecision(0) << medianPop << "\n";
    out_file << "Standard Deviation       : " << fixed << setprecision(0) << stdDev << "\n\n";
    
    out_file << "--- EXTREME VALUES ---\n";
    out_file << "Most Populated Country   : " << maxCountry << "\n";
    out_file << "Least Populated Country  : " << minCountry << "\n";
    out_file << "Most Populated Continent : " << maxContinent << "\n";
    out_file << "Least Populated Continent: " << minContinent << "\n";
    out_file << "Highest Population Density: " << maxDensity << "\n";
    out_file << "Highest Growth Rate      : " << maxGrowth << "\n";
    out_file << "Largest Increase since 1970: " << maxIncrease << "\n\n";
    
    out_file << "--- DENSITY GROUPS ---\n";
    int low = 0, med = 0, high = 0;
    for (size_t i = 0; i < countries.size(); i++) {
        double d = countries[i].get_population_density();
        if (d < 100) low++;
        else if (d < 500) med++;
        else high++;
    }
    out_file << "Low Density (under 100)  : " << low << " countries\n";
    out_file << "Medium Density (100-499) : " << med << " countries\n";
    out_file << "High Density (500+)      : " << high << " countries\n";
    
    out_file << "\n====================================================\n";
    out_file << "Report generated successfully.\n";
    
    // 4. Close the file
    out_file.close();
    
    cout << "\nSUCCESS: Report saved as 'population_analysis_report.txt'" << endl;
}

void ReportGenerator::display_details() const {
    cout << "Report Generator ready with " << countries.size() << " countries." << endl;
}