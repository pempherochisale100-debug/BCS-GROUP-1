

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#include "base_class.h"
#include "custom_exceptions.h"
#include "country_class.h"
#include "Data_manager.h"
#include "extreme_value_countries.h"

	using namespace std;
	
	
		// defining the constructor
		Extreme_value_countries::Extreme_value_countries (const vector<Country_class>& data) : countries (data) {
			
		}
		
		void Extreme_value_countries::display_country_details (const string& title, const Country_class& c, double value, const string unit, bool is_integer) const {
			
			cout << "-------------------------------------------------------------------------------------------------------------\n";
			cout << "                                             " << title << "                                                 \n";
			cout << "-------------------------------------------------------------------------------------------------------------\n";
			
				cout << left << setw (10) << "Rank         => " << c.get_rank() << "\n"
							 << setw (10) << "cca3         => " << c.get_cca3() << "\n"
							 << setw (10) << "country name => " << c.get_name() << "\n"
							 << setw (10) << "Continent    => " << c.get_continent() << "\n";
							 
								     cout << "Value        => " ;
				
					if (is_integer) {
						
						// if the value being passed is an integer, there will no need to setprecision
						cout << fixed << setprecision (0) << value << " ";
						
					}
					else {
						
						cout << fixed << setprecision (2) << value << " ";
					}
					
					cout << unit << endl;
					
			cout << "------------------------------------------------------------------------------------------------------------\n";
		}
			
			
				// this function will loop through the countries and determine a country which has highest population in the year 2023
				void Extreme_value_countries::find_highest_population_2023 () const {
					
					// assume the country has highest population 
					
					Country_class first_country = countries [0];
					
					// loop throuhg and determine the country then set the first_country to the found country at the index of loop counter 
					
						for (size_t i = 1; i < countries.size(); i++) {
							
							if (countries [i].get_population_2023 () > first_country.get_population_2023()) {
								
								first_country = countries [i];
								
							}
							
						}
						
						display_country_details ("HIGHEST POPULATION 2023", 
												  first_country, 
												  first_country.get_population_2023(), 
												  "people", 
												  true);
				}
				
				
				// this function will loop through the countries and determine the coutnry which has the lowest population in the year 2023
				void Extreme_value_countries::find_lowest_population_2023 () const {
					
					
					Country_class first_lowest_pop_country = countries [0];
					
						for ( size_t i = 1; i < countries.size (); i++) {
							
							if (countries[i].get_population_2023() < first_lowest_pop_country.get_population_2023()) {
								
								first_lowest_pop_country = countries [i];
								
							}
							
						}
						
						display_country_details ("LOWEST POPULATION 2023", 
											      first_lowest_pop_country, 
												  first_lowest_pop_country.get_population_2023 (), 
												  "people", 
												  true );
				}
				
				
				// the folloowing function will loop throught the countries and determine a country which has the highest poupaltion density amongest the countries
				void Extreme_value_countries::find_highest_population_density () const {
					
					Country_class high_dense_country = countries [0];
					
						for ( size_t i = 1; i < countries.size (); i++) {
							
							if (countries [i].get_population_density () > high_dense_country.get_population_density()) {
								
								high_dense_country = countries [i];
								
							}
							
						}
						
						display_country_details ("HIGHEST POPULATED COUNTRY", 
												 high_dense_country, 
												 high_dense_country.get_population_density(), 
												 "people per square kilometer", 
												 true);
						
				}
				
				
				// the following function will loop throught the countries and determine a country which has the lowest population density among the countries 
				void Extreme_value_countries::find_lowest_population_density () const {
					
					Country_class lower_dense_country  = countries [0];
					
						for (size_t i = 1; i < countries.size(); i++) {
							
							if (countries [i].get_population_density () < lower_dense_country.get_population_density()) {
								
								lower_dense_country = countries [i];
								
							}
							
						}
					
					display_country_details ("LOWEST DENSELY POPULATED COUNTRY", 
											  lower_dense_country, 
											  lower_dense_country.get_population_density(), 
											  "people per square kilometer", 
											  true);
					
				}
				
				
				// the following function will loop hrought the countries and determine a country which has highest birt rate and then it will return it
				void Extreme_value_countries::find_highest_birth_rate () const {
					
					Country_class high_birth_rate_country = countries [0];
					
						for ( size_t i = 1; i < countries.size (); i++) {
							
							if (countries [i].get_growth_rate () > high_birth_rate_country.get_growth_rate()) {
								
								high_birth_rate_country = countries [i];
								
							}
							
						}
						
				display_country_details ("HIGHEST BIRTH RATE",
										  high_birth_rate_country, 
										  high_birth_rate_country.get_growth_rate(),
										  "percent",
										  true);
					
				}
				
				
				
				// the following function will loo through the countries and detrmine a country which has a lowest growth rate and retun it
				void Extreme_value_countries::find_lowest_birth_rate () const {
					
					Country_class lowest_growth_rate = countries [0];
					
						for (size_t i = 1; i < countries.size(); i++) {
							
							if (countries [i].get_growth_rate () < lowest_growth_rate.get_growth_rate()) {
								
								lowest_growth_rate = countries [i];
								
							}
							
						}
						
			display_country_details ("LOWEST BIRTH RATE", 
									  lowest_growth_rate, 
									  lowest_growth_rate.get_growth_rate(),
									  "percent",
									  false);
					
				}
				
				
				// the following function will loop through the cuntries and determine a country which will have largest land area of all the countries
				void Extreme_value_countries::find_largest_land_area () const {
					
					Country_class largest_area = countries [0];
					
						for ( size_t i = 1; i < countries.size (); i++) {
							
							if (countries [i].get_land_area () > largest_area.get_land_area()) {
								
								largest_area = countries [i];
								
							}
							
						}
				display_country_details ("LARGEST LAND AREA", 
										  largest_area,
										  largest_area.get_land_area(),
										  "square kilometers",
										  false);
					
				}
				
				// the following function will loop through the country and identify a country which ahs the smallest land area
				void Extreme_value_countries::find_smallest_land_area () const {
					
					Country_class smallest_area  = countries [0];
					
						for (size_t i = 0; i < countries.size(); i++) {
							
							if (countries [i].get_land_area () < smallest_area.get_land_area()) {
								
								smallest_area = countries [i];
								
							}
							
						}
						
			display_country_details ("SMALLEST LAND AREA", 
									 smallest_area,
									 smallest_area.get_land_area(),
									 "square kilometers",
									 false);
					
				}
				
				// the following is the function to contain the sub menu for this file
				void Extreme_value_countries::extreme_value_countries_menu () const {
					
					cout << "------------------------------------------------------------------------------------------------------------------\n";
					cout << "                                             IDENTIFY A COUNTRY WITH:                                             \n";
					cout << "------------------------------------------------------------------------------------------------------------------\n";
					
						cout << "1. Highest 2023 population \n";
						cout << "2. Lowest 2023 population \n";
						cout << "3. Highest population density \n";
						cout << "4. Lowest population density \n";
						cout << "5. Highest birth rate \n";
						cout << "6. Lowest growth rate \n";
						cout << "7. Largest land area \n";
						cout << "8. Smallest land area \n";
						cout << "0. Exit the program \n";
					
				}
				
				// this will contain the switch and the loop to process and call the functions
				void Extreme_value_countries::run_menu () const {
					
					int choice ;
					
						do {
							
							// calling the function which has the menu in this sub problem
							extreme_value_countries_menu ();
							
							cout << "Enter yout choice (0 - 8): ";
							
							// checking the user input and tryin g to prevent program crush due to invalid data entered
								if (!(cin>>choice)) {
									cin.clear ();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									//throw Invalid_data_entered ("Choice is invalied ");
									cerr << "ERROR: Invalid data entered \n";
									continue;
								}
								
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							
							// because the wsitch can cause an exception erro i decided to put in try catch bloack to catch any error and allow the program to proceed
									try {
										
										switch (choice) {
											
											case 1: {
												// will identify a country with highest population in the year 2023
												
												find_highest_population_2023 ();
											
												break;
											}
											
											case 2: {
												// will identify a country with lowest poluation in the year 2023
												
												find_lowest_population_2023 ();
												
												break;
											}
											
											case 3: {
												// will identify a country with highest population density 
												
												find_highest_population_density();
												
												break;
											}
											
											case 4: {
												// will identify a country with lowets population density 
												
												find_lowest_population_density ();
												
												break;
											}
											
											case 5: {
												// will identify a country which has highest growth rate
												
												find_highest_birth_rate ();
												
												break;
											}
											
											case 6: {
												// will identify a country which lowets groeth rate 
												
												find_lowest_birth_rate ();
												
												break;
											}
											
											case 7: {
												// will a country which has a largest land area 
												
												find_largest_land_area ();
												
												break;
											}
											
											case 8: {
												// wiill identify a country which has a smmallest lad area 
												
												find_smallest_land_area ();
												
												break;
											}
											
											case 0: {
												// the user wants to exit
												cout << "Exiting the program... \n";
												break;
											}
											
											default : {
												
												throw Invalid_data_entered ("Choice should be in the range 0 - 8 ");
												break;
											}
											
										}
										
										
										
									} catch (const exception& e) {
										
										cout << "ERROR: " << e.what() << endl;
										
									}
									
									if (choice != 0) {
										cout << "\n Press enter to continue \n";
										cin.get();
									}
							
							
						}  while (choice != 0);
					
				}
				
				
				// overriding the display_details function from the base class
				void Extreme_value_countries::display_details () const {
					cout << "Loaded => " << countries.size () << " countries "<< endl;
					cout << "Done \n";
				}
		
		