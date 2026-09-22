
#ifndef COMPARING_COUNTRIES_H
#define COMPARING_COUNTRIES_H


	#include <string>
	#include <iostream>
	#include <vector>
	
	
	#include "base_class.h"
	#include "country_class.h"
	#include "Data_manager.h"
	
		using namespace std;
		
			class Comparing_countries : public Base_class {
				
				private:
					
					vector<Country_class> countries; // this will hold a copy of country vector from the data manager
					
					// the following function will help us search for the country if it exists and then return a pointer to where that country has been found
					const Country_class* search_a_country (const string& user_input) const ;
					
					// the following function will handle conversion of the user input to a lower case so that the search 
					// should be case insetive
					string to_lower_case (const string& user_input) const;
					
					// the following function will handle comparison of the two countries entered by the user
					// this a helper function to display the countries being copmared side by side
					void compare_countries (const string& country_a, const string& country_b) const;
					
					// the following function will hekp display the compared results
					void display_compared_results (const Country_class& country_a, const Country_class& country_b) const;
					
					
				public:
					
					// the following is the public constructor
					Comparing_countries (const vector<Country_class>& data);
					
					
					// this function will have a menu fo the user to select options from there
					void display_compare_countries_menu () const;
					
					// the following function will have a switch to handel the user choice from the menu
					void run_compare_countries_menu () const;
					
					// the following functon will be an override to the display_details () in the base class
					void display_details () const override;
					
					
					
					
					
				
				
				
				
			};


#endif