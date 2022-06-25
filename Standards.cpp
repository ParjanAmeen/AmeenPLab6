//---------------------------------------------------------------------------------------------------------------------
//File Name:        Standards.cpp
//Associated File:  Standards.h
//Contains:
//  OutputDivider
//  OuputHeading
//---------------------------------------------------------------------------------------------------------------------

#include "Standards.h"

void OutputDivider(ofstream& output, char symbolToPrint, int width)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//OutputDivider - The divider will be printed to the screen and output file
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	//Print a divider to the output stream
	output << setfill(symbolToPrint) << setw(width) << symbolToPrint << setfill(' ') << endl;
}

void OutputHeading(ofstream& output)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//OutputHeading - Print the lab header information to the screen and output file
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	//Print a divider to the output stream
	OutputDivider(output, SYMBOL, WIDTH);

	//Print the college name to the output stream
	output << right << setw((WIDTH + COLLEGE.length()) / 2) << COLLEGE << endl;

	//Print the programmers name to the output stream
	output << right << setw((WIDTH + PROGRAMMER_NAME.length()) / 2) << PROGRAMMER_NAME << endl;

	//Print the class and lab name to the output stream
	output << right << setw((WIDTH + CLASS_LAB_NAME.length()) / 2) << CLASS_LAB_NAME << endl;

	//Print a divider to the output stream
	OutputDivider(output, SYMBOL, WIDTH);
}

void PrintCenteredMessage(ofstream& output, string message)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PrintCenteredMessage - Print a message passed in to the desired file stream
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	output << setw((WIDTH + message.length()) / 2) << message << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PrintFileName - Prints the file name passed in to the desired file stream
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintFileName(ofstream& output, string fileType, string fileName)
{
	//Output a file message to the screen
	output << "The " << fileType << " file can be found in the file, " << fileName << endl;
}