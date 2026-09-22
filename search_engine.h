#ifndef SEARCH_ENGINE_H // Checks if this header has already been included
#define SEARCH_ENGINE_H // Defines the header to prevent multiple inclusions

#include "base_class.h" // Includes the Base_class definition for inheritance
#include "country_class.h" // Includes the Country_class to use its objects
#include <vector> // Includes vector library for storing data
#include <string> // Includes string library for text manipulation

using namespace std; // Allows us to use standard library names without std::

class Search_engine : public Base_class {
 // Declares Search_engine inheriting from Base_class
 
 
		// Vector to store all loaded country objects
	    vector<Country_class> countries; 
 
	public:
		
		
		string toLower(string str) const; 
		// Declaration of helper function to lowercase strings
		
	    void search_by_name( string& name) const; 
		// Declaration of function to search by name
		
	    void search_by_cca3( string& code) const; 
		// Declaration of function to search by CCA3
		

 // Start of public members (accessible from main.cpp)
 
    Search_engine(const vector<Country_class>& data); 
	// Constructor declaration
	
    void search_menu() const;
	 // Declaration of function to handle user menu
	 
    void display_details() const override;
	 // Overrides the pure virtual function from Base_class
	 
};


 // End of Search_engine class
#endif // End of the preprocessor guard