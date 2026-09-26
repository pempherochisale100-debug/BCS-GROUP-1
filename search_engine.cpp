#include "search_engine.h"
#include "base_class.h"
#include "country_class.h"
#include "Data_manager.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

string Search_engine::toLower(string str) const {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void Search_engine::search_by_name(string& name) const {
	
    string searchTerm = toLower(name);
    
    bool found = false;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "---------------------------------------------SEARCH RESULTS-------------------------------------------------\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";

    for (size_t i = 0; i < countries.size(); i++) {
    	
        if (toLower(countries[i].get_name()) == searchTerm) {
        	
            cout << "Country Found!\n";
            cout << "------------------------------------------------------------------------------------------------------------\n";
            			cout << left  << setw (5)<< "CATEOGORY        "     << setw (35)<< "VALUE" << endl;
           	cout << "------------------------------------------------------------------------------------------------------------\n";
			            cout << left  << setw (20) << "Rank"                << setw(5) << "=>" << countries [i].get_rank () << endl;
						cout << left  << setw (20) << "cca3"			    << setw(5) << "=>" << countries [i].get_cca3 () << endl;
						cout << left  << setw (20) << "Country name" 		<< setw(5) << "=>" << countries [i].get_name () << endl;
						cout << left  << setw (20) << "Continent"			<< setw(5) << "=>" << countries [i].get_continent () << endl;
						cout << left  << setw (20) << "2023 population" 	<< setw(5) << "=>" << countries [i].get_population_2023 () << endl;
						cout << left  << setw (20) << "2022 population" 	<< setw(5) << "=>" << countries [i].get_population_2022 () << endl;
						cout << left  << setw (20) << "2020 population" 	<< setw(5) << "=>" << countries [i].get_population_2020 () << endl;
						cout << left  << setw (20) << "2015 population" 	<< setw(5) << "=>" << countries [i].get_population_2015 () << endl;
						cout << left  << setw (20) << "2010 population" 	<< setw(5) << "=>" << countries [i].get_population_2010 () << endl;
						cout << left  << setw (20) << "2000 population" 	<< setw(5) << "=>" << countries [i].get_population_2000 () << endl;
						cout << left  << setw (20) << "1990 population" 	<< setw(5) << "=>" << countries [i].get_population_1990 () << endl;
						cout << left  << setw (20) << "1980 population" 	<< setw(5) << "=>" << countries [i].get_population_1980 () << endl;
						cout << left  << setw (20) << "1970 population"  	<< setw(5) << "=>" << countries [i].get_population_1970 () << endl;
						cout << left  << setw (20) << "Population Density"  << setw(5) << "=>" << countries [i].get_population_density () << " Pple/sqr_km" << endl;
						cout << left  << setw (20) << "Land area" 			<< setw(5) << "=>" << countries [i].get_land_area () << " sqr_km" << endl;
						cout << left  << setw (20) << "world percentage" 	<< setw(5) << "=>" << countries [i].get_world_percentage () << " %" << endl;
						cout << left  << setw (20) << "Growth Rate    "     << setw(5) << "=>" << countries [i].get_growth_rate () << " %" << endl;
			cout << "------------------------------------------------------------------------------------------------------------\n";
            countries[i].display_details();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "ERROR: Country " << name << " was not found. Check spelling.\n";
    }
}

void Search_engine::search_by_cca3(string& code) const {
    string searchTerm = toLower(code);
    bool found = false;

    cout << "\n--- SEARCH RESULTS ---\n";

    for (size_t i = 0; i < countries.size(); i++) {
        if (toLower(countries[i].get_cca3()) == searchTerm) {
            cout << "Code Found!\n";
             countries[i].display_details();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "ERROR: CCA3 Code " << code << " was not found.\n";
    }
}

Search_engine::Search_engine(const vector<Country_class>& data)
    : countries(data) {}

void Search_engine::search_menu() const {
    int choice = 0;
    string input;

    cout << "\n--- SEARCH MENU ---\n";
    cout << "1. Search by Country Name\n";
    cout << "2. Search by CCA3 Code\n";
    cout << "0. Press enter to exit the program\n";
    cout << "Enter your choice (1 or 2): ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: invalid choice entered.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
    	
        cout << "Enter the Country Name: ";
        getline(cin, input);
        search_by_name(input);
        
    } 
	else if (choice == 2) {
		
        cout << "Enter CCA3 Code: ";
        getline(cin, input);
        search_by_cca3(input);
        
    } 
    else if (choice == 0) {
    	cout << "Press enter to exit \n";
    	
	}
	else {
		
        cout << "ERROR: Invalid choice. Please select 1 or 2.\n";
        
    }
}

void Search_engine::display_details() const {
	
    search_menu();
    
}







