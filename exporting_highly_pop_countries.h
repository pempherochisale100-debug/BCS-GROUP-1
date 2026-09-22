
#ifndef EXPORTING_HIGHLY_POP_COUNTRIES_H
#define EXPORTING_HIGHLY_POP_COUNTRIES_H

		#include <iostream>
		#include <string>
		#include <vector>
		#include <fstream>
		#include <iomanip>
		
		#include "custom_exceptions.h"
		#include "country_class.h"
		#include "base_class.h"
		
			using namespace std;
			
				// this class will handle exportation of data from the filtered countries based on the criteria of all countries with 2023 population > 100million
				
				class Export_high_pop_countries : public Base_class {
					
					private:
						// the followign are declared private members of this class 
						
						vector<Country_class> countries; // This is the copy of the country object from the country class (composition)
						
						// the following is the criteria i will use throughout the entire module of exporting highly populated countries in the year 2023
						static const long long FILTER_CRITERIA = 100000000;
						
						// a helper function will help to write a single country as a single in the csv file
						void write_single_country (ofstream& out_file, const Country_class& c) const;
						
						void display_line () const;
						
					public:
						
						// the following is the public constructor that will load the declared countrie vector with data from the data manager
						Export_high_pop_countries (const vector<Country_class>& data);
						
						// the following is the function that show a preview of the countries which have been identified to have highest 2023 pop
						void preview_highly_populated_countries () const;
						
						
						// the followng function declaration will handle the actual exporting of data from the program to the csv file
						// it will return an integer because at the end i will only return number of countries which have been exported 
						int export_highly_populated_coountries ( const string& filename = "high_population_countries.csv") const;
						
						
						// the following function will contain a sub-menu for this module
						
						void display_export_countries_menu () const;
						
						void run_export_countries_menu () const;
						
						// the following function declaration will override the display details from the base class 
						
						void display_details () const override;
						
						
						
						
							
						
						
					
					
				};
				
		








#endif