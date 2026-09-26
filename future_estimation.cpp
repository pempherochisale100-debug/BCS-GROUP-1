

#include "search_engine.h"
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
		 	
		 	void future_estimation::estimate (string name)  {
		 		
		 		//Country_class c = countries;
		 		string lower_name = to_lower_case (name);
		 		bool found =false;
		 		for (size_t i = 0; i < countries.size(); i++) {
		 			
		 			if ( to_lower_case (countries [i].get_name()) == lower_name ) {
		 				
		 				found = true;
		 				
		 				cout << left << setw (10) << "Rank"
		 					         << setw (10) << "CCA3"
		 					         << setw (20) << "country"
		 					         << setw (25) << "continent"
		 					         << setw (15) << "2023"
		 					         << setw (15)  << " growth%" << endl;
		 					         
		 				cout << left << setw (10)  << countries [i].get_rank ()
		 							 << setw (10)  << countries [i].get_cca3 ()
		 							 << setw (20) << countries [i].get_name ()
		 							 << setw (25) << countries [i].get_continent ()
		 							 << setw (15) << countries [i].get_population_2023 ()
		 							 << setw (15)  << countries [i].get_growth_rate () << endl << endl;
		 							 
		 					double estimation = 0.0;
		 					
		 					double rate_decimal=countries[i].get_growth_rate()/100.0;
		 					
		 					estimation = countries [i].get_population_2023 () * pow ((1 + rate_decimal),10);
		 					
		 					cout<< fixed <<setprecision(0)<<estimation;
		 							 
		 					cout << "The future population of " << countries [i].get_name () <<	" = " << estimation << endl;	 
		 				
					 }  
		 			
		 			
				 }
		 		
			 }
		 	
		 	void future_estimation::display_menu() {
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
 	

 
 	
 
 	
 