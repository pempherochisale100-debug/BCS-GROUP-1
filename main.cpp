#include<iostream>
#include <limits>
#include<string>

#include "country_class.h"
#include "Data_manager.h"
#include "sorting_data.h"
#include "custom_exceptions.h"
#include "extreme_value_countries.h"
#include "search_engine.h"
#include "exporting_highly_pop_countries.h"
#include "Analysis_engine.h"
#include "comparing_countries.h"


using namespace std;

void display_menu ();
//void main_switch ();

int main() {


	Load_data loader;
	
	loader.load_data ("world_population_data.csv");
	
	
	int choice;
	
		
		
		do {
			
			
			display_menu();
			
			
			cout<<"Enter your choice (0-14) \n";
				cin>>choice;
			
			try {
				
				
				
				switch(choice){
					case 1:{
						//loads csv data
						
						cout << "You selected to load csv data from the file \n";
						loader.display_details();
						break;
					}
					case 2 : {
						//display number of countries 
						cout << "You have " << loader.get_countries_count() << " countires loaded \n";
						break;
					}
					case 3: {
						//search countries 
						
						Search_engine searching (loader.get_countries());
						
						searching.display_details();
						break;
					}
					case 4:{
						//sort countries
						
						Sort_engine sorting (loader.get_countries());
						
						sorting.run_sort_menu();
						
						break;
					}
					case 5:{
						//find max and min values 
						
						Extreme_value_countries extreme (loader.get_countries());
						
						extreme.run_menu ();
						
						break;
					}
					case 6:{
						//filter countries
						
						AnalysisEngine analyser (loader.get_countries());
						
						analyser.filterCountries();
						
						break;
					}
					case 7 :{
						//statistical analaysis
						break;
					}
					case 8:{
						//density classification
						
						AnalysisEngine analyser (loader.get_countries());
						
						analyser.classifyDensity();
						
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
						break;
					}
					case 12:{
						//compare countries 
						
						Comparing_countries comparator (loader.get_countries());
						
						comparator.run_compare_countries_menu();
						break;
					}
					case 13:{
						//export high population countries to another file
						
						Export_high_pop_countries exporter (loader.get_countries());
						
						exporter.run_export_countries_menu();
						
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
		
				
			} catch (const exception& e) {
				cout << "ERROR: " << e.what () << endl;
			}
			
			if (choice != 0) {
				cout << "\n  Press enter to continue...\n";
				cin.get();
			}
			
			
		}	while (choice != 0);	


	return 0;
}




	
		void display_menu () {
			
			// the following function will display the main menu of the program
			
			cout << "------------------MAIN MENU-----------------"<<endl;
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
		
	