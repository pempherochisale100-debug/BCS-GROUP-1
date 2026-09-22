#include "Analysis_engine.h"
#include <iomanip>

AnalysisEngine::AnalysisEngine(vector<Country_class>data){
	// save the data into our private variable
	countries=data;
}

// ======FILTER COUNTRIES======//
void AnalysisEngine::filterCountries()const{
	cout << "\n========================FILTERED  COUNTRIES======================================" << endl;
	
	cout << "CONDTIIONS: POPULATION > 100000000, DENSITY > 500,GROWTH > 2%, LAND AREA > 1000 000 kmÅ"<<endl;
	
	cout << "=================================================================================== " << endl;
	
	//use an integer counter  starting at 0
	int matchCount = 0;
	
	for (int i= 0;i<countries.size();i++) {
		
		
		if (countries[i].get_population_2023() > 100000000 || 
	    	countries[i].get_population_density() >  500   ||
			countries[i].get_growth_rate() > 2.0 ||
			countries[i] .get_land_area() >1000000) {
				
				cout<<countries[i].get_name()<<endl;
				matchCount++;
			} 
	}
	if (matchCount== 0){
		cout << "No countries met these criteria" << endl;
	}
	else{
		cout << "\n total countries found:" << matchCount << endl;
	}
	
	cout << "=================================================================================== " << endl;
}





// ======DENSITY CLASSIFICATIONS=====//
void AnalysisEngine::classifyDensity() const{
	
	int lowCount = 0;
	int mediumCount = 0;
	int highCount =0;
	
	// use for loop  to look  at every single country in our vector one by one
	 for (int i= 0; i < countries.size(); i++){
	 	
	 	double density= countries[i].get_population_density();
	 	
	 	// check all  conditions given
	 	if (density<100){
	 		lowCount++;
	 	
		 }
		 else if (density >= 100 && density < 500){
		 	mediumCount++;
		 	
		 }
		 else{
		 	highCount++;
		 }
		
	 }
	 // print  the results
	 
	 cout<<"\n==================Density Classfiaction=============="<<endl;
	 
	 cout << "low(under 100)      : " << lowCount << " countries " << endl;
	 cout << "Medium(100-499)     : " << mediumCount << "countries" << endl;
	 cout << "High(500 and above) : " << highCount << "countries" << endl;
	 
	 cout<<"\n ====================================================="<<endl;
	 
	 }
	 
	 //===== ANALYSE POPULATION GROWTH======//
	  
	 void AnalysisEngine::analysePopulationGrowth() const{
	 	
	 	//make sure the data exist
	 	if(countries.size()==0){
	 		cout<<"No data loaded"<<endl;
	 		return;
		 }
		 
		 string largestAbsName=countries[0].get_name();
		 long long largestAbsChange=countries[0].get_population_2023()-countries[0].get_population_1970();
		 
		 string smallestAbsName=countries[0].get_name();
		 long long smallestAbsChange=countries[0].get_population_2023()-countries[0].get_population_1970();
		 
		 string largestPercName=countries[0].get_name();
		 double largestPercChange=0;
		 
		 // loop from all countries starting  from second one
		 for (int i=1;i<countries.size();i++){
		 	long long pop1970=countries[i].get_population_1970();
		 	long long pop2023=countries[i].get_population_2023();
		 
		 
		 // claculate absolute and percentage change for current countries
		 long long absoluteChange=pop1970-pop2023;
		 
		 double percentageChange=0.0;
		 if(pop1970>0){
		 
		  percentageChange=((double)absoluteChange/pop1970)*100;
		 
		 }
		 
		 // check largest absolute increase
		 if(absoluteChange > largestAbsChange){
		 
		 
		 	largestAbsChange=absoluteChange;
		 	largestAbsName= countries[i].get_name();
		 }
		 
		 // check smallest absolute increases
		  if(absoluteChange <smallestAbsChange){
		  	
		  	smallestAbsChange=absoluteChange;
		  	smallestAbsName=countries[i].get_name();
		  }
		  	
			  
			  //check largest percentage increase
			  if (i==1){
			  	largestPercChange=percentageChange;
			  }
			  
			  if(percentageChange > largestPercChange)
			  
			  	largestPercChange=percentageChange;
			  	largestPercName=countries[i].get_name();
			  }
			  
			  // print results
			  cout<<"\n============================Global population Growth(1970 t0 2023)==========================="<<endl;
			  cout << "Largest absolute increase        : " << largestAbsName << " + " << largestAbsChange << "people" << endl;
			  cout << "Smallest absolute increase       : " << smallestAbsName << " + " << smallestAbsChange << "people" << endl;
			  cout << "Largest percentage increase      : " << largestPercName << " + " << largestPercChange << "%" << endl;
			  
			  }
	 
	 
	 void AnalysisEngine::display_details()const{
	 	cout<<"analysis engine is ready"<<endl;
	 }
	 
	 
	 