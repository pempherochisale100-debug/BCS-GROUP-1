#ifndef BASE_CLASS_H
#define BASE_CLASS_H


	#include <iostream>
	#include <string>
	
	
		using namespace std;
		
			class Base_class {
				private:
					
					// we will force every derived class to have the following attributes
					string cca3;
					string country_name;
					
				public:
					// every derived class will be forced to ovveride the following functions
					
					// the following is a public constructor to set the values of the members
					Base_class (string cc, string name);
					
					virtual void display_information () override = 0;
					virtual void get_population () override = 0;
					
					virtual ~Base_class () ;
					
					
					
					
					
			};
		
		
		
		
		
		
		
		
		
#endif