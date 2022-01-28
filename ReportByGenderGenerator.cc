#include <iostream>
using namespace std;
#include "ReportByGenderGenerator.h"
#include <sstream>
#include <iomanip>
#include <cmath>

ReportByGenderGenerator::ReportByGenderGenerator(string s)
 : ReportGenerator(s)
{

}

void ReportByGenderGenerator::execute(string& outStr)
{
  stringstream ss;

  int fGrad, fEmp, mGrad, mEmp; //number of females/males graduated and employed
  float fRate, mRate; //female/male employment rate
  float sub[allYears.size()] = {0}; //temporary array to hold proportions for each degree
  float max[allYears.size()][INNER_ARR] = {0.0f}; //2D array. index "i" year, inner array[][0] for region index and array[][1] for max value
  float ratio;

  //set table header
  ss << endl << "TABLE: " << getName() << endl << setw(15) << "";
  for(int i = 0; i < allYears.size(); ++i)
  	ss << setw(15) << allYears[i]->getValue();
  ss << endl;

  //populate table
  for(int i = 0; i < allDegrees.size(); ++i){
    ss << setw(15) << allDegrees[i]->getValue();
    fGrad = fEmp = mGrad = mEmp = 0;
    //traverse all records
    for(int j = 0; j < allYears.size(); ++j){
  	  for(int k = 0; k < allYears[j]->getSize(); ++k){

  	  	//if record matches degree, increment total females
  	  	if((*allYears[j])[k]->getDegree() == allDegrees[i]->getValue() && (*allYears[j])[k]->getGender() == "Females"){
          fEmp += (*allYears[j])[k]->getNumEmployed();
  	  	  fGrad += (*allYears[j])[k]->getNumGrads();
        }

  	  	//if record matches degree, increment total males
  	  	if((*allYears[j])[k]->getDegree() == allDegrees[i]->getValue() && (*allYears[j])[k]->getGender() == "Males"){
          mEmp += (*allYears[j])[k]->getNumEmployed();
          mGrad += (*allYears[j])[k]->getNumGrads();
        }
  	  	
  	  }
      //female employment rate and ratio
      float fRate = (fGrad == 0) ? 0 : (float) fEmp / fGrad;
      float mRate = (mGrad == 0) ? 0 : (float) mEmp / mGrad;
      ratio = (mRate == 0) ? 0 : fRate / mRate;
      ss << setw(15) << fixed << setprecision(3) << ratio;

      //check if should be added to max array based how far from the ratio 1/1
      if(abs(ratio-1) > max[j][1]){
        max[j][0] = i; //max for year j is region i
        max[j][1] = abs(ratio-1); //max for year j has value abs(sub[j]-1)
      }
    }
  	ss << endl;
  }

  //print final row
  ss << setw(15) << "MAX DIFFERENCE: ";
  for(int i = 0; i < allYears.size(); ++i){
    ss << setw(15) << fixed << setprecision(4) << allDegrees[(int)max[i][0]]->getValue();
  }
  ss << endl;

  //set output
  outStr = ss.str();
}