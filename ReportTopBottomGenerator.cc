#include <iostream>
using namespace std;
#include "ReportTopBottomGenerator.h"
#include <iomanip>

ReportTopBottomGenerator::ReportTopBottomGenerator(string s)
 : ReportGenerator(s)
{

}

void ReportTopBottomGenerator::execute(string& outStr)
{
  stringstream  ss;
  int   fem; //number of female graduates
  int   all; //number of all graduates
  float tot; //percentage for a single region
  vector<float> percentages; //keeps track of the percentage for each region
  vector<int>   regionIndex; //keeps track of the index of each region ordered by percentage


  //traverse all records and fill collections of female graduates percentages and order
  for(int i = 0; i < allRegions.size(); ++i){
    all = 0;
  	fem = 0;
    for(int j = 0; j < allRegions[i]->getSize(); ++j){
      if((*allRegions[i])[j]->getGender() == "Females")
        fem += (*allRegions[i])[j]->getNumGrads();
      else if((*allRegions[i])[j]->getGender() == "All")
      	all += (*allRegions[i])[j]->getNumGrads();
  	}
  	//calculate percentage for this region
  	tot = (all == 0) ? 0.0f : (float) fem / all * 100;
    percentages.push_back(tot);
    //find index where to add this region's index in order of percentage
    int j = 0;
    for(; j < regionIndex.size(); ++j){
    	if(tot < percentages[regionIndex[j]]){
    		break;
    	}
    }
    regionIndex.insert(regionIndex.begin()+j, i); //insert region "i" at specified position
  }

  //make string
  //check in case limit (e.g.top 3) is higher than number of regions
  int numRows = (allRegions.size() < LIMIT) ? allRegions.size() : LIMIT;
  ss << endl << "TABLE: " << getName() << endl; 
  ss << "TOP 3" << endl;
  for(int i = regionIndex.size()-1; i >= regionIndex.size() - numRows; --i){
  	ss << setw(15) << allRegions[regionIndex[i]]->getValue() 
  	   << setw(14) << fixed << setprecision(2) << percentages[regionIndex[i]] << "%" << endl;
  }
  ss << "BOTTOM 3" << endl;
  for(int i = 0; i < numRows; ++i){
  	ss << setw(15) << allRegions[regionIndex[i]]->getValue() 
  	   << setw(14) << fixed << setprecision(2) << percentages[regionIndex[i]] << "%" << endl;
  }
  ss << endl;

  //set output
  outStr = ss.str();
}