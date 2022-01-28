README

Program Author:
  Erica Morgan (101015691)
Purpose:
  This program manages runs a system of report generators.
  This program uses NGS data in grad.dat to generate different types of reports.
  The user will be presented a menu and prompted to select the type of report they want, 
  then the program will generate that report and print it to the terminal.
Source Files:
  main.cc
  Control.cc
  View.cc
  Record.cc
  ReportGenerator.cc
  ReportByDegreeGenerator.cc
  ReportByGenderGenerator.cc
  ReportByRegionGenerator.cc
  ReportByYearGenerator.cc
  ReportTopBottomGenerator.cc
Header Files:
  Property.h
  Control.h
  View.h
  Record.h
  ReportGenerator.h
  ReportByDegreeGenerator.h
  ReportByGenderGenerator.h
  ReportByRegionGenerator.h
  ReportByYearGenerator.h
  ReportTopBottomGenerator.h
Additional Files:
  Makefile
  README.txt
  FinalUML.pdf
  grad.dat
Instructions:
  Download tar file
  Go to directory where tar file is located
  Extract files with command: tar -xvf final.tar
  Compile and link program using Makefile command: make
  Run program using command: ./main
Explanation of Additional Reports:
  1. ReportByGenderGenerator.cc
     This report is meant to highlight the differences in employment that exist
     between male and female genders. The data is presented as a table with the 
     rows labeled with the type of degree and the columns labeled with the year.
     This report generator will traverse the collection of records and compute 
     the male and female employment percentage for a given year and degree in 
     all regions, and then compute the ratio between the two. The program presents 
     a table showing this ratio, followed by a row that shows the degree with the 
     largest difference in employment between genders for that given year. This 
     report is unique because it requires keeping track of the maximum value in each 
     column. Its different from require 2.2 for top/bottom 3, because the latter was kept 
     in sorted order then used to print the first 3, and last 3 percentages. However, for this report, I am 
     only keeping the maximum value, which requires doing a check everytime a new 
     cell in the table is calculated. This presents a new challenge, because the data 
     is being printed by rows or regions, but the maximum must be tracked for every column 
     of years. The report also is unique from a non-coding 
     perspective because it allows us to compare between groups as opposed to only 
     viewing the statistics for a single group.

  2. ReportByRegionGenerator.cc
     This report shows how the employment rates for men change with the years. 
     It compares the given year with the previous year a collection was done. 
     It shows the percentage increase or decrease in the male employment rate for 
     given region for all degrees. This report is unique because it requires keeping track of 
     the previous calculation. It also presents the data in terms of differences rather than 
     proportions.









