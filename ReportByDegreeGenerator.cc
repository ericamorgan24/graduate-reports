#include <iostream>
using namespace std;
#include "ReportByDegreeGenerator.h"
#include <sstream>
#include <iomanip>

ReportByDegreeGenerator::ReportByDegreeGenerator(string s)
 : ReportGenerator(s)
{

}

void ReportByDegreeGenerator::execute(string& outStr)
{
  stringstream ss;
  int tot; //total number of grads for each region

  //set table header
  ss << endl << "TABLE: " << getName() << endl << setw(15) << "";
  for(int i = 0; i < allDegrees.size(); ++i)
  	ss << setw(15) << allDegrees[i]->getValue();
  ss << endl;

  //populate table
  for(int i = 0; i < allRegions.size(); ++i){
  	tot = 0; //total number of grads in a given region
    int sub[allDegrees.size()] = {0}; //array for number of employed with each degree in a single region

    //traverse all records
    for(int j = 0; j < allDegrees.size(); ++j){
  	  for(int k = 0; k < allDegrees[j]->getSize(); ++k){

  	  	//if record is in region and for all genders regardless of year, increment variables
  	  	if((*allDegrees[j])[k]->getRegion() == allRegions[i]->getValue() && (*allDegrees[j])[k]->getGender() == "All"){
  	  	  tot += (*allDegrees[j])[k]->getNumGrads();
  	  	  sub[j] += (*allDegrees[j])[k]->getNumEmployed();
        }
  	  	
  	  }
    }

    //print row
    ss << setw(15) << allRegions[i]->getValue();
    for(int j = 0; j < allDegrees.size(); ++j){
      ss << setw(14) << fixed << setprecision(2) << (tot == 0 ? 0.0f : (float)sub[j]/tot*100) << "%";
  	}
  	ss << endl;
  }
  ss << endl;

  //set output
  outStr = ss.str();
}