#include <iostream>
using namespace std;
#include "ReportByYearGenerator.h"
#include <sstream>
#include <iomanip>

ReportByYearGenerator::ReportByYearGenerator(string s)
 : ReportGenerator(s)
{

}

void ReportByYearGenerator::execute(string& outStr)
{
  stringstream ss;
  int tot[allYears.size()] = {0}; //total number of employed for each year in all "CAN"

  //set table header
  ss << endl << "TABLE: " << getName() << endl << setw(15) << "";
  for(int i = 0; i < allYears.size(); ++i)
  	ss << setw(15) << allYears[i]->getValue();
  ss << endl;

  //count total employed in CAN for all genders in each year
  for(int i = 0; i < allYears.size(); ++i){
  	for(int j = 0; j < allYears[i]->getSize(); ++j){
  	  if((*allYears[i])[j]->getRegion() == "CAN" && (*allYears[i])[j]->getGender() == "All"){
  	    tot[i] += (*allYears[i])[j]->getNumEmployed();
  	  }
  	}
  }

  //populate table
  for(int i = 1; i < allRegions.size(); ++i){ //start from 1 to exclude CAN
    ss << setw(15) << allRegions[i]->getValue();

    //traverse all records
    for(int j = 0; j < allYears.size(); ++j){
      int subtot = 0; //total employed in that region and year
  	  for(int k = 0; k < allYears[j]->getSize(); ++k){

  	  	//if record matches region and is for all genders, increment subtotal numbers
  	  	if((*allYears[j])[k]->getRegion() == allRegions[i]->getValue() && (*allYears[j])[k]->getGender() == "All"){
  	  	  subtot += (*allYears[j])[k]->getNumEmployed();
  	  	}
  	  }
      ss << setw(14) << fixed << setprecision(2) << (tot[j] == 0 ? 0.0f : (float)subtot/tot[j]*100) << "%";
    }
  	ss << endl;
  }
  ss << endl;

  //set output
  outStr = ss.str();
}