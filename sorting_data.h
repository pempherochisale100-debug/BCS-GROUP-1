#ifndef  SORTING_DATA_H
#define SORTING_DATA_H

	#include <iostream>
	#include <string>
	#include <limits>
	#include "custom_exceptions.h"
	#include "country_class.h"
	#include "Data_manager.h";
	
		using namespace std;
		
		class Sort_engine : public Base_class {
			
			private:
				vector<Country_class> countries;
				
				void display_details (vector<Country_class>& sorted_countries, const string& sort_criteria);
				
			public:
				
				
			
		};
	














#endif