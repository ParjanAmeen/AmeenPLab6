//----------------------------------------------------------------------------------------------------------------------
//Lab 6 Grading Block
//Name: Parjan Ameen 
//Lab Grade: 
//----------------------------------------------------------------------------------------------------------------------
//Total Possible Points -------------------------------------------------------------------------------------------> 200
//Total Points lost ----------------------------------------------------------------------------------------------->
//Lab Grade -------------------------------------------------------------------------------------------------------> 
//----------------------------------------------------------------------------------------------------------------------
//General Comments:
//  
//  
//  
//  
//----------------------------------------------------------------------------------------------------------------------
//Standard Requirements
//  Requirements met as specified for the
//  Which includes but not limited to:
//    Program Creation
//    File Requirements
//    Documentation
//    Documentation as required for Class Objects
//    Constants
//    Variables 
//    Code
//Comments:
//  
//  
//  
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//Program Specifications
//-Standards.h included with the preprocessor directives
//-Course Required header & CPP file
//Comments:
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//----------------------------------------------------------------------------------------------------------------------
//
//Class Object DEFINITION
//nodeStructType defined
//node defined
//nodePtr type def
//Object defined using UML
//
//Methods
// Accomplish the required tasks EFFICIENTLY
// Methods placed in header and cpp file in the order 
//  listed in the instructions with the constructor first and the destructor last
// Constructor
//  Calls CreateTree
// CreateTree
//  Set root to NULL & isAlpha to true
// IsEmpty 
//  returns a bool
// GetRoot
//  returns a pointer to the root
// GetANode
//  Creates a nodePtr with letter,count and 2 pointers set to NULL// Insert
//   Inserts a node into the ordered ascending tree, either alpha or int tree
// BuildAlphaTree
//  Inputs letters, creating an alphabet ordered tree with counts set to 0
//  Recursively, Inorder
// BuildCountTree
//  From the updated Alpha tree, creates a count tree in ascending order, recursively
// ProcessText
//  Inputs the letters created a binary search tree from the order of the letters in the input file
// Insert
//  Inserts a node into tree based on the type of the newNode
// Inorder,Preorder,Postorder
//  Outputs the output file, in aligned columns the letter and the counts in the correct order, 
//    one per line
// UpdateTree
//  Using the input data from the text file, updates the count based on the occurrence of the
//   letter, recursively, Inorder
// FindLargestCount
//  Using the count tree & taking advantage of the order, efficiently finds the largest count
//   in the tree
// SumCounts
//  Calculates the sum of the counts in the count tree, recursively
// SearchTree
//  Non-recursive solution returns a bool, current and parent based on the type of tree
// DeleteLeafNode, DeleteNodeLeftChildOnly, DeleteNodeRightChildOnly, DeleteNodeWithTwoChildren,
//  Deletes and updates the pointers as needed
// DeleteNode
// Delete
//  Call one of 4 deletion methods to actually delete the specific type of node
// DestroyTree
// Print
//  Outputs the tree in the specified order to the output file
// Destructor
//Friend Functions
//  PrintDivider
//
//Comments:
// 
// 
// 
// 
//Points Lost --------------------------------------------------------------------------------------------------->
//
//Main - follow this order and accomplish these tasks
// Files open
// Alpha tree built
// Alpha tree output inorder, no counts updated with sum of counts
// Process Text, counts updated based on text
// Output Alpha tree inorder with letters, counts & sum of counts
// Output Alpha tree preorder with letters, counts & sum of counts
// Output Alpha tree postorder with letters, counts & sum of counts
// Build the count tree, ordered in ascending order based on the counts
// Output Count tree inorder with letters, counts & sum of counts
// Output Count tree postorder with letters, counts & sum of counts
// Find the largest in the Count tree and output the largest clearly labeled in the main
// Search for the letter, t in the Alpha tree and output message with letter and count or
//  message that it was not found
// Search for the letter, * in the Alpha tree and output message with letter and count or
//  message that it was not found
// Search for the letter, q in the Alpha tree and output message with letter and count or
//  message that it was not found
// Attempt to delete a node with letter, u to search and delete the node if found - leaf node
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, u - search and delete the node if found - node with 2 children
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, h - search and delete the node if found - node with 1 right child
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, z - search and delete the node if found - node with 1 left child
// Output deletion message in the main based on found
// Attempt to delete a node with letter, x - search and delete the node if found - node not found
// Output deletion message in the main based on found
// Output the alpha tree to the output file, message "After 4 Deletions"
// Output the count tree to the output file, message "After 4 Deletions"
// Files Closed
//----------------------------------------------------------------------------------------------------------------------
//Miscellaneous Errors not anticipated by your professor
//
//
//
//Comments:
// 
//
// 
//----------------------------------------------------------------------------------------------------------------------
//

#include "Standards.h"
#include "TreeClassType.h"

int main(void)
{
	
	//declare file variables
	ofstream fout;
	ifstream fin;

	//Local objects
	TreeClassType alphaTree;
	TreeClassType countTree;
	nodePtr child = new node;
	nodePtr parent = new node;
	nodeStructType aNode;

	//Local variables
	bool found;
	int largest;
	char testingArrayNotDeletion[3] = { 't', '*', 'q' };
	char testingArrayDeletion[5] = { 'u', 'x', 'h', 'z', 'x' };

	//Initial set up of program & List--------------------------------------------------------------

	//Open the two files
	fin.open("Letters.txt");
	fout.open("Results.txt");

	//Set up fixed point output for the file
	fout << fixed << setprecision(2);

	//Output the course required header and file messages to the screen 
	PrintFileName(static_cast<ofstream&> (cout), "Input", "info.txt");

	//Output the course required header and file messages to the screen 
	PrintFileName(static_cast<ofstream&> (cout), "Input", "Letters.txt");

	//Call to output the output file names to the screen
	PrintFileName(static_cast<ofstream&> (cout), "Output", "Results.txt");

	//Call to output the course heading to the screen
	OutputHeading(static_cast<ofstream&> (cout));

	//Call to output the course heading to the output file
	OutputHeading(fout);

	//Call BuildAlphaTree
	alphaTree.BuildAlphaTree(fin);

	//Clear the file
	fin.clear();

	//Close the files
	fin.close();

	//Output the alpha tree
	alphaTree.Print(fout, "Inorder", "Alpha", "Updated With Letters");

	//Open the info text input file
	fin.open("info.txt");

	//Call the processing function for the info text input file
	alphaTree.ProcessText(fin);

	//Print with an Inorder
	alphaTree.Print(fout, "Inorder", "Alpha", "Updated Counts");

	//Print with a Preorder
	alphaTree.Print(fout, "Preorder", "Alpha", "Letters & Counts");

	//Print with a Postorder
	alphaTree.Print(fout, "Postorder", "Alpha", "Letters & Counts");

	//Build the count tree
	countTree.BuildCountTree(alphaTree.GetRoot());

	//Print the count tree with an Inorder
	countTree.Print(fout, "Inorder", "Count", "Letters & Counts");

	//Print the count tree with a Postorder
	countTree.Print(fout, "Postorder", "Count", "Letters & Counts");

	//Set the largest to catch the FindLargestCount function
	largest = countTree.FindLargestCount();

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Output the largest count
	fout << "Largest Count is: " << setw(12) << largest << endl;

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Testing for the search section only
	for (int index = 0; index < 3; index++)
	{
		//Set the letter equal to the characters being tested
		aNode.letter = testingArrayNotDeletion[index];

		//Search the alpha tree for the letter
		alphaTree.SearchTree(aNode, found, child, parent);

		if (found)
		{
			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);

			//Output what was searched for
			fout << "The character searched for was: " << aNode.letter << endl;

			//Output that the character was found along with the count
			fout << "The character was found in the tree" << endl;
			fout << "The letter is " << child->data.letter <<  " The count is " << child->data.counter << endl;

			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);
		}

		else
		{
			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);

			//Output what was searched for
			fout << "The character searched for was: " << aNode.letter << endl;

			//Output that it could not be found
			fout << "That character was not found" << endl;

			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);
		}
	}

	//Testing for the deletion section
	for (int index = 0; index < 5; index++)
	{
		//Set the letter equal to the characters being tested
		aNode.letter = testingArrayDeletion[index];

		//Search the alpha tree for the letter
		alphaTree.SearchTree(aNode, found, child, parent);

		if (found)
		{
			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);

			//Output what was searched for
			fout << "The character searched for was: " << aNode.letter << endl;

			//Call DeleteNode
			alphaTree.DeleteNode(aNode, found);

			//Output that the character was found
			fout << "The character " << aNode.letter << " was deleted from the tree" << endl;

			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);
		}

		else
		{
			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);

			//Output what was searched for
			fout << "The character searched for was: " << aNode.letter << endl;

			//Output that it could not be found
			fout << "That character was not found" << endl;

			//Print a divider to the output stream
			OutputDivider(fout, SYMBOL, WIDTH);
		}

	}

	//Output the alpha tree Inorder after the deletions
	alphaTree.Print(fout, "Inorder", "Alpha", "After 4 Deletions");

	//Output the count tree Inorder with updated counts
	countTree.Print(fout, "Inorder", "Count", "Updated Counts");

	//Close the files
	fin.close();
	fout.close();

	return 0;
}