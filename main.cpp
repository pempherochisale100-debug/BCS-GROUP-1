#include<iostream>
#include "country_class.h"
#include "Data_manager.h"
#include<string>

using namespace std;

void display_menu ();
//void main_switch ();

int main() {

//	Country_class country (1, "MAL", "malawi", "africa", 2345, 1234, 2345, 2345, 2345, 234, 2345,876, 12345, 234, 2345, 0.34, 234);
//	country.main_switch();



Base_class* ptr  = new Load_data;

//ptr = &Load_data;

//ptr->display_details();

ptr->display_details();	
	
	bool loop_controller = true;
	
//	do {
		
		
		
			display_menu();
			int choice;
			
			cout<<"Enter your choice (0-14) \n";
				cin>>choice;
				
				switch(choice){
					case 1:{
						//loads csv data
						
						cout << "You selected to load csv data from the file \n";
						break;
					}
					case 2 : {
						//display number of countries 
						break;
					}
					case 3: {
						//search countries 
						break;
					}
					case 4:{
						//sort countries
						break;
					}
					case 5:{
						//find max and min values 
						break;
					}
					case 6:{
						//filter countries
						break;
					}
					case 7 :{
						//statistical analaysis
						break;
					}
					case 8:{
						//density classification
						break;
					}
					case 9:{
						//analyse by continent
						break;
					}
					case 10:{
						//population trend analysis
						break;
					}
					case 11:{
						//estimate future population
						break;
					}
					case 12:{
						//compare countries 
						break;
					}
					case 13:{
						//export high population countries to another file
						break;
					}
					case 14:{
						//generate report 
						break;
					}
					case 0:{
						cout<<"Press any key to exit \n";
						//loop_controller = false;
						break;
					}
					default :{
						cout<<"INVALID CHOICE SELECTED, SELECT (0-14) \n";
						break;
					}
				}
			
			
		
		
		
	
	
  











	return 0;
}




	
		void display_menu () {
			cout<<"----MAIN MENU----"<<endl;
			cout<<" 1. Load CSV Data  "<<endl;
			cout<<" 2. Display Nmumber of Countries "<<endl;
			cout<<" 3. Search Countries \n";
			cout<<" 4. Sort Countries \n";
			cout<<" 5. Find maximu /minimum values \n";
			cout<<" 6. Filter countries \n";
			cout<<" 7. Statistical Analysis \n";
			cout<<" 8. Density Classification\n";
			cout<<" 9. Analyses by continent \n";
			cout<<"10. Population Trend Analysis \n";
			cout<<"11. Estimate Future Population \n";
			cout<<"12. Compare Countries \n";
			cout<<"13. Export High-Population Countries \n";
			cout<<"14. Generate Report \n";
			cout<<" 0. Exit \n ";
			
		}
		
	