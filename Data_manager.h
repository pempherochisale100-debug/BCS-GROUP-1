#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

		
		#include <string>
		#include <vector>
		#include <fstream>
		#include <sstream>
		#include <iostream>
		
		using namespace std;


			class Load_data : public Base_class {
				
				
				private:
					
					vector<Country_class> country;
					
					bool check_loading_status = true;
					
				public:
					
					Load_data () : check_loading_status (false) {
						
					}
					void load_data (const string& fileName) {
						
					
						
					ifstream in_file;
					in_file.open(fileName);
					
						if (!in_file) {
							cerr << "ERROR: Failed to open the file \n";
						}
						
					string line;//this variable will store a line extracted from the file
					int line_count; // to keep track of thed line count
					
					// we are skipping the first line (header of thed file)
					getline (in_file, line);
					line_count = 0;
					
					
					
					// read line by line form the csv file
					while (getline (in_file, line)) {
						
						line_count++;
						
						if (line.empty()){
							continue;
						}
						
						string value; // to store a single entity from the line extracted 
						
						vector<string> individual_fields; // to store individual entities from the extracted line
						
						stringstream ss (line);
						
						
							
							string field;
							
							// copying comma separated items into the vector
							while (getline (ss, field, ',')) {
								individual_fields.push_back(field);
								
							}
							
							
							// we are explicitly converting hte string value at the first index to the int datatype (RANK)
							int rank = stoi(individual_fields[0]);
							
							// passing string values to the respective variables because they are already strings
							string cca3 = individual_fields[1];
							string country_name = individual_fields[2];
							string continent = individual_fields [3];
							
							
							// explicit coverting string to double because they are created as doubles in the country class
							long long pop23 = stoll (individual_fields[4]);
							long long pop22 = stoll (individual_fields[5]);
							long long pop20 = stoll (individual_fields[6]);
							long long pop15 = stoll (individual_fields[7]);
							long long pop10 = stoll (individual_fields[8]);
							long long pop00 = stoll (individual_fields[9]);
							long long pop90 = stoll (individual_fields[10]);
							long long pop80 = stoll (individual_fields[11]);
							long long pop70 = stoll (individual_fields[12]);
							
							
							// explicit converting to doubles because they are doubles in the country class
							double area = stod (individual_fields[13]);
							double density = stod (individual_fields[14]);
							double rate = stod (individual_fields[15]);
							double percentage = stod (individual_fields[16]);
							
							
							// creating a country_class object and initializing it with values get from the fields 
							Country_class c (rank, cca3, country_name, continent, pop23,
													pop22, pop20, pop15, pop10, pop00, pop90,
													pop80, pop70, area, density, rate, percentage);
													
							
							
							// adding a country object to the main country class vector						
							country.push_back(c);
							
							
							
							
							
							
							
							
						}
					
					if(in_file.eof()){
							cout<<"The end of the file is reached!!!"<<endl;
						}	
						
									in_file.close ();
									
									
						cout << "SUCCESS: Data has been loaded from " << fileName << endl;
						cout << "It has total objects = " << country.size() << endl;
						
					}
						
						
			void display_details () override {
				string file_name = "world_population_data.csv";
				load_data (file_name);
			}
						
					
			};






#endif