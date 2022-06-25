//---------------------------------------------------------------------------------------------------------------------
//File Name:        Standards.h
//Associated File:  Standards.cpp
//Contains:
//  preprocessor directives for I/0, string, and formatting
//  OutputDivider
//  OuputHeading
//---------------------------------------------------------------------------------------------------------------------

#ifndef Standards_h
#define Standards_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Constant variables for the Course Heading
const string COLLEGE = "SUNY Broome Community College";
const string PROGRAMMER_NAME = "Parjan Ameen";
const string CLASS_LAB_NAME = "CST 202";

//Width of screen for divider
const int WIDTH = 90;

//Variable for the divider
const char SYMBOL = '-';

//Setting divider function
void OutputDivider(ofstream& output, char symbolToPrint, int width);

//Setting output heading
void OutputHeading(ofstream& output);

//Setting print centered message function
void PrintCenteredMessage(ofstream& output, string message);

//Setting the file name message function
void PrintFileName(ofstream& output, string fileType, string fileName);

#endif 

