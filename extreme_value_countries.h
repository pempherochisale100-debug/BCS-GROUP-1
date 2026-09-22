

#ifndef EXTREME_VALUE_COUNTRIES_H
#define EXTREME_VALUE_COUNTRIES_H

	#include <string>
	#include "base_class.h"
	
	using namespace std;

		class Extreme_value_countries : public Base_class {
			
			private:
				
				
				// creating a copy of country object from the data (that is composition)
				vector<Country_class> countries;
				
				// a helper function o help simply the displaying of data which happen in several places 
				// it is declared private because we want only the members of this class to access it
				void display_country_details (const string& title, const Country_class& c, double value, const string unit, bool is_integer) const;
				
			public:
				
				Extreme_value_countries (const vector<Country_class>& data);
				
				// the following are declarations of functions to find the country that will meet the specfic criteria
				void find_highest_population_2023 () const;
				void find_lowest_population_2023 () const;
				
				void find_highest_population_density () const;
				void find_lowest_population_density () const;
				
				void find_highest_birth_rate () const;
				void find_lowest_birth_rate () const;
				
				void find_largest_land_area () const;
				void find_smallest_land_area () const;
				
				// the following is the function to contain the sub menu for this file
				void extreme_value_countries_menu () const;
				
				// this will contain the switch and the loop to process and call the functions
				void run_menu () const;
				
				
				// overriding the display_details function from the base class
				void display_details () const override;
				
								
				
		};
		




#endif