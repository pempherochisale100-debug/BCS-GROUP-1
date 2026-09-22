

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <fstream>
#include <iomanip>
#include <vector>

#include "exporting_highly_pop_countries.h"

	using namespace std;
	
	
	// definition of the default constructor which has been declared in the exporting_highly_popyulated_countries.h
	Export_high_pop_countries::Export_high_pop_countries (const vector<Country_class>& data) : countries (data) {
		
	}
	
	// this function will contain a dashed lien for decorating the output
	void Export_high_pop_countries::display_line () const {
		
		cout << "--------------------------------------------------------------------------------------------------------------------\n";
	}
	
	// the followng is the helper function that will help in writing data to a file 
	void Export_high_pop_countries::write_single_country (ofstream& out_file, const Country_class& c) const {
		
		out_file << c.get_rank () << ","
				 << c.get_cca3 () << ","
				 << c.get_name () << ","
				 << c.get_continent () << ","
				 << c.get_population_2023 () << ","
				 << c.get_land_area () << ","
				 << c.get_population_density () << ","
				 << c.get_world_percentage () << ","
				 << c.get_growth_rate  () << "\n";
				 
				 
	}
	
	
	// the following function will be called when user selects an option which demands the program to produce the preview of the highly populated countries
	void Export_high_pop_countries::preview_highly_populated_countries() const {
		
		display_line ();
		cout << "                           A PREVIEW OF HIGH POPULATED COUNTRIES TO BE EXPORTED                                     \n";
		display_line ();
		
		cout << left << setw (8) << " Number " << setw (18) << " Country " << setw (20) << " 2023 Population " << endl;
		
		display_line ();
		
		// the following integer variable will help to keep track of the numbers of the countries under inspection
			int count = 0;
			
			// the following for loop will loop through the coutries vector and find countris with 2023 population greater than 100 million
			for (size_t i = 0; i < countries.size(); i++) {
				
				// checking if the countries at the loop index is meeting the required criteria 
				// if it meets the criteria, then print it
				if (countries [i].get_population_2023 () > FILTER_CRITERIA) {
					count++;
					cout << left << setw (8) << count << setw (18) << countries [i].get_name () << setw (20) << countries [i].get_population_2023 () << endl;
				}
				
				
			}
			
			display_line ();
			cout << "A total of " << count << " countries has been identified to have population greater than " << FILTER_CRITERIA << endl;
			display_line ();
		
		
	}
	
	
	// the folllowing fnction will disply the define the sub-menu of this module 
	void Export_high_pop_countries::display_export_countries_menu() const {
		
		display_line ();
		cout << "                          SUB-MENU FOR EXPORTING DATA                                    \n";
		display_line ();
		
			cout << "1. Preview a list of countries to be exported \n";
			cout << "2. Export countries to a \"High_population_countries.csv\" \n";
			cout << "0. Exit the program \n";
			cout << "Enter your choice (0 -2) ";
			
		
	}
	
	// this function will handle real exportation lof data from the program to the csv file
	void Export_high_pop_countries::run_export_countries_menu() const {
		
		int choice;
		do {
			
			
			
		display_export_countries_menu ();
		
		
			if (!(cin>>choice)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max (), '\n');
				cerr << "ERROR: Invalid input detected \n";
			}
				cin.ignore(numeric_limits<streamsize>::max (), '\n');
		
		
			try {
				
				switch (choice) {
					case 1: {
						// this will about the preview of the data of countries to be exported
						preview_highly_populated_countries ();
						break;
					}
					
					case 2: {
						// this will be about the actual data exportation 
						export_highly_populated_coountries ();
						break;
					}
					
					case 0: {
						cout << "Press any key to exit... \n";
						break;
					}
					
					default : {
						throw Invalid_data_entered ("Choice should be an integer between 0 and 2");
						break;
					}
				}
				
			}
			catch (const exception& e) {
				cout << "ERROR: " << e.what () << endl;
			}
				
			if (choice != 0) {
				cout << "Press enter to continue \n";
				cin.get();
			}			
			
			
		
	} while (choice != 0);
	
	}
	
	// the following function will handle the actual exporting of data to the csv file
	int Export_high_pop_countries::export_highly_populated_coountries(const string& filename) const {
		
		// the following vector will hold filtered countries which have me the filtering criteria
		vector<Country_class> filtered_countries;
		
		// check if the countries object has got data in it 
		
		if (countries.empty()) {
			throw Invalid_data_entered ("ERROR: No data in this object");
		}
		
		
		// the following for loop will loop through the countries and yeah 
		
		for (size_t i = 0; i < countries.size (); i++) {
			
			if (countries [i].get_population_2023 () > FILTER_CRITERIA) {
				
				filtered_countries.push_back(countries [i]);
			}
		}
		
		// check the status of the filtered countries 
		
		if (filtered_countries.empty()) {
			throw Invalid_data_entered ("No countries found to much the criteria (>100M)");
		}
		
		// let now sort the countries in descending order
		
		sort (filtered_countries.begin(), filtered_countries.end(),
		
			[] (const Country_class& a, const Country_class b ) {
				
				return a.get_population_2023 () > b.get_population_2023 ();
				
			}
			
		);
		
		// creating the object of ofstream 
		
		ofstream out_file;
		out_file.open(filename.c_str(), ios::out);
		
			if (!out_file.is_open()) {
				throw Invalid_data_entered ("File failed to open " + filename);
			}
			
			// creating  a  header row  csv file 
			
			out_file << "Rank, cca3, country name, continent, 2023 population, land area, population density, growth rate, world percentage \n";
			
			// writing the acrtual data into the file 
			for (size_t i = 0; i < filtered_countries.size(); i++) {
				
				write_single_country (out_file, filtered_countries [i]);
				
			}
			
			out_file.close();
			
		display_line ();
		cout << "Exporting data to " << filename << " has been successful \n";
		cout << filtered_countries.size() << " Countries have been exported \n";
		display_line ();
		
			return (int) filtered_countries.size();		
		
		
	}
	
	void Export_high_pop_countries::display_details() const {
		
		cout << "Exporting engine with " << countries.size() << " of loaded countries \n";
		
	}
		