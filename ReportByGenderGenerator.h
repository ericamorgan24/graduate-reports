/*
Purpose:
  An concrete ReportByGenderGenerator control subclass to generate reports
  for the employment ratio of female to male employment for each degree 
  by year for all regions
Attributes:
  Those inherited from ReportGenerator base class
Functions:
  ReportByGenderGenerator(string):
    purpose: to create a ReportByGenderGenerator object
    input: a string for the name of the report the object generates
    output: a ReportByGenderGenerator object
  void execute(string&):
    purpose: a virtual function used to generate a string of the report
    input: none
    output: a string reference for the report that was generated
*/

#ifndef REPORTBYGENDER_H
#define REPORTBYGENDER_H

#include "ReportGenerator.h"
#include <string>
#define INNER_ARR 2 //to be used liked a tupple of 2 numbers for an inner array

class ReportByGenderGenerator : public ReportGenerator
{
  public:
  	ReportByGenderGenerator(string);
    virtual void execute(string&);
};

#endif