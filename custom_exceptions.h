		
#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

		
		
		
		
		#include <iostream>
		#include <string>
		#include <exception>
		
		
			using namespace std;
			
		// the following are the exceptions which will  be of invalid data entered by the user	
		class Invalid_data_entered : public exception {
			
			private:
				
				string message; //this will be used to store the message
				
			public:
				
				Invalid_data_entered (const string& msg) : message (msg) {
					message = "Data you entered is Invalid \n";
				}
				
				const char* what () const noexcept override {
					return message.c_str();
				}
			
			
			
			
			
		};
		
		// the following class will handle exceptions of country not found 
		class Country_not_found : public exception  {
			
			private:
				string message;
				
			public:
				
				Country_not_found (const string& text) {
					message = "Country not found!!!! \n";
				}	
				
				const char* what () const noexcept override {
					return message.c_str ();
				}
		};	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
#endif























