/*
Purpose:
  An concrete ReportByRegionGenerator control subclass to generate reports
  for the increase in Male Employment for each Region by Year for all Degrees
Attributes:
  Those inherited from ReportGenerator base class
Functions:
  ReportByRegionGenerator(string):
    purpose: to create a ReportByRegionGenerator object
    input: a string for the name of the report the object generates
    output: a ReportByRegionGenerator object
  void execute(string&):
    purpose: a virtual function used to generate a string of the report
    input: none
    output: a string reference for the report that was generated
*/

#ifndef REPORTBYREGION_H
#define REPORTBYREGION_H

#include "ReportGenerator.h"
#include <string>

class ReportByRegionGenerator : public ReportGenerator
{
  public:
  	ReportByRegionGenerator(string);
    virtual void execute(string&);
};

#endif