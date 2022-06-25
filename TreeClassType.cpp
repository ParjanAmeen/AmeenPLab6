///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         IntegerClassType.h
// Associated File:   IntegerClassType.cpp                                                                                           
// CPP File Contains:
//Contains Gets, Sets, prints, and other functions for the TreeClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "TreeClassType.h"

//----------------------------------------------------------------------------------------------------------------------
//CreateTree - Initializes the private variables
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::CreateTree(void)
{
	//Initializing the private variables
	root = NULL;
	isAlpha = true;
}

//----------------------------------------------------------------------------------------------------------------------
//IsEmpty - Tests the root and returns true if NULL and false otherwise
//----------------------------------------------------------------------------------------------------------------------
bool TreeClassType::IsEmpty(void)
{
	if (root == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//GetANode - Stores the letter and counter in a node pointer and set the two links to NULL
//----------------------------------------------------------------------------------------------------------------------
nodePtr TreeClassType::GetANode(char aLetter, int letterCounter)
{
	//Local pointer 
	nodePtr ptr = new node;

	//Set the pointer equal to the parameters
	ptr->data.letter = aLetter;
	ptr->data.counter = letterCounter;

	//Set the left and right links to NULL
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;
}

//----------------------------------------------------------------------------------------------------------------------
//BuildAlphaTree - Reads in from the input file
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::BuildAlphaTree(ifstream& fin)
{
	//Local variables
	char aLetter;
	int aCounter = 0;
	nodePtr ptr;

	//Set the bool flag to false
	isAlpha = true;

	//Primer
	fin.get(aLetter);
	
	while (fin)
	{
		//Create a node for the new line of data read in
		ptr = GetANode(aLetter, aCounter);

		//Call insert to add the new letter to the BST
		Insert(ptr);

		//Changer
		fin.get(aLetter);
	}
}

//----------------------------------------------------------------------------------------------------------------------
//Insert - Determines where the new node for a letter or a count will be inserted in the binary search tree
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::Insert(nodePtr newNode)
{
	if (isAlpha) 
	{
		//Local nodes
		nodePtr parent = NULL;
		nodePtr child = root;

		while (child != NULL) 
		{
			//Set the parent equal to the child
			parent = child;

			if (child->data.letter > newNode->data.letter) 
			{
				//Set the child to the left pointer
				child = child->left;
			}
			else
			{
				//Set the child to the right pointer
				child = child->right;
			}
		}

		if (IsEmpty()) 
		{
			//Set the root equal to the node
			root = newNode;
		}
		
		else if (newNode->data.letter < parent->data.letter)
		{
			//Set the left pointer to the new node
			parent->left = newNode;
		}
		else 
		{
			//Set the right pointer to the new node
			parent->right = newNode;
		}
	}
	else 
	{
		//Set the parent to NULL
		nodePtr parent = NULL;

		//Set the child to the root
		nodePtr child = root;

		while (child != NULL) 
		{
			//Set the parent to the child
			parent = child;

			if (newNode->data.counter < child->data.counter)
			{
				//Set the child to the left pointer
				child = child->left;
			}
			else
			{
				//Set the child to the right pointer
				child = child->right;
			}
		}

		if (IsEmpty()) 
		{
			//Set the root equal to the new node
			root = newNode;
		}
		
		else if ((newNode->data.counter < parent->data.counter))
		{
			//Set the left pointer equal to the new node
			parent->left = newNode;
		}
		else 
		{
			//Set the right pointer equal to the new node
			parent->right = newNode;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//BuidCountTree - Traverses the alpha tree and creates a deep copied binary search tree
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::BuildCountTree(nodePtr parentPtr)
{
	//Local pointer 
	nodePtr ptr;

	//Set isAlpha to false
	isAlpha = false;

	if (parentPtr != NULL)
	{
		//Assign the ptr a value from GetANode
		ptr = GetANode(parentPtr->data.letter, parentPtr->data.counter);

		//Call for the left link
		BuildCountTree(parentPtr->left);

		//Call Insert to set the new node
		Insert(ptr);

		//Call for the right link
		BuildCountTree(parentPtr->right);
	}



}

//----------------------------------------------------------------------------------------------------------------------
//ProcessText - Reads in one character at a time from the info.txt file until all characters have been read
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::ProcessText(ifstream& fin)
{
	//Local variables
	char aLetter;

	//Primer
	fin.get(aLetter);

	while (fin)
	{
		//Lowercase the letter read in
		aLetter = tolower(aLetter);

		//Check to see if the letter is a part of the alphabet
		if ('a' <= aLetter || aLetter <= 'z')
		{
			//Call update tree
			UpdateTree(aLetter, root);
		}

		//Changer
		fin.get(aLetter);
	}
}

//----------------------------------------------------------------------------------------------------------------------
//InOrder - Outputs the nodes in a tree
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::InOrder(ofstream& fout, nodePtr currentPtr)
{
	if (currentPtr != nullptr)
	{
		InOrder(fout, currentPtr->left);

		//Output the letter and counter
		fout << setw(12) << currentPtr->data.letter;
		fout << setw(12) << currentPtr->data.counter << endl;

		InOrder(fout, currentPtr->right);
	}

}

//----------------------------------------------------------------------------------------------------------------------
//PreOrder - Outputs the nodes in a tree
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::PreOrder(ofstream& fout, nodePtr currentPtr)
{
	if (currentPtr != nullptr)
	{
		//Output the letter and counter
		fout << setw(12) << currentPtr->data.letter;
		fout << setw(12) << currentPtr->data.counter << endl;

		PreOrder(fout, currentPtr->left);
		PreOrder(fout, currentPtr->right);
	}
}


//----------------------------------------------------------------------------------------------------------------------
//PostOrder - Outputs the nodes in a tree
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::PostOrder(ofstream& fout, nodePtr currentPtr)
{
	if (currentPtr != nullptr)
	{
		PostOrder(fout, currentPtr->left);
		PostOrder(fout, currentPtr->right);

		//Output the letter and counter
		fout << setw(12) << currentPtr->data.letter;
		fout << setw(12) << currentPtr->data.counter << endl;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//UpdateTree - Searches the alpha tree for a letter passed in
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::UpdateTree(char aLetter, nodePtr currentPtr)
{
	//Local variables
	nodePtr parent;

	if (currentPtr != NULL)
	{
		//Check to see if the letter passed is there
		if (currentPtr->data.letter == aLetter)
		{
			//Increment the counter
			currentPtr->data.counter++;

			return;
		}
		else if (aLetter < currentPtr->data.letter)
		{
			//Set the parent ptr to the currentPtr
			parent = currentPtr;

			//Call recursively 
			UpdateTree(aLetter, parent->left);

			return;
		}
		else
		{
			 //Set the parent ptr to the currentPtr
			 parent = currentPtr;

			 //Call recursively 
			 UpdateTree(aLetter, parent->right);

			 return;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//FindLargestCount - Find the largest count in the binary search tree
//----------------------------------------------------------------------------------------------------------------------
int TreeClassType::FindLargestCount()
{
	
	//Local variables
	nodePtr current;
	nodePtr parent = root;
	int test = 0;

	//Assign the current to the right link of the parent
	current = parent->right;

	while (current != NULL)
	{
		//Set parent to current
		parent = current;

		//Set current to the right link of the parent
		current = current->right;
	}

	return parent->data.counter;

}

//----------------------------------------------------------------------------------------------------------------------
//SumCounts - Calculates the sum of the nodes starting at the root of the tree
//----------------------------------------------------------------------------------------------------------------------
int TreeClassType::SumCounts(nodePtr current)
{
	//Local variables
	int sum = 0;

	if (current != NULL) 
	{
		//Add up the sum of the left and right sides of the tree
		sum = current->data.counter + SumCounts(current->left) + (SumCounts(current->right));

		return sum;

	}

	else
	{
		return 0;  
	}

}

//----------------------------------------------------------------------------------------------------------------------
//SearchTree - Searches the correct tree based on isAlpha
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::SearchTree(nodeStructType searchNode, bool& found, nodePtr& currentPtr, nodePtr& parentPtr)
{
	
	//Setting found to false
		found = false;

		//Setting currentPtr to root and parentPtr to NULL
		currentPtr = root;
		parentPtr = NULL;

		if (isAlpha)
		{

			if (root == nullptr)
			{
				cout << "Cannot search an empty tree." << endl;
			}

			else
			{


				//Set the currentPtr to the root
				currentPtr = root;

				while (currentPtr != nullptr && !found)
				{
					if (currentPtr->data.letter == searchNode.letter)
					{
						found = true;
					}

					else if (currentPtr->data.letter > searchNode.letter)
					{
						//Set the parentPtr to the currentPtr
						parentPtr = currentPtr;

						//Move the currentPtr left
						currentPtr = currentPtr->left;

					}

					else
					{
						//Set the parentPtr to the currentPtr
						parentPtr = currentPtr;

						//Move the currentPtr right
						currentPtr = currentPtr->right;
					}
				}//end while
			}//end else

		}

		if (!isAlpha)
		{

			if (root == nullptr)
			{
				cout << "Cannot search an empty tree." << endl;
			}

			else
			{
				//Set currentPtr to root
				currentPtr = root;

				while (currentPtr != nullptr && !found)
				{
					if (currentPtr->data.counter == searchNode.counter)
					{
						found = true;
					}

					else if (currentPtr->data.counter > searchNode.counter)
					{
						//Set the parentPtr to the currentPtr
						parentPtr = currentPtr;

						//Move the currentPtr left
						currentPtr = currentPtr->left;
					}

					else
					{

						//Set the parentPtr to the currentPtr
						parentPtr = currentPtr;

						//Move the currentPtr right
						currentPtr = currentPtr->right;
					}
				}//end while
			}//end else

		}
}

//----------------------------------------------------------------------------------------------------------------------
//DeleteLeafNode - Deletes the current node
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::DeleteLeafNode(nodePtr& currentPtr, nodePtr& parentPtr)
{
		if (parentPtr == NULL)
		{
			//Set the root to NULL
			root = NULL;
		}
		else if (parentPtr->left == currentPtr)
		{
			//Set the left and currentPtr node equal to NULL
			parentPtr->left = NULL;
			
		}
		else
		{
			//Set the left and currentPtr node equal to NULL
			parentPtr->right = NULL;
			
		}
	
		delete currentPtr;
}

//----------------------------------------------------------------------------------------------------------------------
//DeleteNodeLeftChildOnly - Deletes the current node
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::DeleteNodeLeftChildOnly(nodePtr& currentPtr, nodePtr& parentPtr)
{
	if (parentPtr != NULL)
	{
		if (parentPtr->right == currentPtr)
		{
			//Set the right link to the left link
			parentPtr->right = currentPtr->left;
		}
		else
		{
			//Set the parents left child to the currents left
			parentPtr->left = currentPtr->left;
		}

	}
	
	if (currentPtr == root)
	{
		//Set the root equal to the left link
		root = currentPtr->left;
	}

	//Set the left link to NULL
	currentPtr->left = NULL;
	

	delete currentPtr;
}

//----------------------------------------------------------------------------------------------------------------------
//DeleteNodeRightChildOnly - Deletes the current node
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::DeleteNodeRightChildOnly(nodePtr& currentPtr, nodePtr& parentPtr)
{
	if (parentPtr != NULL)
	{
		if (parentPtr->right == currentPtr)
		{
			//Set the right link to the left link
			parentPtr->right = currentPtr->right;
		}
		else
		{
			//Set the parents left child to the currents left
			parentPtr->left = currentPtr->right;

		}

	}

	if (currentPtr == root)
	{
		//Set the root equal to the left link
		root = currentPtr->right;
	}

	//Set the left link to NULL
	currentPtr->right = NULL;


	delete currentPtr;
}

//----------------------------------------------------------------------------------------------------------------------
//DeleteNodeWithTwoChildren - Deletes the current node
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::DeleteNodeWithTwoChildren(nodePtr& currentPtr, nodePtr& parentPtr)
{
	//Local variables
	nodeStructType swap;
	nodePtr ptr;
	nodePtr temp;

	//Set the pointer to the left link and the temp pointer to the currentPtr
	ptr = currentPtr->left;
	temp = currentPtr;

	while (ptr->right != NULL)
	{
		//Moving the pointer to the right
		temp = ptr;
		ptr = ptr->right;
	}

	//Swapping data
	swap = ptr->data;
	ptr->data = currentPtr->data;
	currentPtr->data = swap;

	if (ptr->left == NULL)
	{
		//Call DeleteLeafNode
		DeleteLeafNode(ptr, temp);
	}

	else
	{
		//Call DeleteNodeLeftChildOnly
		DeleteNodeLeftChildOnly(ptr, temp);
	}

}

//----------------------------------------------------------------------------------------------------------------------
//Delete - Based on the current node passed in call one of the 4 delete methods
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::Delete(nodePtr& currentPtr, nodePtr& parentPtr)
{
	
	if (currentPtr->left == NULL && currentPtr->right == NULL)
	{
		//Call DeleteLeaf
		DeleteLeafNode(currentPtr, parentPtr);
	}
	else if (currentPtr->left == NULL)
	{
		//Call DeleteNodeLeftChildOnly
		DeleteNodeRightChildOnly(currentPtr, parentPtr);
	}
	else if (currentPtr->right == NULL)
	{
		//Call DeleteNodeRightChildOnly
		DeleteNodeLeftChildOnly(currentPtr, parentPtr);
	}
	else
	{
		//Call DeleteNodeWithTwoChildren
		DeleteNodeWithTwoChildren(currentPtr, parentPtr);
	}
}

//----------------------------------------------------------------------------------------------------------------------
//DeleteNode - Searches the tree by calling SearchTree and deletes the node value found
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::DeleteNode(nodeStructType searchNode, bool& found)
{
	//Local variables
	nodePtr currentPtr;
	nodePtr parentPtr;

	//Call SearchTree
	SearchTree(searchNode, found, currentPtr, parentPtr);

	if (found)
	{
		//Call delete if found is true
		Delete(currentPtr, parentPtr);
	}
	else
	{
		return; 
	}

}

//----------------------------------------------------------------------------------------------------------------------
//DestroyTree - Breaks down the tree by deletion
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::DestroyTree(void)
{
	
	//Local variables
	int deleteCounter = 0;
	bool found;
	nodeStructType searchNode;

	while (!IsEmpty())
	{
		//Set the searchNode to data
		searchNode = root->data;

		//Call DeleteNode
		DeleteNode(searchNode, found);

		
		if (found)
		{
			//Increment the counter
			deleteCounter++;

			//Output the deletion number
			cout << "Destroy #" << deleteCounter << endl;
			
			//Output the letter and counter for each node being deleted
			cout << "Letter: " << searchNode.letter << right << setw(10) << "Count: " << searchNode.counter << endl;

			//Create a blank space
			cout << endl;
		}
		else
		{
			//Error message
			cout << "Cannot find the node" << endl;
		}
			
	}
	
}

//----------------------------------------------------------------------------------------------------------------------
//Print - Prints out a heading with which tree being printed along with the tree its self
//----------------------------------------------------------------------------------------------------------------------
void TreeClassType::Print(ofstream& fout, string traversal, string treeType, string taskType)
{
	//Local variables
	int sum = 0;

	//Header 
	fout << "This is the " << treeType << " Tree" << endl;
	fout << traversal<< " traversal of the Tree" << endl;
	fout << "Task Preformed: " << taskType << endl;
	fout << setw(12) << "Letter" << setw(12) << "Count" << endl;
	
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	if (traversal == "Inorder")
	{ 
		
		InOrder(fout, root);
	
	}

	if (traversal == "Postorder")
	{ 
		PostOrder(fout, root); 
	
	}

	else if (traversal == "Preorder") 
	{ 
		PreOrder(fout, root); 
	
	}

	//Assign the sum
	sum = SumCounts(root);

	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

	//Output the sum
	fout << "Sum of Counts" << setw(18) << sum << endl;
	
	//Print a divider to the output stream
	OutputDivider(fout, SYMBOL, WIDTH);

}