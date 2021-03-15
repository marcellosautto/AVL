#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

class AVL
{
public:
	struct Node {
		Node* left;
		Node* right;
		int num;
		Node()
		{
			left = nullptr;
			right = nullptr;
			num = 0;
		};
		Node(int number)
		{
			left = nullptr;
			right = nullptr;
			num = number;
		};
	}*root;

	bool run();
	AVL();
	void LNR(Node* n),
		NLR(Node* n),
		LRN(Node* n),
		menu(),
		displayTree(Node* r, int x, int y, int width);
	struct Node* buildTree(int n, Node* r);
	struct Node* rightRightRotate(Node* r);
	struct Node* leftLeftRotate(Node* r);
	struct Node* leftRightRotate(Node* r);
	struct Node* rightLeftRotate(Node* r);
	struct Node* balanceTree(Node* r);
	int Difference(Node* r);
	int height(Node* r) const;
	int addNum;
	//struct Node* DEL(int removeNumber, Node* r);
	char choice;
};


