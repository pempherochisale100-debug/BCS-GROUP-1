

#include "search_engine.h"
#include "custom_exceptions.h"
#include "base_class.h"
#include "country_class.h"
#include "Data_manager.h"
#include "statistical_measures.h"
#include "sorting_data.h"
#include "future_estimation.h"
//#include "search_engine.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;



			string future_estimation::to_lower_case (const string& text) {
				
				string result = text;
				
				for (size_t i = 0; i < result.size(); i++) {
					result [i] = (char) tolower (result [i]);
				}
				return result;
			}
 
		 	future_estimation::future_estimation(const vector<Country_class>&data) : countries (data) {
		 		
			 }
		 	
		 void future_estimation::estimate (string name) {
    
    // 1. Trim leading/trailing whitespace
    while (!name.empty() && (name.front() == ' ' || name.front() == '\t')) {
        name.erase(0, 1);
    }
    while (!name.empty() && (name.back() == ' ' || name.back() == '\t' || name.back() == '\r')) {
        name.pop_back();
    }
    
    // 2. Case-insensitive version
    string lower_name = to_lower_case(name);
    
    bool found = false;
    
    for (size_t i = 0; i < countries.size(); i++) {
        
        // 3. Check BOTH name AND cca3
        bool name_matches = (to_lower_case(countries[i].get_name()) == lower_name);
        bool code_matches = (to_lower_case(countries[i].get_cca3()) == lower_name);
        
        if (name_matches || code_matches) {
            
            found = true;
            
            // -------- display current info --------
            cout << "\n---------------------------------------------------------------------\n";
            cout << "  Country         : " << countries[i].get_name() << "\n";
            cout << "  CCA3            : " << countries[i].get_cca3() << "\n";
            cout << "  Continent       : " << countries[i].get_continent() << "\n";
            cout << "  2023 Population : " << countries[i].get_population_2023() << " people\n";
            cout << "  Growth Rate     : " << fixed << setprecision(2) 
                 << countries[i].get_growth_rate() << " %\n";
            cout << "---------------------------------------------------------------------\n";
            
            // -------- compute future population --------
            // Formula: pop2023 * (1 + rate/100)^10
            double rate_decimal = countries[i].get_growth_rate() / 100.0;
            double future_pop = countries[i].get_population_2023() 
                              * pow((1 + rate_decimal), 10);
            
            // -------- display estimate --------
            cout << "\n  Estimated Population in 10 years:\n";
            cout << "  " << fixed << setprecision(0) << future_pop << " people\n";
            cout << "---------------------------------------------------------------------\n\n";
            
            return;   // ← exit the function after finding
        }
    }
    
    // -------- not found --------
    if (!found) {
        cout << "\nERROR: Country \"" << name << "\" was not found.\n";
        cout << "  - Try the exact name (e.g., \"Malawi\")\n";
        cout << "  - Or use the CCA3 code (e.g., \"MWI\")\n\n";
    }
}	void future_estimation::display_menu() {
		 		cout << "========================================================================\n";
		 		cout << "                    ESTIMATE POPULATION AFTER 10 YEARS                  \n";
		 		cout << "========================================================================\n";
		 		
		 			cout << "1. Estimate population after 10 years \n";
		 			cout << "0. Back to main menu \n";
		 			cout << "Enter your choice (0-1): ";
		 		
			 }
		 	
			 
			 void future_estimation::run_menu () {
		 		int choice;
		 		
		 		do {
		 			display_menu ();
		 				if (!(cin>>choice)) {
		 					cin.clear();
		 					cerr << "ERROR: an error occured \n";
		 					cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 					choice = 0;
		 					
						 }
		 			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 			
		 			try {
		 				
		 				switch (choice) {
		 					case 1: {
		 						// will handle estimatiom \
		 						
		 						cout << "Enter country to estimate it's population: ";
		 						string country_name;
		 						getline (cin, country_name);
		 						
		 						estimate (country_name);
		 						
		 						
		 						
								break;
							 }
							 
							 case 0: {
							 	// will handle user exiting 
							 	cout << "Press enter to exit \n";
								break;
							 }
							 default : {
							 	throw Invalid_data_entered ("Invalid data entered, choie must be 0-1");
								break;
							 }
						 }
		 				
		 				
					 }catch (const exception& e) {
					 	cout << "ERROR: " << e.what () << endl;
					 }
		 			
				 }while (choice != 0);
		 		
			 }
		 	
		 	void future_estimation::display_details () const {
		 		
		 		
		 		cout << "Estimated population for the country done \n";
		 		
		 		
			 }
 	

 
 	
 
 	
 