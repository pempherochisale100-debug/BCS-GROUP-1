#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "sorting_data.h"
#include "country_class.h"
#include "custom_exceptions.h"

using namespace std;


// Display sort submenu
void Sort_engine::display_sort_menu () const {
	cout << "-----------------------------------------------------------------------------\n" << endl;
	cout << "                          SORTING CRITERIA MENU                              \n" << endl;
	cout << "-----------------------------------------------------------------------------\n" << endl;
	cout << "1. Sort by 2023 population (Descending) \n" << endl;
	cout << "2. Sort by 2010 population (Descending) \n" << endl;
	cout << "3. Sort by 1970 population (Descending) \n" << endl;
	cout << "4. Sort by population density (Descending) \n" << endl;
	cout << "5. Sort by growth rate (Ascending) \n" << endl;
	cout << "0. Exit the program  \n" << endl;
}

// Run the sort menu (loop)
void Sort_engine::run_sort_menu () const {
	

	int choice = -1;

	do {
		display_sort_menu();
		cout << "Enter your choice please: ";

		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore (numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number.\n";
			continue;
		}
		cin.ignore (numeric_limits<streamsize>::max(), '\n');

		try {
			switch (choice) {
				
				case 1: {
					
					sort_by_2023_population();
					
					break;
				}
				
				case 2: {
					
					sort_by_2010_population();
				
					break;
				}
				
				case 3: {
					
					sort_by_1970_population();
					
					break;
				}
				
				case 4: {
					
					sort_by_population_density();
					
					break;
				}
				
				case 5:{
					
					sort_by_growth_rate();
					
					break;
				}
				
				case 0:{
					
					cout << "Exiting the program...\n";
					
					break;
				}
				default: {
					
					cout << "Invalid choice. Please select 0-5.\n";
					break;
				}
				
			}
			
		} catch (const exception& e) {
			
			cout << "ERROR: " << e.what() << endl;
			
		}

		if (choice != 0) {
			
			cout << "\nPress Enter to continue...";
			cin.get();
			
		}

	} while (choice != 0);
}

// Override from Base_class
void Sort_engine::display_details () const {
	
	cout << "Sort_engine has " << countries.size() << " countries loaded.\n";
	
}















// Private helper — display sorted list
void Sort_engine::display_sorted_list (const vector<Country_class>& sorted_countries,
                                       const string& criteria,
                                       const string& column_label,
                                       int value_data_type) const {

	cout << "-------------------------------------------------------------------------------------------------\n" << endl;
	cout << "Sorted countries  => " << sorted_countries.size() << endl;
	cout << "Sorting criteria  => " << criteria << endl;
	cout << "-------------------------------------------------------------------------------------------------\n" << endl;

// displaying headers 
	cout << left
	     << setw(6)  << "Rank"
	     << setw(7)  << "cca3"
	     << setw(35) << "Country"
	     << setw(20) << "Continent"
	     << setw(20) << column_label << endl;
	cout << "-------------------------------------------------------------------------------------------------\n" << endl;

// here i will use size_t for the loop counter variable becaus it is a special datatype associated with vectors
	for (size_t i = 0; i < sorted_countries.size(); i++) {

		// creating a reference object to the country class and feeding it with sorted data from the sort functions
		const Country_class& c = sorted_countries[i];

		//  getting data using constructors and therefore displaying it 
		cout << left
		     << setw(6)  << c.get_rank()
		     << setw(7)  << c.get_cca3()
		     << setw(35) << c.get_name()
		     << setw(20) << c.get_continent();

		if (value_data_type == 1) {
			long long value = 0;

			// here the .find () method will return true if the argument passed to it,i.e 2023 from the function calling this helper function the
			if (column_label.find("2023") != string::npos) {
				
				value = c.get_population_2023();
				
			} 
			else if (column_label.find("2010") != string::npos) {
				
				value = c.get_population_2010();
				
			} 
			else if (column_label.find("1970") != string::npos) {
				
				value = c.get_population_1970();
				
			}

			cout << setw(20) << value << endl;
			
		} 
		else {
			
			// here we are dealing with double members which are density and growth rate
			double val = 0.0;

			if (column_label.find("Density") != string::npos) {
				
				val = c.get_population_density();
				
			} 
			else if (column_label.find("Growth") != string::npos) {
				
				val = c.get_growth_rate();
				
			}

			cout << setw(20) << fixed << setprecision(2) << val << endl;
			
		}
	}

	cout << "---------------------------------------------------------------------------------------------------\n";
}




// Constructor
Sort_engine::Sort_engine (const vector<Country_class>& data) : countries (data) {
	
}

// Sort: 2023 population (descending)
void Sort_engine::sort_by_2023_population () const {
	
	vector<Country_class> sorted_countries_by_2023 = countries;

	sort (sorted_countries_by_2023.begin(), sorted_countries_by_2023.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_population_2023() > b.get_population_2023();
		
	}
	);

	display_sorted_list (sorted_countries_by_2023, "2023 population (Descending)", "2023 population", 1);
}

// Sort: 2010 population (descending)
void Sort_engine::sort_by_2010_population () const {
	
	vector<Country_class> sorted_countries_by_2010 = countries;

	sort (sorted_countries_by_2010.begin(), sorted_countries_by_2010.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_population_2010() > b.get_population_2010();
		
	}
	);

	display_sorted_list (sorted_countries_by_2010, "2010 population (Descending)", "2010 population", 1);
}

// Sort: 1970 population (descending)
void Sort_engine::sort_by_1970_population () const {
	
	vector<Country_class> sorted_countries_1970 = countries;

	sort (sorted_countries_1970.begin(), sorted_countries_1970.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_population_1970() > b.get_population_1970();
		
	}
	);

	display_sorted_list (sorted_countries_1970, "1970 population (Descending)", "1970 population", 1);
}

// Sort: density (descending)
void Sort_engine::sort_by_population_density () const {
	
	vector<Country_class> sort_by_density = countries;

	sort (sort_by_density.begin(), sort_by_density.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_population_density() > b.get_population_density();
		
	}
	);

	display_sorted_list (sort_by_density, "Density (Descending)", "population Density", 2);
}

// Sort: growth rate (ascending)
void Sort_engine::sort_by_growth_rate () const {
	
	vector<Country_class> sort_growth_rate = countries;

	sort (sort_growth_rate.begin(), sort_growth_rate.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_growth_rate() < b.get_growth_rate();
		
	}
	);

	display_sorted_list (sort_growth_rate, "Growth rate (Ascending)", "Growth rate", 2);
}
