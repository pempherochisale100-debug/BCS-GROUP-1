#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

		
		#include <string>
		#include <vector>
		#include <fstream>
		#include <sstream>
		#include <iostream>
		
		#include "country_class.h"
		#include "base_class.h"
		
		using namespace std;


			class Load_data : public Base_class {
				
				
				private:
					
					vector<Country_class> country;
					
					bool check_loading_status = true;
					
				public:
					
					
					// we added the following getter to get the countries to every part where we need 
					
					const vector<Country_class>& get_countries () const;
					
					
					// the following function will return number of countries loaded from the csv file
					int get_countries_count () const ;
					
					// this is the default constructor to initialise the check_loading_status variable with false
					Load_data ();
					
					
					// a function to load data 
					void load_data (const string& fileName) ;
						
					// an override to the base class display function 	
					void display_details () const override ;
			
						
					
			};






#endif