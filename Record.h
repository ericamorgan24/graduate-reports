/*
Purpose:
  A Record entity class that holds the information of a single line in grad.dat
Attributes:
  year: an int for the year in the line
  region: a string for the region in the line
  degree: a string for the degree in the line
  gender: a string for the gender in the line
  numEmployed: an int for the number of employed people in the line
  numGrads: an int for the number of graduates in the line
Functions:
  Record(int, string, string, string, int, int):
    purpose: constructor for a Record object
    input: an int for year, strings for region, degree, and gender, and ints for 
    numEmployed and numGrads
    output: a Record object
  int getYear():
    purpose: to get year of the record
    input: none
    output: an int for the year
  string getRegion():
    purpose: to get region of the record
    input: none
    output: a string for the region
  string getDegree():
    purpose: to get degree of the record
    input: none
    output: a string for the region
  string getGender():
    purpose: to get gender of the record
    input: none
    output: a string for the gender
  int getNumEmployed():
    purpose: to get number of employed people of the record
    input: none
    output: an int for the number of employed people
  int getNumGrads():
    purpose: to get number of grads of the record
    input: none
    output: an int for the number of grads
*/

#ifndef RECORD_H
#define RECORD_H

class Record
{
  public:
  	Record(int, string, string, string, int, int);
    int getYear() const;
    string getRegion() const;
    string getDegree() const;
    string getGender() const;
    int getNumEmployed() const;
    int getNumGrads() const;

  private:
    const int     year;
    const string  region;
    const string  degree;
    const string  gender;
    const int     numEmployed;
    const int     numGrads;
};

#endif