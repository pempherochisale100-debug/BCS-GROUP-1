#ifndef STATISTICAL_MEASURES_H // Checks if this header has already been included
#define STATISTICAL_MEASURES_H // Defines the header to prevent multiple inclusions

#include "base_class.h" // Includes the Base_class definition for inheritance
#include "country_class.h"
#include "sorting_data.h" // Includes the Country_class to use its objects
#include <vector> // Includes vector library for storing data
#include <string> // Includes string library for text manipulation

using namespace std; // Allows us to use standard library names without std::

class statistical_measures: public Base_class {
 // Declares mean inheriting from Base_class
 
      private:
		// Vector to store all loaded country objects
	    vector<Country_class> countries; 
	    
	    // private helper function to help display the results of each case
	    void help_display_result(const Country_class& c,bool flag, const std::string& label )const;
	    
	    //void help_display_result (const Country_class& c, bool check_type, string& description) const ;
	    
	    void nl () const {
	    	cout << "\n";
		}
	    
	    public:	
	    
	    statistical_measures(const vector<Country_class>&data);
	    
	    
	    
	    
	    // statistical measures for mean
	    void display_details()const override;
	    
	    void display_statistical_menu( );
	    
	    void run_statistical_menu();
	
	    long long pop_2023_mean();
	    
	    
	    double density_mean();
	    
	    
	    double growth_rate_mean();
	    
	    // median statistical measures 
	  void Sort_engine (const std:: vector<Country_class>& data);
	    
	    void display_median();
	    
	    void run_median_menu();
	     void  display_mean_menu();
	     
	     void run_mean_menu();
	    
	    
	    
	    void display_median_menu();
	    
	    long long pop_2010_median();
	    
	    
	    double density_median();
	    
	    
	   double growth_rate_median();
	   
	   // finding minimum and maximum
	   
	   long long pop_1970_max();
	   long long pop_1970_min();
	   
	   double land_area_max();
	   double land_area_min ();
	   
	   
	   double density_max();
	   double density_min ();
	   
	   void display_extremes_menu () ;
	   void run_extremes_menu () ;
	   
	   
	   
	   // finding range
	   
	   long long pop_1970_range();
	   double land_area_range();
	   void display_range();
	   void run_range_menu();
	   
	    
	    
	    
	    

};


#endif
