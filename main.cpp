#include "AVL.h"

int main()
{
	AVL avl;
	cout << "MAKE SURE TO USE FULL SCREEN WHEN RUNNING THE PROGRAM" << endl;
	Sleep(1000);
	cout << endl << "LOADING...";
	Sleep(2000);
	system("cls");
	avl.menu();
	while (avl.choice != 'E' && avl.choice != 'e')
		avl.run();

	return 0;
}
