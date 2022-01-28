/*
Purpose:
  A Control class used to launch the program and control which functions to call
Attributes:
  name: a string for the name of this report system
  generators: a collection of generator objects used to make reports
  view: a View object to interact with user for output to and input from user
Functions:
  Control(string):
    purpose: constructor for a Control object
    input: a string for the name of the book Report System
    output: a Control object
  void launch():
    purpose: to get the program running so the user can select a report to generate
    input: none
    output:none
  void initGenerators():
    purpose: to initialize the generator objects used for the report
    input: none
    output: none   
  void freeGenerators():
    purpose: to deallocate memory of the reports that were initialized
    input: none
    output: none
*/

#ifndef CONTROL_H
#define CONTROL_H

#include "ReportGenerator.h"
#include "View.h"
#include <vector>

class Control
{
  public:
  	Control(string);
    void launch();

  private:
  	string                      name;
  	vector<ReportGenerator*> 	generators;
  	View						view;
  	void initGenerators();
  	void freeGenerators();
};

#endif
