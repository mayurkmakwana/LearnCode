#include <iostream>
using namespace std;

class TreeNode
{
public:
	int Value;
	TreeNode *Left;
	TreeNode *Right;

	TreeNode()
	{
		Value = 0;
		Left = nullptr;
		Right = nullptr;
	}

	TreeNode(int v)
	{
		Value = v;
		Left = nullptr;
		Right = nullptr;
	}
};

class BST
{
public:
	TreeNode* Root;
	BST();
	bool isTreeEmpty();
	void insertNode(TreeNode*);
	void deleteNode(int);
	void printPreOrderNode(TreeNode*);
	void printInOrderNode(TreeNode*);
	void printPostOrderNode(TreeNode*);
	TreeNode* iterativeSearch(int);
	int heightOfTree(TreeNode*);
	void printLevelOrderBFS(TreeNode*);
	void printGivenLevel(TreeNode*, int);
};

BST::BST()
{
	Root = nullptr;
}

bool BST::isTreeEmpty()
{
	if (Root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BST::insertNode(TreeNode* new_node)
{
	
	if (Root == nullptr)
	{
		Root = new_node;
		cout << "Value inserted as root node" << endl;
	}
	else
	{
		
		TreeNode *temp = Root;
		while (temp != nullptr)
		{
			
			if (new_node->Value == temp->Value)
			{
				cout << "Value already exists" << endl;
				cout << "please, Enter diffrent value" << endl;
				return;
			}
			else if (new_node->Value < temp->Value && temp->Left == nullptr)
			{
				cout << "Value inseted as left node" << endl;
				temp->Left = new_node;
				break;
			}
			else if (new_node->Value < temp->Value)
			{
				temp = temp->Left;
			}
			else if (new_node->Value > temp->Value && temp->Right == nullptr)
			{
				cout << "Value inseted as Right node" << endl;
				temp->Right = new_node;
				break;
			}
			else 
			{
				temp = temp->Right;
			}
		}

	}
}

void BST::deleteNode(int delVal)
{
	
	if (delVal == Root->Value)
	{
		TreeNode* temp = Root;
		while (temp != nullptr)
		{
			temp = temp->Left;
		}
		temp->Left = Root->Left;
		temp->Right = Root->Right;
		Root = temp;
	}
}

TreeNode* BST::iterativeSearch(int val)
{
	if (Root == nullptr)
	{
		return nullptr;
	}
	else
	{
		TreeNode* temp = Root;
		while (temp != nullptr)
		{
			if (val == temp->Value)
			{
				return temp;
			}
			else if (val < temp->Value)
			{
				temp = temp->Left;
			}
			else
			{
				temp = temp->Right;
			}
		}
		return nullptr;
	}
}

void BST::printPreOrderNode(TreeNode *node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->Value << " ";
	printPreOrderNode(node->Left);
	printPreOrderNode(node->Right);
}

void BST::printInOrderNode(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	
	printInOrderNode(node->Left);
	cout << node->Value << " ";
	printInOrderNode(node->Right);
}

void BST::printPostOrderNode(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	
	printPostOrderNode(node->Left);
	printPostOrderNode(node->Right);
	cout << node->Value << " ";
}

int BST::heightOfTree(TreeNode* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	else
	{
		int lheight = heightOfTree(node->Left);
		int rheight = heightOfTree(node->Right);
		if (lheight > rheight)
		{
			return lheight + 1;
		}
		else
		{
			return rheight + 1;
		}

	}
}

void BST::printLevelOrderBFS(TreeNode* node)
{

	int height = heightOfTree(node);
	for (int i = 0; i <= height; i++)
	{
		printGivenLevel(node, i);
	}
}

void BST::printGivenLevel(TreeNode* node, int level)
{
	if (node == nullptr)
	{
		return;
	}
	else if (level == 0)
	{
		cout << node->Value << " ";
	}
	else
	{
		printGivenLevel(node->Left, level - 1);
		printGivenLevel(node->Right, level - 1);
	}
}

int main()
{ 
	int option,value;
	BST bstObj;
	
	do
	{
		cout << "Select the option you want to perform : " << endl;
		cout << "0. Exit" << endl;
		cout << "1. Insert a node into tree" << endl;
		cout << "2. Search a node into tree" << endl;
		cout << "3. Delete a node from tree" << endl;
		cout << "4. DFS print tree" << endl;
		cout << "5. BFS print tree" << endl;
		cout << "6. Height of tree" << endl;
		cout << "7. clear a screen" << endl;
		cout << endl;
		cin >> option;
		TreeNode* new_node = new TreeNode();
		switch (option)
		{
		case 0:
		{
			exit(0);
		}
		break;
		case 1:
		{
			cout << "Enter the value you want to add into tree : ";
			cin >> value;
			new_node->Value = value;
			bstObj.insertNode(new_node);
		}
		break;
		case 2:
		{
			if (!bstObj.isTreeEmpty())
			{
				cout << "Enter the value you want to search in the tree : ";
				cin >> value;
				new_node = bstObj.iterativeSearch(value);
				if (new_node != nullptr)
				{
					cout << "VALUE FOUND" << endl;
				}
				else
				{
					cout << "VALUE NOT FOUND" << endl;
				}
			}
			else
				cout << "Tree is empty" << endl;

		}
		break;
		case 3:
		{
			if (!bstObj.isTreeEmpty())
			{
				cout << "Enter the value you want to delete from the tree : ";
				cin >> value;
				bstObj.deleteNode(value);
			}
			else
				cout << "Tree is empty" << endl;
		}
		break;
		case 4:
		{
			if (!bstObj.isTreeEmpty())
			{
				cout << "PRE-ORDER PRINT" << endl;
				bstObj.printPreOrderNode(bstObj.Root);  // for pre-order printing
				cout << endl;
				//cout << "IN-ORDER PRINT" << endl;
				//bstObj.printInOrderNode(bstObj.Root);  // for in-order printing
				//cout << endl;
				//cout << "POST-ORDER PRINT" << endl;
				//bstObj.printPostOrderNode(bstObj.Root);  // for post-order printing
				//cout << endl;
			}
			else
				cout << "Tree is empty" << endl;

		}
		break;
		case 5:
		{
			if (!bstObj.isTreeEmpty())
			{
				cout << "LEVEL ORDER PRINT" << endl;
				bstObj.printLevelOrderBFS(bstObj.Root);  // for level order printing
				cout << endl;
				
			}
			else
				cout << "Tree is empty" << endl;

		}
		break;
		case 6:
		{
			if (!bstObj.isTreeEmpty())
			{
				cout << "HEIGHT = " << bstObj.heightOfTree(bstObj.Root) << endl;
			}
			else
				cout << "Tree is empty" << endl;


		}
		break;
		case 7:
		{    
			cout << "CLEAR SCREEN" << endl;
			system("cls");
		}
		break;
		default:
		{
			cout << "selected wrong option...try again" << endl;
		}
		break;
		}



	} while (option!=0);
}
