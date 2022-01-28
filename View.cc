#include <iostream>
using namespace std;
#include <string>
#include "View.h"


void View::printStr(string str) const
{
  cout << str;
}

void View::readInt(int& n) const
{
  cin >> n;
}