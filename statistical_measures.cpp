#include "search_engine.h"
#include "base_class.h"
#include "country_class.h"
#include "Data_manager.h"
#include "statistical_measures.h"
#include "sorting_data.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;


statistical_measures::statistical_measures(const vector<Country_class>& data):countries(data){}

void statistical_measures::display_details () const{

	cout<<"statistical measures loaded with "<<countries.size()<<"countries \n";
}

void statistical_measures::display_statistical_menu(){
	
	
	cout<<"------------------------------------------------------------------------------------------------------\n";
	
	cout<<"---------------------------------STATISTICAL MEASURES  ------------------------------------------\n";
	
	cout<<"-------------------------------------------------------------------------------------------------------\n";
	
	cout<<"\n";
	
	cout<<"1. Mean \n";
	
	cout<<"2. Median \n";
	
	cout<<"3. range \n";
	
	cout<<"4. maximum \n";
	
	cout<<"5. minimum \n ";
	
	cout<<"6. standard deviation \n";
}

void statistical_measures::display_mean_menu(){
	
		   	cout << "====================================================================\n";
	   		cout << "                               MEAN MEASURES                         \n";
	   		cout << "====================================================================\n";
	   		
	   			cout << "1. mean for 2023 population \n ";
	   			cout << "2. mean for population density \n ";
	   			cout << "3. mean for growth rate  \n";
	   			cout << "0. Exit the program \n";
}

void statistical_measures ::run_mean_menu(){
		
			int choice=-1;
			
			do {
				// calling the function which has our display menu \
				display_mean_menu ();
				
				cout << "Enter a choice (0-3): ";
					if (!(cin>>choice)) {
						cin.clear ();
						cerr << "Choice you entered is invalid \n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
						cerr<<"invalid input \n";
						choice = -1;
						
						continue;
					}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				try {
					
					switch (choice) {
						case 1: {
							
							
							cout<<" THE MEAN FOR 2023 POPULATION IS : "<<pop_2023_mean()<<endl;
							
				
							
							break;
						}
						
						case 2: {
							
							cout<<"THE MEAN FOR POPULATION DENSITY IS : "<<density_mean()<<endl;
							
							break;
						}
						
						case 3: {
							
							cout<<"THE MEAN FOR THE GROWTH RATE IS : "<<growth_rate_mean()<<endl;
							break;
						}
						case 0:{
							cout<<"returning the statistical measures menu \n";
							break;
						}
						default : {
							throw Invalid_data_entered ("The choice should be between 0 and 3");
							break;
						}
						
					}
					
				}
				catch (const exception& e) {
					throw Invalid_data_entered ("The data you entered is invalid");
				}
				
				if (choice != 0) {
					cout <<" Press enter to continue \n";
					cin.get();
				}
				
			}
			while (choice != 0);
		}


		
long long statistical_measures::pop_2023_mean(){
	
	if(countries.empty()){   //validation if theres no data
		cerr<<"ERROR "<<endl;
		return 0;
	}
	long long sum=0;
	
	for (size_t i=0;i<countries.size ();i++){ // loops through all the countries 
		
		sum=sum+countries[i].get_population_2023(); // gets the population for all countries in 2023 and adds
	}
		long long mean=sum/countries.size();
		
		return mean; // return 2023 population mean 
}

double statistical_measures::density_mean(){
	
	double sum=0;
	
	for(size_t i=0;i<countries.size();i++){ // loops through all countries
		
		sum=sum+countries[i].get_population_density(); // gets density of all countries  and adds 
	}
	double dens_mean=sum/countries.size();
	
	return dens_mean; // returns the mean of the density
}
double statistical_measures::growth_rate_mean(){
	
	double sum=0;
	
	for(size_t i=0;i<countries.size();i++){ // loops through all countries 
		
		sum=sum+countries[i].get_growth_rate(); // get growth rate and adds
	
	}
		double gr_mean=sum/countries.size();
		
		return gr_mean; //returns the mean of the growth rate 
}

void statistical_measures::display_median_menu(){
	
		   	cout << "====================================================================\n";
	   		cout << "                               MEAN MEASURES                         \n";
	   		cout << "====================================================================\n";
	   		
	   			cout << "1. median for 2010 population \n ";
	   			cout << "2. median for growth rate \n ";
	   			cout << "3. median for density  \n";
	   			cout << "0. Exit the program \n";
}
void statistical_measures ::run_median_menu(){
		
			int choice=-1;
			
			do {
				// calling the function which has our display menu \
				display_median_menu ();
				
				cout << "Enter a choice (0-3): ";
					if (!(cin>>choice)) {
						cin.clear ();
						cerr << "Choice you entered is invalid \n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						
					 cerr<<"invalid input \n";
						choice = -1;
						
						continue;
					}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				try {
					
					switch (choice) {
						case 1: {
							
							
							cout<<" THE MEDIAN FOR 2010 POPULATION IS : "<<pop_2010_median()<<endl;
							
				
							
							break;
						}
						
						case 2: {
							
							cout<<"THE MEDIAN FOR GROWTH RATE IS : "<<growth_rate_median()<<endl;
							
							break;
						}
						
						case 3: {
							
							cout<<"THE MEDIAN FOR THE DENSITY IS : "<<density_median()<<endl;
							break;
						}
						case 0:{
							cout<<"returning the statistical measures menu \n";
							break;
						}
						default : {
							throw Invalid_data_entered ("The choice should be between 0 and 3");
							break;
						}
						
					}
					
				}
				catch (const exception& e) {
					throw Invalid_data_entered ("The data you entered is invalid");
				}
				
				if (choice != 0) {
					cout <<" Press enter to continue \n";
					cin.get();
				}
				
			}
			while (choice != 0);
		}




long long statistical_measures::pop_2010_median(){
	
	
	vector<Country_class> sorted_countries_by_2010 = countries;

	sort (sorted_countries_by_2010.begin(), sorted_countries_by_2010.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_population_2010() > b.get_population_2010();
		
	}
	); // gets 2010 population sorted in descending order  
	
	
	
	size_t size= sorted_countries_by_2010.size();
	if(size==0){
		return 0.0;
	}
	long long  median_pop=0.0;
	if(size%2 !=0){
		median_pop=sorted_countries_by_2010[size/2].get_population_2010();
	}
	else{
		long long middle1 =sorted_countries_by_2010[(size/2)-1].get_population_2010();
		long long  middle2 =sorted_countries_by_2010[(size/2)].get_population_2010();
		median_pop=(middle1 + middle2)/2.0; // returns the medina of 2010 population
}


    return median_pop; // returs the median for 2010 population

}
double statistical_measures::growth_rate_median(){
	
	
	vector<Country_class> sort_growth_rate = countries;
	
	sort(sort_growth_rate.begin(), sort_growth_rate.end(),[](const Country_class& a, const Country_class& b){
		return a.get_growth_rate()<b.get_growth_rate();
	}); // gets growth rate sorted in ascending order 

	size_t size= sort_growth_rate.size();
	if(size==0){
		return 0.0;
	}
	double median=0.0;
	if(size%2 !=0){
		median=sort_growth_rate[size/2].get_growth_rate();
	}
	else{
		double middle1 =sort_growth_rate[(size/2)-1].get_growth_rate();
		double middle2 =sort_growth_rate[(size/2)].get_growth_rate();
		median=(middle1 + middle2)/2.0;
		 
	}
	return median; // returns median for the growth rate 
} 

double statistical_measures::density_median(){
	
	
	
	vector<Country_class> sort_by_density = countries;

	sort (sort_by_density.begin(), sort_by_density.end(),
	
	[] (const Country_class& a, const Country_class& b) {
		
		return a.get_population_density()  < b.get_population_density() ;
		
	}
	); // gets density sorted in descending order
	
	
	
	
	size_t size= sort_by_density.size();
	if(size==0){
		return 0.0;
	}
	double median_dens=0.0;
	if(size%2 !=0){
		median_dens=sort_by_density[size/2].get_population_density();
	}
	else{
		double middle1 =sort_by_density[(size/2)-1].get_population_density();
		double middle2 =sort_by_density[(size/2)].get_population_density();
		median_dens=(middle1 + middle2)/2.0;
		 
	}
	return median_dens; // retruns median for density
}



	   void statistical_measures::display_extremes_menu () {
	   		cout << "====================================================================\n";
	   		cout << "                 MAXIMUM AND MINIMUM COUNTRY MEASURES               \n";
	   		cout << "====================================================================\n";
	   		
	   			cout << "1. Population for 1970 \n";
	   			cout << "2. Land area \n";
	   			cout << "3. Density \n";
	   			cout << "0. Exit the program \n";
	   			
	   }
	
		void statistical_measures::run_extremes_menu ()  {
			
			int choice;
			
			do {
				// calling the function which has our display menu \
				display_extremes_menu ();
				
				cout << "Enter a choice (0-3): ";
					if (!(cin>>choice)) {
						cin.clear ();
						cerr << "Choice you entered is invalid \n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						
						cerr<<"invalid input \n";
						choice = -1;
						
						continue;
					}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				try {
					
					switch (choice) {
						case 1: {
							// this case will handle max and min 1970 population of a country identified from the data set
							pop_1970_max () ;
							cout<<endl;
							
							pop_1970_min ();
							cout << endl;
							break;
						}
						
						case 2: {
							// this case will handle the max and min for land area of the identified country
							land_area_min ();
							cout << endl;
							land_area_max ();
							cout << endl;
							
							break;
						}
						
						case 3: {
							// this case will handle the max and min density ofa identified country from the data set
							density_min ();
							nl ();
							density_max();
							nl ();
							break;
						}
						
						case 0: {
							cout << "Press enter to exit the program...\n";
							break;
						}
						
						default : {
							throw Invalid_data_entered ("The choice should be between 0 and 3");
							break;
						}
						
					}
					
				}
				catch (const exception& e) {
					throw Invalid_data_entered ("The data you entered is invalid");
				}
				
				if (choice != 0) {
					cout <<" Press enter to continue \n";
					cin.get();
				}
				
			}
			while (choice != 0);
		}
		
// maxmimum and minimum statistics


 long long statistical_measures::pop_1970_max(){
 	
 	Country_class max_pop = countries[0];
 	
 	for (size_t i = 0; i < countries.size(); i++) {
 		if (countries[i].get_population_1970() > max_pop.get_population_1970()) {
 			max_pop = countries [i];
		 }
	 }
	   	help_display_result (max_pop , true , "maximum 1970 population " );
	   	
	   	return max_pop.get_population_1970();
 }
 
 
 long long statistical_measures::pop_1970_min(){
 	
 	Country_class min_pop = countries[0];
 	
 	for (size_t i = 1; i < countries.size(); i++) {
 		if (countries[i].get_population_1970 () < min_pop.get_population_1970 ()) {
 			min_pop = countries [i];
		 }
	   	help_display_result (min_pop , false , "minimum 1970 population " );
	 }
	 
	 
	   	
	   	return min_pop.get_population_1970();
 }
 
 
 void statistical_measures::help_display_result(const Country_class& c,bool is_max,const std::string& label)const{
 	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
 	cout << (is_max ? "MAX":"MIN") << "  " << label  << "           => " << "country name          ==> " << c. get_name () <<"\n";
 	
 	
 	cout << (is_max ? "MAX":"MIN") << "  " << label  << "           => " << "population for 1970   ==> " << c.get_population_1970() <<"\n";
 	
 	cout<< "                                        => " <<                                                     "Land area             ==> " << c.get_land_area()<<"\n";
 	
 	
 }
 
 
 
 
 
 
 
	   double statistical_measures::land_area_max() {
	   	
	   	if (countries.empty ()) {
	   		throw Invalid_data_entered ("no data is available in this object");
		   }
		   
	   		Country_class max_area = countries [0];
	   		
	   		// loop through the country_class vector and determine the max land area country
	   		for (size_t i = 1; i < countries.size(); i++) {
	   			
	   			if ( countries [i].get_land_area () > max_area.get_land_area ()) {
	   				
	   				max_area = countries [i];
				   }
				   
			   }
			   
	   	help_display_result (max_area , false  , "maximum land area" );
	   	
	   	return max_area.get_land_area();
	   	
	   }
	   double statistical_measures::land_area_min () {
	   	
	   	
	   	if (countries.empty ()) {
	   		throw Invalid_data_entered ("no data is available in this object");
		   }
		   
	   		Country_class min_area = countries [0];
	   		
	   		// loop through the country_class vector and determine the max land area country
	   		for (size_t i = 1; i < countries.size(); i++) {
	   			
	   			if ( countries [i].get_land_area () < min_area.get_land_area ()) {
	   				
	   				min_area = countries [i];
				   }
				   
			   }
			   
	   	help_display_result (min_area, false , "minimum land area" );
	   	
	   	return min_area.get_land_area();
	   	
	   }
	   
	   
	   double statistical_measures::density_max() {
	   	
	   	if (countries.empty ()) {
	   		throw Invalid_data_entered ("no data is available in this object");
		   }
		   
	   		Country_class max_density = countries [0];
	   		
	   		// loop through the country_class vector and determine the max land area country
	   		for (size_t i = 1; i < countries.size(); i++) {
	   			
	   			if ( countries [i].get_population_density () > max_density.get_population_density ()) {
	   				
	   				max_density = countries [i];
				   }
				   
			   }
			   
			   
	   	help_display_result (max_density, false ,  "maximum density");
	   	
	   	return max_density.get_population_density();
	   	
	   }
	   double statistical_measures::density_min () {
	   	
	   		if (countries.empty ()) {
	   		throw Invalid_data_entered ("no data is available in this object");
		   }
		   
	   		Country_class min_density = countries [0];
	   		
	   		// loop through the country_class vector and determine the max land area country
	   		for (size_t i = 1; i < countries.size(); i++) {
	   			
	   			if ( countries [i].get_population_density () < min_density.get_population_density ()) {
	   				
	   				min_density = countries [i];
				   }
				   
			   }
			   
			   
	   	help_display_result (min_density ,false , "minimum density" );
	   	
	   	return min_density.get_population_density();
	   	
	   
	   }
	   
	   
		
		
		
		// finding range 
		
	  void statistical_measures::display_range()  {
	   		cout << "====================================================================\n";
	   		cout << "                                RANGE                               \n";
	   		cout << "====================================================================\n";
	   		
	   			cout << "1. Population for 1970 \n";
	   			cout << "2. Land area \n";
	   			cout << "0. Exit the program \n";
	   			
	   }
	   			void statistical_measures ::run_range_menu() {
		
			int choice=-1;
			
			
			do {
				// calling the function which has our display menu \
				display_range ();
				
				cout << "Enter a choice (0-2): ";
					if (!(cin>>choice)) {
						cin.clear ();
						cerr << "Choice you entered is invalid \n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cerr<<"invalid input \n";
						choice = -1;
						
						continue;
					}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				try {
					
					switch (choice) {
						case 1: {
							
							
							cout<<" THE RANGE FOR 1970 POPULATION IS : "<<pop_1970_range()<<endl;
							
				
							
							break;
						}
						
						case 2: {
							
							cout<<"THE RANGE FOR THE DENSITY IS  : "<<land_area_range()<<endl;
							
							break;
						}
						
						case 0: {
							cout << "Press enter to exit the program...\n";
							break;
						}
						
						default : {
							throw Invalid_data_entered ("The choice should be between 0 and 3");
							break;
						}
						
					}
					
				}
				catch (const exception& e) {
					throw Invalid_data_entered ("The data you entered is invalid");
				}
				
				if (choice != 0) {
					cout <<" Press enter to continue \n";
					cin.get();
				}
				
			}
			while (choice != 0);
		}
		
		
		long long statistical_measures::pop_1970_range() {
			
			return pop_1970_max()-pop_1970_min();
			
		}
		
		double statistical_measures::land_area_range(){
			
			
			return land_area_max()-land_area_min();
		}
		
		
		void statistical_measures::run_statistical_menu()
     {
	
	
	
			int choice=-1;
			
			do {
				// calling the function which has our display menu \
				display_statistical_menu();
					
	cout<<"------------------------------------------------------------------------------------------------------\n";
	
	cout<<"---------------------------------STATISTICAL MEASURES  ------------------------------------------\n";
	
	cout<<"-------------------------------------------------------------------------------------------------------\n";
	
	cout<<"\n";
	
	cout<<"1. Mean \n";
	
	cout<<"2. Median \n";
	
	cout<<"3. range \n";
	
	cout<<"4. maximum \n";
	
	cout<<"5. minimum \n ";
	
	cout<<"6. standard deviation \n";

				
				cout << "Enter a choice (0-6): ";
					if (!(cin>>choice)) {
						cin.clear ();
						cerr << "Choice you entered is invalid \n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cerr<<"invalid input \n";
						choice = -1;
						
						continue;
					}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				try {
					
					switch (choice) {
						case 1: {
							display_mean_menu();
							run_mean_menu() ;
				
							
							break;
						}
						
						case 2: {
							display_median_menu();
							run_median_menu();
							
							break;
						}
						
						case 3: {
							
							display_range() ;
							run_range_menu();
						
							break;
						}
						case 4:{
							display_extremes_menu ();
							
							run_extremes_menu () ;
							break;
						}
						case 5:{
							display_extremes_menu ();
							run_extremes_menu () ;
							break;
						}
						case 6:{
							
							break;
						}
						case 0:{
							cout<<"returning the statistical measures menu \n";
							break;
						}
						default : {
							throw Invalid_data_entered ("The choice should be between 0 and 3");
							break;
						}
						
					}
					
				}
				catch (const exception& e) {
					throw Invalid_data_entered ("The data you entered is invalid");
				}
				
				if (choice != 0) {
					cout <<" Press enter to continue \n";
					cin.get();
				}
				
			}
			while (choice != 0);
		}
		
	
	




