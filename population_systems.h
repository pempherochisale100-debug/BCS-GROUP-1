
#ifndef POPULATION_SYSTEMS_H
#define POPULATION_SYSTEMS_H

	#include <string>
	#include <vector>
	#include <limits>
	#include <iostream>
	
	#include "Data_manager.h"
	#include "Analysis_engine.h"
	#include "base_class.h"
	#include "custom_exceptions.h"
	#include "country_class.h"
	#include "search_engine.h"
	#include "sorting_data.h"
	#include "exporting_highly_pop_countries.h"
	#include "comparing_countries.h"
	#include "extreme_value_countries.h"
	#include "statistical_measures.h"
	//#include "Data_manager.h"
	#include "future_estimation.h"
	
		using namespace std;
		
		class Population_systems  {
			
			private:
				
				// decalring the owner of all the data we will use here
				Load_data loader;
				
				// a flag to check the data loading errors 
				bool check_loading_status;
				
				
				// creating pointer object to the various engines developed 
				AnalysisEngine* analysing;
				Search_engine* searching;
				Export_high_pop_countries* exporting;
				Base_class* pointer;
				Comparing_countries* comparing;
				Extreme_value_countries* extremes;
				Sort_engine* sorting;
				statistical_measures* stats;
				future_estimation* estimating;
				
				// a void function to hold the main menu of the project
				void display_menu () const;
				
				// a void function to invoke the data_loader from the data_manager_class 
				void invoke_data_loader ();
				
				// avoid function to cleanup the engines for a fresh start  of the project
				void cleanup_all_engines ();
				
				// a void function to rebuild the engines after cleaning them
				void rebuild_engines_after_cleaning ();
				
			public:
				
				// a public constructor to initialise thedeclared objects with nullptrs 
				Population_systems ();
				
				// a void function to contain the menu of the project
				void run_main_menu () ;
				
				//a public destructor to invoke the the clean engines method
				
				~Population_systems ();
				
				
				
				
				
				
				
		};





#endif