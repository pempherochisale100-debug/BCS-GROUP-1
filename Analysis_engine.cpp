#include "Analysis_engine.h"
#include <iomanip>
#include "custom_exceptions.h"
#include "Data_manager.h"

AnalysisEngine::AnalysisEngine(vector<Country_class>data){
	// save the data into our private variable
	countries=data;
}

// ======FILTER COUNTRIES======//
void AnalysisEngine::filterCountries()const{
	cout << "\n========================FILTERED  COUNTRIES======================================" << endl;
	
	cout << "CONDTIIONS: POPULATION > 100000000, DENSITY > 500,GROWTH > 2%, LAND AREA > 1000 000 kmÅ"<<endl;
	
	cout << "=================================================================================== " << endl;
	
	//use an integer counter  starting at 0
	int matchCount = 0;
	
	for (int i= 0;i<countries.size();i++) {
		
		
		if (countries[i].get_population_2023() > 100000000 || 
	    	countries[i].get_population_density() >  500   ||
			countries[i].get_growth_rate() > 2.0 ||
			countries[i] .get_land_area() >1000000) {
				
				cout<<countries[i].get_name()<<endl;
				matchCount++;
			} 
	}
	if (matchCount== 0){
		cout << "No countries met these criteria" << endl;
	}
	else{
		cout << "\n total countries found:" << matchCount << endl;
	}
	
	cout << "=================================================================================== " << endl;
}





// ======DENSITY CLASSIFICATIONS=====//
void AnalysisEngine::classifyDensity() const{
	
	int lowCount = 0;
	int mediumCount = 0;
	int highCount =0;
	
	if (countries.empty()) {
		throw Invalid_data_entered ("ERROR: This object has no data");
	}
	
	// use for loop  to look  at every single country in our vector one by one
	 for (int i= 0; i < countries.size(); i++){
	 	
	 	double density = countries[i].get_population_density();
	 	
	 	// check all  conditions given
	 	if (density < 100){
	 		lowCount++;
	 	
		 }
		 else if (density >= 100 && density < 500){
		 	mediumCount++;
		 	
		 }
		 else{
		 	highCount++;
		 }
		
	 }
	 // print  the results
	 
	 cout<<"\n==================Density Classfiaction=============="<<endl;
	 
	 cout << "low(under 100)      : " << lowCount    << " countries " << endl;
	 cout << "Medium(100-499)     : " << mediumCount << " countries" << endl;
	 cout << "High(500 and above) : " << highCount   << " countries" << endl;
	 
	 cout<<"======================================================"<<endl;
	 
	 }
	 
	 //===== ANALYSE POPULATION GROWTH======//
	  
	 void AnalysisEngine::analysePopulationGrowth() const {

    if (countries.size() == 0){
        cout << "No data loaded\n";
        return;
    }

    string largestAbsName   = countries[0].get_name();
    long long largestAbsChange = countries[0].get_population_2023() - countries[0].get_population_1970();

    string smallestAbsName  = countries[0].get_name();
    long long smallestAbsChange = largestAbsChange;  // start with same value

    string largestPercName  = countries[0].get_name();
    double largestPercChange = 0.0;

    for (size_t i = 0; i < countries.size(); i++) {
        long long pop1970 = countries[i].get_population_1970();
        long long pop2023 = countries[i].get_population_2023();

        long long absoluteChange = pop2023 - pop1970;   // ? correct direction

        double percentageChange = 0.0;
        if (pop1970 > 0) {
            percentageChange = ((double)absoluteChange / pop1970) * 100.0;
        }

        if (absoluteChange > largestAbsChange) {
            largestAbsChange = absoluteChange;
            largestAbsName   = countries[i].get_name();
        }
        if (absoluteChange < smallestAbsChange) {
            smallestAbsChange = absoluteChange;
            smallestAbsName   = countries[i].get_name();
        }
        if (percentageChange > largestPercChange) {   // ? braces
            largestPercChange = percentageChange;
            largestPercName   = countries[i].get_name();
        }
    }

    cout << "\n=========== Global Population Growth (1970 to 2023) ===========\n";
    cout << "Largest absolute increase   : " << largestAbsName  << " +" << largestAbsChange  << " people\n";
    cout << "Smallest absolute increase  : " << smallestAbsName << " "  << smallestAbsChange << " people\n";
    cout << "Largest percentage increase : " << largestPercName << " +" << fixed << setprecision(2) << largestPercChange << "%\n";
}

void AnalysisEngine::display_details () const {
	//int country_number = get_countries_count ();
	cout << "Filtering operation have been done on " << countries.size() <<  endl;
	//cout << "End it \n";
}