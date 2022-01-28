/*
Purpose:
  An abstract ReportGenerator control base class to generate reports
Attributes:
  name: a string for the name of the report
  records: a collection of Record* for all the records in the file
  allYears: a collection of Property<int>* for for property objects with a year as a value
  allRegions: a collection of Property<string>* for for property objects with a region as a value
  allDegrees: a collection of Property<string>* for for property objects with a degree as a value
Functions:
  ReportGenerator(string):
    purpose: to create a ReportGenerator object
    input: a string for the name of the report the object generates
    output: a ReportGenerator object
  string getName():
    purpose: to return the name of the object
    input: none
    output: a string for the name of the object
  void initData():
    purpose: to initilize the collection of reports and all partial collections
    input: none
    output: none
  void freeData():
    purpose: to free the memory that was allocated when collections were created
    input: none
    output: none
  void execute(string&):
    purpose: a virtual function used to generate a string of the report
    input: none
    output: a string reference for the report that was generated
  void loadRecords():
    purpose: to generate a string of the report
    input: none
    output: a string reference for the report that was generated
  void addAllPartials():
    purpose: makes all partial collections based on the values in the reports
    input: none
    output: none
  void addYears(Record*):
    purpose: to make the partial collection allYears ordered numerically
    input: a Record* for the record being added to the partial collection
    output: none
  void addRegions(Record*):
    purpose: to make the partial collection allRegions ordered alphabetically
    input: a Record* for the record being added to the partial collection
    output: none
  void addDegrees(Record*):
    purpose: to make the partial collection allDegrees ordered by level of education
    input: a Record* for the record being added to the partial collection
    output: none
  int orderDegrees(string):
    purpose: used to order the partial collection allDegrees 
      based on the level of education
    input: a string for the name of the degree
    output: an int for the precedence of the degree
*/

#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>
#include "Record.h"
#include "Property.h"

#define MAX_ARRAY


class ReportGenerator
{
  public:
  	ReportGenerator(string);
    string getName() const;
    static void initData();
    static void freeData();
    virtual void execute(string&) = 0;

  protected: 
    static vector<Property<int>*>         allYears;
    static vector<Property<string>*>      allRegions;
    static vector<Property<string>*>      allDegrees;

  private:
  	const string name;
    static vector<Record*> records;
    static void loadRecords();
    static void addAllPartials();
    static void addYears(Record*);
    static void addRegions(Record*);
    static void addDegrees(Record*);
    static int orderDegrees(string);
};

#endif