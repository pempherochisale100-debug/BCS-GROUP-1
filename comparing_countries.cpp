
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <cctype>
#include <limits>

#include "Data_manager.h"
#include "country_class.h"
#include "base_class.h"
#include "comparing_countries.h"
#include "custom_exceptions.h"

	using namespace std;


	// the following function is the definition of the constructor that has been initialised in the comparing_countries.h
	Comparing_countries::Comparing_countries (const vector<Country_class>& data) : countries (data) {
		
	}
	
	// the following function will compare the country details
	void Comparing_countries::compare_countries (const string& country_a, const string& country_b) const {
		
		if (countries.empty()) {
			throw Invalid_data_entered ("No data in htis object");
		}
		
		const Country_class* first_country = search_a_country (country_a);
		const Country_class* second_country = search_a_country (country_b);
		
		if (first_country == nullptr) {
			throw Invalid_data_entered ("This pointer currently has no active data");
		}
		
		if (second_country == nullptr ) {
			throw Invalid_data_entered ("this pointer currently has no active data ");
		}
		
		display_compared_results (*first_country, *second_country );
		
	}


	// the following function definition will make the search to be case insesitive 
	
	string Comparing_countries::to_lower_case (const string& user_input) const {
		
		string input_holder = user_input;
		
		for (size_t i = 0; i < input_holder.size (); i++) {
			
			//taking every character at the loop index and casting it explicitly to a lower case thus (char) casting
			input_holder [i] = (char) tolower (input_holder [i]);
			
		}
		
		return input_holder;
		
	}



	// the following function will help searcha country by name or cca3 and it will return a country if found else a null pointer 
	const Country_class* Comparing_countries::search_a_country (const string& user_input) const {
		
		string target = to_lower_case (user_input); 
		
		// loop through the countries
		for (size_t i = 0; i < countries.size(); i++) {
			
			// search by name 
			if (to_lower_case (countries [i].get_name ()) == target) {
				
				return &countries [i];
				
			}
			
			// search by cca3
			if (to_lower_case (countries [i].get_cca3 ()) == target) {
				
				return &countries [i];
				
			}
			
		}
		return nullptr;
	}


	// the following function will compare the countries in different fields 
	void Comparing_countries::display_compared_results (const Country_class& country_a, const Country_class& country_b) const {
		
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                              COUNTRY COMPARISON                                " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	
	
	// header row: names
	cout << left << setw(28) << "" << setw(24) << country_a.get_name() << setw(24) << country_b.get_name() << endl;
	
	cout << left << setw(28) << "" << setw(24) << ("(" + country_a.get_cca3() + ")") << setw(24) << ("(" + country_b.get_cca3() + ")") << endl;
	
	cout << "--------------------------------------------------------------------------------" << endl;
	
	
	// this line of code will display the continent names in which the countries the user entered belong
	cout << left << setw(28) << "Continent" << setw(24) << country_a.get_continent() << setw(24) << country_b.get_continent()  << endl;
	
	// this line of code will display the 2023 population of the countries under study
	cout << left << setw(28) << "2023 Population" << setw(24) << country_a.get_population_2023() << setw(24) << country_b.get_population_2023() << endl;
	
	// this line of code will display the land area of each of the selected countries 
	cout << left << setw(28) << "Land Area (km2)" << setw(24) << fixed << setprecision(2) << country_a.get_land_area() << setw(24) << fixed << setprecision(2) << country_b.get_land_area() << endl;
	
	// this line of code will display the  Population Density of each of the countries under study 
	cout << left << setw(28) << "Population Density" << setw(24) << fixed << setprecision(2) << country_a.get_population_density() << setw(24) << fixed << setprecision(2) << country_b.get_population_density() << endl;
	
	// this line will also diaply the growth of each of the countries under comparison
	cout << left << setw(28) << "Growth Rate (%)" << setw(24) << fixed << setprecision(2) << country_a.get_growth_rate() << setw(24) << fixed << setprecision(2) << country_b.get_growth_rate()  << endl;
	
	// this line will didplay the world [ercentage contribution of each of the countries under study
	cout << left << setw(28) << "World Percentage (%)" << setw(24) << fixed << setprecision(2) << country_a.get_world_percentage() << setw(24) << fixed << setprecision(2) << country_b.get_world_percentage() << endl;
	     
	
	cout << "\n------------------------------------------------------------------------------------\n" << endl;
	
	
	}

	// this function will have a menu fo the user to select options from there
	void Comparing_countries::display_compare_countries_menu () const {
		
		cout << "-----------------------------------------------------------------------------\n";
		cout << "                          COMPARING COUNTRIES MENU                           \n";
		cout << "-----------------------------------------------------------------------------\n";
		
			cout << "1. Compare two countries \n";
			cout << "0. Exit to the main menu \n";
			cout << "Select an option (0-1): ";
	}
	
	
	// the following function will have a switch to handel the user choice from the menu
	void Comparing_countries::run_compare_countries_menu () const {
		
		int choice;
		
		do {
			
			display_compare_countries_menu ();
			// checking the user input before handling the data whether it is of string data type because we would our type to be an integer
				if (!(cin>>choice)) {
					cin.clear();
					cerr << "\nERROR: Invalid input entered \n";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					choice = 0;
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
					try {
					
						switch (choice) {
							case 1: {
								// this will control everything here 
								// variables to store the inpput entered by the user
								string first_country, second_country;
								
									// getting the user input using getline *() method
									cout << "Enter name or cca3 of the first country to compare: ";
										getline (cin, first_country);
									
									cout << endl;
									cout << "Enter name or cca3 of the second country to compare: ";
									getline (cin, second_country);
									
									// i can check whether the data entered is valid or is empty using  the empty () method 
									
										if (first_country.empty() && second_country.empty()){
											throw Invalid_data_entered ("ERROR: You must enter the names of the countries to proceed with the comaprison");	
										}	
																		
									compare_countries (first_country, second_country);
								
								break;
							}
							case 0: {
								// this cae will handle user exiting the program
								break;
							}
							default : {
								throw Invalid_data_entered ("Your choice should be between 0 - 1");
								break;
							}
						}
						
						if (choice != 0) {
							cout << "Press enter to continue the program..." << endl;
							cin.get();
						}	
						
						
						
					}catch (const exception& e) {
						cout << "ERROR: " << e.what () << endl;
					}
			
			
		}
		while (choice != 0);
	}
	
	// the following functon will be an override to the display_details () in the base class
	void Comparing_countries::display_details () const {
		
		cout << "Comparing of countries happened with " << countries.size() << " and has been successful " << endl;
		
	}
	



