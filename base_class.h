#ifndef BASE_CLASS_H
#define BASE_CLASS_H


	#include <iostream>
	#include <string>
	
	
		using namespace std;
		
			class Base_class {
					
				public:
					
					// the following are declarations for pure virtual functions to be used trhoughout the project
					// every entity which has to display information has to override this pure virtual function
					
					virtual void display_details () const = 0;
					
					
					virtual ~Base_class () ;
					
					
					
					
					
			};
		
		
		
		
		
		
		
		
		
#endif