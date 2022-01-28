/*
Purpose:
  A View class to control the input and output to user
Attributes:
  None
Functions:
  void printStr(string):
    purpose: prints information to the user from the Control object
      in order to interact with menu
    input: string to be displayed in terminal
    output: none
  void readInt(int&):
    purpose: to read int input from the user, i.e. numbers
    input: an integer reference to hold the number the user inputs
    output: none
*/

#ifndef VIEW_H
#define VIEW_H

class View
{
  public:
    void printStr(string) const;
    void readInt(int&) const;
};

#endif