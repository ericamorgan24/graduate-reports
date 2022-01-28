/*
Purpose:
  An concrete ReportTopBottomGenerator control subclass to generate reports
  for the top 3 and bottom 3 regions for percentage of female graduate for all 
  years and all degrees
Attributes:
  Those inherited from ReportGenerator base class
Functions:
  ReportTopBottomGenerator(string):
    purpose: to create a ReportTopBottomGenerator object
    input: a string for the name of the report the object generates
    output: a ReportTopBottomGenerator object
  void execute(string&):
    purpose: a virtual function used to generate a string of the report
    input: none
    output: a string reference for the report that was generated
*/


#ifndef REPORTTOPBOTTOM_H
#define REPORTTOPBOTTOM_H

#include "ReportGenerator.h"
#include <string>
#define LIMIT 3	//number of top and number of bottom rows

class ReportTopBottomGenerator : public ReportGenerator
{
  public:
  	ReportTopBottomGenerator(string);
    virtual void execute(string&);
};

#endif