#ifndef ANALYSIS_ENGINE_H
#define ANALYSIS_ENGINE_H

#include <iostream>
#include <vector>
#include <string>
#include "country_class.h"
#include "base_class.h"

using namespace std;
class AnalysisEngine : public Base_class {
	
	private:
		//this hold all the data
		vector<Country_class>countries;
		
		public:
			// constructor: receives data from main cpp
			AnalysisEngine(vector<Country_class> data);
			
			
			void filterCountries()const;
			
			void classifyDensity()const;
			
			void analysePopulationGrowth()const;
			
			void display_details() const override;
	
};
#endif