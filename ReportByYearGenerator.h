/*
Purpose:
  An concrete ReportByYearGenerator control subclass to generate reports
  for the employment proportion of each region, by year, for all degrees 
  and all genders
Attributes:
  Those inherited from ReportGenerator base class
Functions:
  ReportByYearGenerator(string):
    purpose: to create a ReportByYearGenerator object
    input: a string for the name of the report the object generates
    output: a ReportByYearGenerator object
  void execute(string&):
    purpose: a virtual function used to generate a string of the report
    input: none
    output: a string reference for the report that was generated
*/

#ifndef REPORTBYYEAR_H
#define REPORTBYYEAR_H

#include "ReportGenerator.h"
#include <string>

class ReportByYearGenerator : public ReportGenerator
{
  public:
  	ReportByYearGenerator(string);
    virtual void execute(string&);
};

#endif