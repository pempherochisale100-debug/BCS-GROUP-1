

#ifndef FUTURE_ESTIMATION_H // Checks if this header has already been included



#define FUTURE_ESTIMATION_H // Defines the header to prevent multiple inclusions



#include <string>
#include <cctype>
#include <cstring>

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "base_class.h"
#include "Data_manager.h"
#include "country_class.h"
#include "search_engine.h"

using namespace std;

class future_estimation: public Base_class {
	
	private:
		
		 vector<Country_class> countries; 
		 
		 
		 
		 public:
		 	
		 	string to_lower_case (const string& text);
		 	
		 	future_estimation(const vector<Country_class>&data);
		 	
		 	void estimate (string name) ;
		 	
		 	void display_menu(); // displays the message to prompt the user to pick the country they want 
		 	void run_menu ();
		 	
		 	void display_details () const override ;
		
};




#endif 