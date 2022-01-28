/*
Purpose:
  An concrete ReportByDegreeGenerator control subclass to generate reports
  for the employment percentage for each region, by degree, for all 
  years and genders
Attributes:
  Those inherited from ReportGenerator base class
Functions:
  ReportByDegreeGenerator(string):
    purpose: to create a ReportByDegreeGenerator object
    input: a string for the name of the report the object generates
    output: a ReportByDegreeGenerator object
  void execute(string&):
    purpose: a virtual function used to generate a string of the report
    input: none
    output: a string reference for the report that was generated
*/

#ifndef REPORTBYDEGREE_H
#define REPORTBYDEGREE_H

#include "ReportGenerator.h"
#include <string>

class ReportByDegreeGenerator : public ReportGenerator
{
  public:
  	ReportByDegreeGenerator(string);
    virtual void execute(string&);
};

#endif