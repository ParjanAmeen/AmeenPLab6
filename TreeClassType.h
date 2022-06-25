///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         TreeClassType.h
// Associated File:   TreeClassType.cpp                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the TreeClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TreeClassType_h
#define TreeClassType_h
//---------------------------------------------------------------------------------------------------------------------
#include "Standards.h"

//Defining a structure nodeType
struct nodeStructType
{
    //nodeStructType member variables
    char letter;
    int counter;

};

//Defining a structure node
struct node
{
    //node member variables
    nodeStructType data;
    node* left;
    node* right;

};

//Creating a type definition, this is a pointer to the node
typedef node* nodePtr;

//Definition of the class - TreeClassType
class TreeClassType
{

private:

    //Member variables
    nodePtr root;
    bool isAlpha;

    //Member functions
    void Insert(nodePtr newNode);
    void DeleteLeafNode(nodePtr& currentPtr, nodePtr& parentPtr);
    void DeleteNodeLeftChildOnly(nodePtr& currentPtr, nodePtr& parentPtr);
    void DeleteNodeRightChildOnly(nodePtr& currentPtr, nodePtr& parentPtr);
    void DeleteNodeWithTwoChildren(nodePtr& currentPtr, nodePtr& parentPtr);
    void Delete(nodePtr& currentPtr, nodePtr& parentPtr);


public:

    //Constructor(s)---------------------------------------------------------------------------------------------------
    TreeClassType(void) { CreateTree(); }

    //Public member functions
    void CreateTree(void);
    bool IsEmpty(void);
    nodePtr GetRoot(void) { return root; }
    nodePtr GetANode(char aLetter, int letterCounter);
    void BuildAlphaTree(ifstream& fin);
    void BuildCountTree(nodePtr parentPtr);
    void ProcessText(ifstream& fin);
    void InOrder(ofstream& fout, nodePtr currentPtr);
    void PreOrder(ofstream& fout, nodePtr currentPtr);
    void PostOrder(ofstream& fout, nodePtr currentPtr);
    void UpdateTree(char aLetter, nodePtr currentPtr);
    int FindLargestCount(void);
    int SumCounts(nodePtr current);
    void SearchTree(nodeStructType searchNode, bool& found, nodePtr& currentPtr, nodePtr& parentPtr);
    void DeleteNode(nodeStructType searchNode, bool& found);
    void DestroyTree(void);
    void Print(ofstream& fout, string traversal, string treeType, string taskType);

    //Destructor-------------------------------------------------------------------------------------------------------
    ~TreeClassType(void) { DestroyTree(); };

    //Setting divider function
    friend void OutputDivider(ofstream& output, char symbolToPrint, int width);

};

#endif  