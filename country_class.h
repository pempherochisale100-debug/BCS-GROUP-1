#ifndef COUNTRY_CLASS_H
#define COUNTRY_CLASS_H

	#include <string>
	using namespace std;
	
	
	class Country_class {
		
		private:
			
			// the following data members are declared as private to protect them from unauthorised access and modifications
			// they will be used to store data loaded from the csv file 
			int rank;
			string cca3, country_name, continent_name;
			
			long long population_2023, population_2022, population_2020;
			long long population_2015, population_2010, population_2000;
			long long population_1990, population_1980, population_1970;
			
			double land_area, population_density, growth_rate, world_percentage;
			
	public:
		
		// the following will our constkructo to the data members with some defaults 
		
		Country_class (int rnk, string cc, string cou, string cont, long long pop_2023, long long pop_2022, long long pop_2020,
					  long long pop_2015, long long pop_2010,long long pop_2000, long long pop_1990, long long pop_1980,
					  long long pop_1970, double area, double density, double rate, double percentage);
					  
					  
		// the following will be declarations of getters and setters 
		
		void set_rank (int rank);
		void set_cca3 (string cca3) ;
		void set_name (string name);
		void set_continent (string continent);
		void set_population_2023 (long long p2023);
		void set_population_2022 (long long p2022);
		void set_population_2020 (long long p2020);
		void set_population_2015 (long long p2015);
		void set_population_2010 (long long p2010);
		void set_population_2000 (long long p2000);
		void set_population_1990 (long long p1990);
		void set_population_1980 (long long p1980);
		void set_population_1970 (long long p1970);
		void set_land_area (double area);
		void set_population_density (double density);
		void set_growth_rate (double rate);
		void set_world_percentage (double percentage);
		
		// the following definitions are of getters of these set private member attributes
		
		int  get_rank ();
		string get_cca3 () ;
		string get_name ();
		string get_continent ();
		long long get_population_2023 ();
		long long get_population_2022 ();
		long long get_population_2020 ();
		long long get_population_2015 ();
		long long get_population_2010 ();
		long long get_population_2000 ();
		long long get_population_1990 ();
		long long get_population_1980 ();
		long long get_population_1970 ();
		double get_land_area ();
		double get_population_density ();
		double get_growth_rate ();
		double get_world_percentage ();
		
		void display_menu ();
		void main_switch ();
		
		void display_country_details ();
		
			
			
			
			
		
		
		
		
		
	};
	
	
	
	
	
	
	
#endif