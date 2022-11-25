#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "helper.h"



void main()
{
	bool exit = false;
	int choice;
	System system;

	while (exit == false)
	{
		printMenu();
		cin >> choice;
		exit = processChoice(system,choice);
		cout << endl;
	}

	_CrtDumpMemoryLeaks();
}
