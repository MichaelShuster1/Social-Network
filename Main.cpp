#include "helper.h"
using namespace std;


void main()
{
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

