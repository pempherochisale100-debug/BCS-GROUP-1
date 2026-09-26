
#include <iostream>
#include <string>
#include <vector>
#include <limits>

	#include "population_systems.h"
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
	#include "future_estimation.h"

	using namespace std;
	
	
	// this is public constructor to initialise the obeject pointers with  a nullptrt in the first place 
	Population_systems::Population_systems () : check_loading_status (false), 
													 analysing (nullptr),
													 searching (nullptr),
													 sorting (nullptr),
													 exporting (nullptr),
													 extremes (nullptr),
													 comparing (nullptr),
													 pointer (nullptr),
													 estimating (nullptr),
													 stats (nullptr) {
													 	
													 	
													 }
// the follwing function will delete the dynamically memory for the object of different classes 
// format is like => step 1. delete the object 
//				  => step 2. set the deleted object to  nullptr													 
	void Population_systems::cleanup_all_engines ()  {
		delete analysing;
		analysing = nullptr;
		delete searching;
		searching = nullptr;
		delete sorting;
		sorting = nullptr;
		delete exporting;
		exporting = nullptr;
		delete extremes;
		extremes = nullptr;
		delete comparing;
		comparing = nullptr;
		delete pointer;
		pointer = nullptr;
		delete stats;
		stats = nullptr;
		delete estimating;
		estimating = nullptr;
	}
	
	// the following function will rebuild the engines after they have cleaned by the ceaning fucntion
	void Population_systems::rebuild_engines_after_cleaning () {
		
		// a country class vector to hold the countries loaded from the data manager
		const vector<Country_class>& data = loader.get_countries();
		
		// dynamically allocating memory to the heap with the objects created 
		sorting = new Sort_engine (data);
		comparing = new Comparing_countries (data);
		searching = new Search_engine (data);
		extremes = new Extreme_value_countries (data);
		exporting = new Export_high_pop_countries (data);
		stats = new statistical_measures (data);
		analysing = new AnalysisEngine (data);
		
	}
	
	void Population_systems::invoke_data_loader() {
		
		// invoking the load_data () method of the data_manager class
		
		string filename = "world_population_data.csv";
		loader.load_data (filename);
		
		check_loading_status = true;
		
		rebuild_engines_after_cleaning ();
		
	}
	
	void Population_systems::display_menu () const {
		
			// the following function will display the main menu of the program
			cout << "--------------------------------------------------------------------------\n";
			cout << "---------------------------------MAIN MENU--------------------------------\n";
			cout << "--------------------------------------------------------------------------\n";
			cout << " 1. Load CSV Data  " << endl;
			cout << " 2. Display Nmumber of Countries " << endl;
			cout << " 3. Search Countries \n";
			cout << " 4. Sort Countries \n";
			cout << " 5. Find maximu /minimum values \n";
			cout << " 6. Filter countries \n";
			cout << " 7. Statistical Analysis \n";
			cout << " 8. Density Classification\n";
			cout << " 9. Analyses by continent \n";
			cout << "10. Population Trend Analysis \n";
			cout << "11. Estimate Future Population \n";
			cout << "12. Compare Countries \n";
			cout << "13. Export High-Population Countries \n";
			cout << "14. Generate Report \n";
			cout << " 0. Exit \n ";
			
	}
	
	
	// the function to run the do while loop of the 
	void Population_systems::run_main_menu() {
		int choice;
		do {
			display_menu();
			cout<<"Enter your choice (0-14) \n";
				cin>>choice;
		// we are going to put our switch inside a try catch block because it cause exception dutring the progrqm running when rhe user
		// interacting with the system 	
			try {
				switch(choice){
					case 1:{
						//loads csv data
						pointer = &loader;
						pointer->display_details();
						break;
					}
					case 2 : {
						//display number of countries 
						cout << "You have " << loader.get_countries_count() << " countires loaded \n";
						break;
					}
					case 3: {
						//search countries 
						searching->display_details();
						pointer->display_details();
						break;
					}
					case 4:{
						//sort countries
						sorting->run_sort_menu();
						pointer->display_details();
						break;
					}
					case 5:{
						//find max and min values 
						extremes->run_menu();
						pointer->display_details();
						break;
					}
					case 6:{
						//filter countries
						analysing->filterCountries();
						pointer->display_details();
						break;
					}
					case 7 :{
						//statistical analaysis
						stats->run_statistical_menu();
						pointer->display_details();
						break;
					}
					case 8:{
						//density classification
						analysing->classifyDensity();
						pointer->display_details();
						break;
					}
					case 9:{
						//analyse by continent
						break;
					}
					case 10:{
						//population trend analysis
						break;
					}
					case 11:{
						//estimate future population
						estimating->run_menu();
						pointer->display_details();
						break;
					}
					case 12:{
						//compare countries 
						comparing->run_compare_countries_menu();
						pointer->display_details();
						break;
					}
					case 13:{
						//export high population countries to another file
						exporting->run_export_countries_menu();
						pointer->display_details();
						break;
					}
					case 14:{
						//generate report 
						break;
					}
					case 0:{
						cout << "Press any key to exit \n";
						//loop_controller = false;
						break;
					}
					default :{
						cout << "INVALID CHOICE SELECTED, SELECT (0-14) \n";
						break;
					}
				}
		
			// cstch the exception from the try and then invoke the what () method from the exception class	
			} catch (const exception& e) {
				cout << "ERROR: " << e.what () << endl;
			}
			
			if (choice != 0) {
				cout << "\n  Press enter to continue...\n";
				cin.get();
			}
			
			
		}	while (choice != 0);
	}
	
	Population_systems::~Population_systems() {
		cleanup_all_engines ();
	}
	
	
	
	