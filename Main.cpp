#include "helper.h"
using namespace std;



void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool exit = false;
	int choice;
	System system;

	while (exit == false)
	{
		printMenu();
		cin >> choice;
		exit = processChoice(system, choice);
		cout << endl;
	}
	

}

