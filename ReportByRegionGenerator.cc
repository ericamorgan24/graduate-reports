#include <iostream>
using namespace std;
#include "ReportByRegionGenerator.h"
#include <sstream>
#include <iomanip>

ReportByRegionGenerator::ReportByRegionGenerator(string s)
 : ReportGenerator(s)
{

}

void ReportByRegionGenerator::execute(string& outStr)
{
  stringstream ss;
  float prev, cur; //previous and current values of the employment rate for that particular region
  int grad, emp; //number of male grads and employed

  //set table header
  ss << endl << "TABLE: " << getName() << endl 
     << setw(15) << "";
  for(int i = 0; i < allYears.size(); ++i)
  	ss << setw(15) << allYears[i]->getValue();
  ss << endl;

  //populate table
  for(int i = 0; i < allRegions.size(); ++i){
    ss << setw(15) << allRegions[i]->getValue();
    //traverse all records
    for(int j = 0; j < allYears.size(); ++j){
      grad = emp = 0;
  	  for(int k = 0; k < allYears[j]->getSize(); ++k){

  	  	//if record is in region, increment total males
  	  	if((*allYears[j])[k]->getRegion() == allRegions[i]->getValue() && (*allYears[j])[k]->getGender() == "Males"){
          grad += (*allYears[j])[k]->getNumGrads();
          emp += (*allYears[j])[k]->getNumEmployed();
        }	
  	  }
      cur = (grad == 0) ? 0.0f : (float) emp / grad * 100;

      if(j == 0){
        //need previous year 1995 to show difference
        ss << setw(15) << "-";
      }else{
        ss << setw(14) << fixed << setprecision(2) << cur - prev << "%"; 
      }
      prev = cur;
    }
  	ss << endl;
  }

  ss << endl;

  //set output
  outStr = ss.str();
}