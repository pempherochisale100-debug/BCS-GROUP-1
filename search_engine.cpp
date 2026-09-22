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

using namespace std;

string Search_engine::toLower(string str) const {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void Search_engine::search_by_name(string& name) const {
	
    string searchTerm = toLower(name);
    
    bool found = false;

    cout << "\n--- SEARCH RESULTS ---\n";

    for (size_t i = 0; i < countries.size(); i++) {
    	
        if (toLower(countries[i].get_name()) == searchTerm) {
        	
            cout << "Country Found!\n";
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
    cout << "Enter your choice (1 or 2): ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: invalid number entered.\n";
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
	else {
		
        cout << "ERROR: Invalid choice. Please select 1 or 2.\n";
        
    }
}

void Search_engine::display_details() const {
	
    search_menu();
    
}







