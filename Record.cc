#include <iostream>
using namespace std;
#include <iomanip>
#include "Record.h"

Record::Record(int y, string r, string d, string g, int e, int gr)
 : year(y), region(r), degree(d), gender(g), numEmployed(e), numGrads(gr)
{

}

int Record::getYear() const
{
  return year;
}

string Record::getRegion() const
{
  return region;
}

string Record::getDegree() const
{
  return degree;
}

string Record::getGender() const
{
  return gender;
}

int Record::getNumEmployed() const
{
  return numEmployed;
}

int Record::getNumGrads() const
{
  return numGrads;
}