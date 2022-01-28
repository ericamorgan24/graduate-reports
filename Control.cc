#include <iostream>
using namespace std;
#include "Control.h"
#include "ReportGenerator.h"
#include "ReportByDegreeGenerator.h"
#include "ReportTopBottomGenerator.h"
#include "ReportByYearGenerator.h"
#include "ReportByGenderGenerator.h"
#include "ReportByRegionGenerator.h"
#include <string>
#include <sstream>



Control::Control(string s)
 :name(s)
{

}



void Control::launch()
{

  int choice; 		//users menu choice
  string output;	//report as a string

  //initialize generators
  initGenerators();

  //present menu
  stringstream ss;
  while (1) {
    //print options
    ss << endl << name << endl << endl;
    for(int i = 0; i < generators.size(); ++i){
      ss << "\t(" << i+1 << ") " << generators[i]->getName() << "\n";
    }
    ss << "\t(0) Exit\n\n";
    //get valid option
    do{
      ss << "Enter your selection: ";
      view.printStr(ss.str());
      view.readInt(choice);
      ss.str("");
    }while(choice < 0 || choice > generators.size());
    //complete choice
    if(choice == 0)
      break;
    generators[choice-1]->execute(output);
    view.printStr(output);
  }

  //free memory
  freeGenerators();
}



void Control::initGenerators()
{
  //upload data from file and make collections
  ReportGenerator::initData();

  //create generators
  ReportByDegreeGenerator*    r1 = new ReportByDegreeGenerator("Employment Percentage for each Region by Degree for all Years and Genders");
  ReportTopBottomGenerator*   r2 = new ReportTopBottomGenerator("Top/Bottom 3 Regions for percentage of Female Graduates for all Years and all Degrees");
  ReportByYearGenerator*      r3 = new ReportByYearGenerator("Employment Proportion for each Region by Year for all Degrees and all Genders");
  ReportByGenderGenerator*    r4 = new ReportByGenderGenerator("Female to Male Employment Proportion for each Degree by Year for all Regions");
  ReportByRegionGenerator*    r5 = new ReportByRegionGenerator("Male Employment Increase for each Region by Year for all Degrees");

  //add generators to collection
  generators.push_back(r1);
  generators.push_back(r2);
  generators.push_back(r3);
  generators.push_back(r4);
  generators.push_back(r5);

}



void Control::freeGenerators()
{
  //free memory
  ReportGenerator::freeData();
  for(int i = 0; i < generators.size(); ++i)
    delete generators[i];
}