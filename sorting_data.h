#ifndef  SORTING_DATA_H
#define SORTING_DATA_H

	#include <iostream>
	#include <string>
	#include <limits> // this will be used to clear the input buffer when trying to get user input
	#include <algorithm> // it will be used fo the sort() function to siimply sorting
	#include <iomanip> // used for setting precision points and setting width
	#include <vector> // we use this because will compose a vector object in the sort_engine class
	
	
	#include "custom_exceptions.h"
	#include "country_class.h"
	#include "Data_manager.h"
	#include "base_class.h"
	
		using namespace std;
		
		class Sort_engine : public Base_class {
			
			private:
				vector<Country_class> countries;
				
				void display_sorted_list (const vector<Country_class>& sorted_countries, 
										  const string& criteria, const string& column_label, 
										  int value_data_type ) const;
				
				
				
			public:
				
				// i will have a constructor that will receive a refence to the data from the data_managaer.h
				// in the main function when a data_manager_pointer is created with an object, we will use that obeject to get data from country country
				// for example Data_manager* load;
				// 
				Sort_engine (const vector<Country_class>& data);
				
				
				void sort_by_2023_population () const;
				
				void sort_by_2010_population () const;
				
				void sort_by_1970_population () const;
				
				void sort_by_population_density () const;
				
				void sort_by_growth_rate () const;
				
				void display_sort_menu () const;
				
				void run_sort_menu () const;
				
				void display_details () const override;
				
				
			
		};
	














#endif