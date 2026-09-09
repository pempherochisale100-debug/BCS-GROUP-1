#include <string>
#include <iostream>
#include <limits>
#include "country_class.h"
#include "base_class.h"

	using namespace std;
	
	// the following is the default constructor which we will use to initialise the data members with 
	// some default values 
	
	Country_class::Country_class (int rnk, string cc, string cou, string cont, long long pop_2023, long long pop_2022, long long pop_2020,
					  long long pop_2015, long long pop_2010,long long pop_2000, long long pop_1990, long long pop_1980,
					  long long pop_1970, double area, double density, double rate, double percentage) : rank (0), cca3 (""), 
					  country_name (""), continent_name (""), population_2023 (0), population_2022 (0), population_2020 (0),
					  population_2015 (0), population_2010 (0), population_2000 (0), population_1990 (0), population_1980 (0),
					  population_1970 (0), land_area (0.0), population_density (0.0), growth_rate (0.0), world_percentage (0.0) {
					  	
					  	
					  }
					  
	// the following will be the implementation of the setter functins already defined in country_class.h
	
	
		void Country_class::set_rank (int rank){
			if (rank < 0) {
				cerr << "ERROR: Rank of a country is a positive number \n";
				//return 1;
			}
			
			else {
				this->rank = rank;
			}
		}
		
		void Country_class::set_cca3 (string cca3)  {
			if (cca3.length () < 3 || cca3.length() > 3) {
				cerr << "ERROR: This field must have three characters \n";
				//return "1";
			}
			else if (cca3.empty()) {
				cerr << "ERROR: Cca3 can not be empty \n";
				//return "1";
			}
			else {
				this->cca3 = cca3;
			}
		}
		
		void Country_class::set_name (string name) {
			if (name.empty()) {
				cerr << "ERROR: Name of the country is to be filled \n";
				//return "1";
			}
			else {
				this->country_name = name;
			}
		}
		
		void Country_class::set_continent (string continent) {
			if (continent.empty()) {
				cerr << "ERROR: Name of the continent is to be filled \n";
				//return "1";
			}
			else {
				this->continent_name = continent;
			}
		}
		
		void Country_class::set_population_2023 (long long p2023) {
			if (p2023 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_2023 = p2023;
			}
		}
		
		void Country_class::set_population_2022 (long long p2022) {
			
			if (p2022 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_2022 = p2022;
			}
		}
		
		void Country_class::set_population_2020 (long long p2020) {
			if (p2020 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_2020 = p2020;
			}
		}
		
		void Country_class::set_population_2015 (long long p2015) {
			if (p2015 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_2015= p2015;
			}
		}
		
		void Country_class::set_population_2010 (long long p2010) {
			if (p2010 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_2010 = p2010;
			}
		}
		
		void Country_class::set_population_2000 (long long p2000) {
			if (p2000 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_2000 = p2000;
			}
		}
		
		void Country_class::set_population_1990 (long long p1990) {
			if (p1990 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_1990 = p1990;
			}
		}
		
		void Country_class::set_population_1980 (long long p1980) {
			if (p1980 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_1980 = p1980;
			}
		}
		
		void Country_class::set_population_1970 (long long p1970) {
			if (p1970 < 0) {
				cerr << "ERROR: Population cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_1970 = p1970;
			}
		}
		
		void Country_class::set_land_area (double area) {
				if (area < 0) {
				cerr << "ERROR: Area cannot be a negative number \n";
				//return 1;
			}
			else {
				this->land_area = area;
			}
		}
		
		void Country_class::set_population_density (double density) {
			if (density < 0) {
				cerr << "ERROR: Density cannot be a negative number \n";
				//return 1;
			}
			else {
				this->population_density = density;
			}
		}
		
		void Country_class::set_growth_rate (double rate) {
				if (rate < -9 || rate >5) {
				cerr << "ERROR: Growth Rate Should be in the range of -9 to 5 \n";
				//return 1;
			}
			else {
				this->growth_rate = rate;
			}
		}
		
		void Country_class::set_world_percentage (double percentage) {
			if (percentage< 0) {
				cerr << "ERROR: World Percentage cannot be a negative number \n";
				//return 1;
			}
			else {
				this->world_percentage = percentage;
			}
		}
		
		
		
		
		// the following will be the im[plementation of the getter functions we have already declared 
		
		
		int Country_class::get_rank () {
				return rank;
			
		}
		
		string Country_class::get_cca3 ()  {
			return cca3;
		}
		
		string Country_class::get_name () {
			return country_name;
		}
		
		string Country_class::get_continent () {
				return continent_name;
		}
		
		long long Country_class::get_population_2023 () {
				return population_2023;
		}
		
		long long Country_class::get_population_2022 () {
				return population_2022;
		}
		
		long long Country_class::get_population_2020 () {
				return population_2020;
		}
		
		long long Country_class::get_population_2015 () {
				return population_2015;
		}
		
		long long Country_class::get_population_2010 () {
				return population_2010;
			
		}
		
		long long Country_class::get_population_2000 () {
				return population_2000;
		}
		
		long long Country_class::get_population_1990 () {
				return population_1990;
		}
		
		long long Country_class::get_population_1980 () {
				return population_1980;
		}
		
		long long Country_class::get_population_1970 () {
				return population_1970;
		}
		
		double Country_class::get_land_area () {
				return land_area;
		}
		
		double Country_class::get_population_density () {
				return population_density;
		}
		
		double Country_class::get_growth_rate () {
				return growth_rate;
		}
		
		double Country_class::get_world_percentage () {
			return world_percentage;
		}
		
		
		
		
		void Country_class::display_menu () {
			cout<<"----MAIN MENU----"<<endl;
			cout<<" 1. Load CSV Data  "<<endl;
			cout<<" 2. Display Nmumber of Countries "<<endl;
			cout<<" 3. Search Countries \n";
			cout<<" 4. Sort Countries \n";
			cout<<" 5. Find maximu /minimum values \n";
			cout<<" 6. Filter countries \n";
			cout<<" 7. Statistical Analysis \n";
			cout<<" 8. Density Classification\n";
			cout<<" 9. Analyses by continent \n";
			cout<<"10. Population Trend Analysis \n";
			cout<<"11. Estimate Future Population \n";
			cout<<"12. Compare Countries \n";
			cout<<"13. Export High-Population Countries \n";
			cout<<"14. Generate Report \n";
			cout<<" 0. Exit \n ";
			
		}
		
		void Country_class::main_switch () {
			display_menu();
			int choice;
			cout<<"Enter your choice (0-14) \n";
			cin>>choice;
			switch(choice){
				case 1:{
					//loads csv data
					
					cout << "You selected to load csv data from the file \n";
					break;
				}
				case 2 : {
					//display number of countries 
					break;
				}
				case 3: {
					//search countries 
					break;
				}
				case 4:{
					//sort countries
					break;
				}
				case 5:{
					//find max and min values 
					break;
				}
				case 6:{
					//filter countries
					break;
				}
				case 7 :{
					//statistical analaysis
					break;
				}
				case 8:{
					//density classification
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
					break;
				}
				case 13:{
					//export high population countries to another file
					break;
				}
				case 14:{
					//generate report 
					break;
				}
				case 0:{
					cout<<"Press any key to exit \n";
					break;
				}
				default :{
					cout<<"INVALID CHOICE SELECTED, SELECT (0-14) \n";
					break;
				}
			}
			
			
		}
		
		
		void Country_class::display_country_details () {
			
		}
		
		
		
		
		
		