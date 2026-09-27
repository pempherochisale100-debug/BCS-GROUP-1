#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Data_manager.h"
#include "country_class.h"
#include "custom_exceptions.h"

using namespace std;

// Constructor
Load_data::Load_data () : check_loading_status (false) {
	
}

// Getter — return the internal vector
const vector<Country_class>& Load_data::get_countries () const {
	
 	return country;
 	
}

// trimming will be done here 
// strip trailing % and whitespace


// Count helper
int Load_data::get_countries_count () const {
	
	return country.size();
	
}

// Load CSV

void Load_data::load_data (const string& fileName){

	ifstream in_file;
	in_file.open (fileName);

	if (!in_file) {
		cerr << "ERROR: Failed to open the file " << fileName << endl;
		return;
	}
	

	string line;
	int line_count = 0;

	// skip header
	getline (in_file, line);

try {
	
	
	while (getline (in_file, line)) {

		line_count++;

		if (line.empty()) {
			continue;
		}
		
		vector<string> individual_fields;
		stringstream ss (line);
		string field;

		while (getline (ss, field, ',')) {
			individual_fields.push_back (field);
		}

		if (individual_fields.size() < 17) {
			continue;
		}


	// converting the data from all string to the =ir respective datatypes for storage in the vector and for use 
		int rank           = stoi (individual_fields[0]);
		string cca3        = individual_fields[1];
		string country_name = individual_fields[2];
		string continent   = individual_fields[3];

		long long pop23 = stoll (individual_fields[4]);
		long long pop22 = stoll (individual_fields[5]);
		long long pop20 = stoll (individual_fields[6]);
		long long pop15 = stoll (individual_fields[7]);
		long long pop10 = stoll (individual_fields[8]);
		long long pop00 = stoll (individual_fields[9]);
		long long pop90 = stoll (individual_fields[10]);
		long long pop80 = stoll (individual_fields[11]);
		long long pop70 = stoll (individual_fields[12]);

		double area       = stod (individual_fields[13]);
		double density    = stod (individual_fields[14]);
		double rate       = trim_percent_symbol (individual_fields[15]);
		double percentage = trim_percent_symbol (individual_fields[16]);


		// creating an insatmce of acountry class and feeding it data which is proper format after conversion 
		// we will call it's public constructor for this
		Country_class c (rank, cca3, country_name, continent,
		                 pop23, pop22, pop20, pop15, pop10,
		                 pop00, pop90, pop80, pop70,
		                 area, density, rate, percentage);

// adding a single country per iteration to the country vector per itertaion of the loop 
		country.push_back (c);
	}

	
}catch (const exception& e) {
	 // we will catch the exception an error that can happening when traversing trhough the data set
	cout << "Corrupted line has been detected at line number " << line_count << ", Exiting the program " << e.what () << endl;
}
	in_file.close();
	check_loading_status = true;

	//cout << "SUCCESS: Data has been loaded from " << fileName << endl;
	//cout << "It has total objects => " << country.size() << endl;
}

// Display details
void Load_data::display_details () const{
	
	cout << "Total loaded countries => " << country.size() << endl;
	
}