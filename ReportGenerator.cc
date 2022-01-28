#include <iostream>
using namespace std;
#include "ReportGenerator.h"
#include <fstream>



//static data members
vector<Record*>                ReportGenerator::records;
vector<Property<int>*>         ReportGenerator::allYears;
vector<Property<string>*>      ReportGenerator::allRegions;
vector<Property<string>*>      ReportGenerator::allDegrees;



ReportGenerator::ReportGenerator(string s)
 : name(s)
{

}



string ReportGenerator::getName() const
{
  return name;
}



void ReportGenerator::initData()
{
  ReportGenerator::loadRecords();
  ReportGenerator::addAllPartials();
}



void ReportGenerator::loadRecords()
{
  int year, numEmployed, numGrads;
  string region, degree, gender;
  
  //open file
  ifstream infile("grad.dat", ios::in);
  if (!infile) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }

  //add record for each line of data
  while (infile >> year >> region >> degree >> gender >> numEmployed >> numGrads){
    Record* rec = new Record(year, region, degree, gender, numEmployed, numGrads);
    records.push_back(rec);
  }
}



void ReportGenerator::addAllPartials()
{
  //all other vectors of partial collections will be ordered alphanumerically
  //traverse all records and add to each partial collection
  for (int i = 0; i < records.size(); ++i){
    ReportGenerator::addYears(records[i]);
    ReportGenerator::addRegions(records[i]);
    ReportGenerator::addDegrees(records[i]);
  } 
}



void ReportGenerator::addYears(Record* r)
{
  //add to allYears ordered numerically
  int x = false; //set flag
  int j; //index
  for (j = 0; j < allYears.size(); ++j){
    //if theres a property with that value, add to property's collection
    if (r->getYear() == allYears[j]->getValue()){
      (*allYears[j]) += r;
      x = true;
      break;
    }
    //add position
    else if(r->getYear() < allYears[j]->getValue()){
      break;
    }
  }
  //if property value isn't present, create new property and add
  if(x == false){
    Property<int>* prop = new Property<int>(r->getYear());
    *prop += r;
    allYears.insert(allYears.begin()+j, prop);
  }
}



void ReportGenerator::addRegions(Record* r)
{
  //add to allRegions ordered alphabetically, except "CAN" at front
  int x = false; //set flag
  int j; //index
  for (j = 0; j < allRegions.size(); ++j){
    //if theres a property with that value, add to property's collection
    if (r->getRegion() == allRegions[j]->getValue()){
      (*allRegions[j]) += r;
      x = true;
      break;
    }
    //if there isn't a property with that value, break
    else if(j != 0 && r->getRegion() < allRegions[j]->getValue()){
      break;
    }
  }
  //if property value isn't present, create new property
  if(x == false){
    Property<string>* prop = new Property<string>(r->getRegion());
    *prop += r;
    //exception to add canada as first region
    if(r->getRegion() == "CAN")
      allRegions.insert(allRegions.begin(), prop);
    else
      allRegions.insert(allRegions.begin()+j, prop);
  }

}



void ReportGenerator::addDegrees(Record* r)
{
  //add to allDegrees in order of degree level
  int x = false; //set flag
  int j; //index
  for (j = 0; j < allDegrees.size(); ++j){
    //if theres a property with that value, add to property's collection
    if (r->getDegree() == allDegrees[j]->getValue()){
      (*allDegrees[j]) += r;
      x = true;
      break;
    }
    //if there isn't a property with that value, break
    else if(ReportGenerator::orderDegrees(r->getDegree()) < ReportGenerator::orderDegrees(allDegrees[j]->getValue())){
      break;
    }
  }
  //if property value isn't present, create new property
  if(x == false){
    Property<string>* prop = new Property<string>(r->getDegree());
    *prop += r;
    allDegrees.insert(allDegrees.begin()+j, prop);
  }
}



int ReportGenerator::orderDegrees(string s)
{
  if(s == "College")
    return 0;
  else if(s == "Bachelor's")
    return 1;
  else if(s == "Master's")
    return 2;
  else if(s == "Doctorate")
    return 3;
  else
    return -1;
}



void ReportGenerator::freeData()
{
  for(int i = 0; i < records.size(); ++i)
    delete records[i];
  for(int i = 0; i < allYears.size(); ++i)
    delete allYears[i];
  for(int i = 0; i < allRegions.size(); ++i)
    delete allRegions[i];
  for(int i = 0; i < allDegrees.size(); ++i)
    delete allDegrees[i];
}













