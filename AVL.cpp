#include "AVL.h"

AVL::AVL()
{
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void AVL::NLR(Node* n) //recursively prints tree in NLR order
{
	cout << n->num << " ";
	if (n->left != nullptr)
		NLR(n->left);
	if (n->right != nullptr)
		NLR(n->right);
}

void AVL::LNR(Node* n) //recursively prints tree in LNR order
{
	if (n->left != nullptr)
		LNR(n->left);
	cout << n->num << " ";
	if (n->right != nullptr)
		LNR(n->right);
}

void AVL::LRN(Node* n) //recursively prints tree in LRN order
{
	if (n->left != nullptr)
		LRN(n->left);
	if (n->right != nullptr)
		LRN(n->right);
	cout << n->num << " ";
}

void AVL::displayTree(Node* r, int x, int y, int width)
{
	if (r == nullptr)
		return;
	if (r == root)
	{
		gotoxy(x - 1, y - 1);
		cout << "root";
	}
	gotoxy(x, y);
	//if node has 2 children
	if (r->left != nullptr && r->right != nullptr)
	{
		cout << r->num;
		gotoxy(x - width, y + 1);
		for (int i = 1; i <= width; i++)
			cout << "_";
		cout << "||";
		for (int j = 1; j <= width; j++)
			cout << "_";
		gotoxy(x - width, y + 2);
		cout << "|";
		for (int k = 1; k <= (width) * 2; k++)
			cout << " ";
		cout << "|";
	}
	//if theres only a left child
	else if (r->left != nullptr && r->right == nullptr)
	{
		cout << r->num;
		gotoxy(x - width, y + 1);
		for (int i = 1; i <= width; i++)
			cout << "_";
		cout << "|";
		gotoxy(x - width, y + 2);
		cout << "|";
		for (int j = 1; j <= width; j++)
			cout << " ";
	}
	//if there's only a right child
	else if (r->left == nullptr && r->right != nullptr)
	{
		cout << r->num;
		gotoxy(x, y + 1);
		cout << "|";
		for (int i = 1; i <= width; i++)
			cout << "_";
		gotoxy(x, y + 2);
		for (int j = 1; j <= width; j++)
			cout << " ";
		cout << "|";
	}
	else {
		cout << r->num;
	}
	displayTree(r->right, x + width, y + 3, width / 2);
	displayTree(r->left, x - width, y + 3, width / 2);
}

void AVL::menu()
{
	cout << "   #    #     # #          #######                      " << endl;
	cout << "  # #   #     # #             #    #####  ###### ###### " << endl;
	cout << " #   #  #     # #             #    #    # #      #      " << endl;
	cout << "#     # #     # #             #    #    # #####  #####  " << endl;
	cout << "#######  #   #  #             #    #####  #      #      " << endl;
	cout << "#     #   # #   #             #    #   #  #      #      " << endl;
	cout << "#     #    #    #######       #    #    # ###### ###### " << endl << endl;



	cout << "--------------------------------------------------------------------------- \n" <<
		"         AVL Tree Implemenation \n" <<
		"A: Insert an integer to tree and show the balanced tree at each insertion. \n" <<
		"B: Display the balanced tree and show preorder traversal. \n" <<
		"C: Display the balanced tree and show inorder traversal \n" <<
		"D: Display the balanced tree and show postorder traversal \n" <<
		"E: Exit \n";
}

bool AVL::run()
{
	menu();
	while (1)
	{
		cout << endl << "Enter a Command: ";
		cin >> choice;

		if (choice == 'A' || choice == 'a') //Prompts user to insert node
		{
			cout << endl << "Enter the Number You Want to Insert: " << endl;
			cin >> addNum;
			buildTree(addNum, root);
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl;
		}
		else if (choice == 'B' || choice == 'b') //print Tree with LNR order output
		{
			//readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "Preorder: ";
			NLR(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == 'C' || choice == 'c')//print Tree with NLR order output
		{
			//readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "Inorder: ";
			LNR(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == 'D' || choice == 'd')//print Tree with LRN order output
		{
			//readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "Postorder: ";
			LRN(root);
			cout << endl << endl << endl << endl << endl;
		}
		else if (choice == 'E' || choice == 'e')
			return false;
	}
}

struct AVL::Node* AVL::buildTree(int n, Node* r) //insert a node into the tree then balance it
{
	//builds the root
	if (r == nullptr)
	{
		Node* temp = new Node(n);
		if (root == nullptr)
			root = temp;
		//else if (temp->left == root || temp->right == root)
			//root = temp;
		return temp;
	}
	//build the rest of the tree based on whether the nodes are greater or less than their parents
	if (n < r->num) //if the value is less than the current value, go to the left
		r->left = buildTree(n, r->left);
	else if (n > r->num) //if the value is greater than the current value, go to the right
		r->right = buildTree(n, r->right);
	else
		return r;

	balanceTree(r);
}


struct AVL::Node* AVL::leftLeftRotate(Node* r)
{
	//Returns the tree node resulting from
	// a left rotation.
	Node* A = r->right;
	Node* B = A->left;
	A->left = r;
	r->right = B;
	return A;
}

struct AVL::Node* AVL::rightRightRotate(Node* r)
{
	// Returns the tree node resulting from
	// a right rotation.
	Node* A = r->left;
	Node* B = A->right;
	A->right = r;
	r->left = B;
	return A;
}

struct AVL::Node* AVL::leftRightRotate(Node* r)
{
	// Returns the tree node resulting from a
	// right-left rotation.
	Node* A = r->left;
	r->left = leftLeftRotate(A);
	return rightRightRotate(r);
}

struct AVL::Node* AVL::rightLeftRotate(Node* r)
{
	// Returns the tree node resulting from a
	// right-left rotation.
	Node* A = r->right;
	r->right = rightRightRotate(A);
	return leftLeftRotate(r);
}

struct AVL::Node* AVL::balanceTree(Node* r)
{
	int balanceFactor = Difference(r);

	if (balanceFactor > 1) // Left subtree is taller
	{
		if (Difference(r->left) > 0)
			return rightRightRotate(r);
		else
			return leftRightRotate(r);
	}
	else if (balanceFactor < -1) // Right subtree is taller
	{
		if (Difference(r->right) < 0)
			return leftLeftRotate(r);
		else
			return rightLeftRotate(r);
	}
	else
		return r;
}

int AVL::Difference(Node* r) //takes the difference between the left and right height of a node
{
	return (height(r->left) - height(r->right));
}

int AVL::height(Node* r) const //checks the height of each node
{
	if (r == nullptr)
		return 0;
	else
	{
		int heightLeft = height(r->left);
		int heightRight = height(r->right);
		if (heightLeft > heightRight)
			return heightLeft + 1;
		else
			return heightRight + 1;
	}
}
