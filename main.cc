/*
Purpose:
  This program manages runs a system of report generators.
  This program uses NGS data in grad.dat to generate different types of reports.
  The user will be presented a menu and prompted to select the type of report they want, 
  then the program will generate that report and print it to the terminal.
Usage:
  Command line arguments:
    $ make
    $ ./main
  The program will prompt user for a menu option then generate the corresponding report.
Author:
  Erica Morgan 101015691
Revisions:
  None
*/

#include <iostream>
using namespace std;
#include "Control.h"

int main()
{
  Control control("ERICA'S EMPLOYMENT DATABASE");
  control.launch();
  return 0;
}