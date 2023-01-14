#include "helper.h"
using namespace std;



void main()
{
	bool exit = false;
	int choice;
	System system;

	string test = "picture.png";

	if (StatusPicture::checkExtension(test, ".jpg"))
		cout << "yes\n";
	else
		cout << "no\n";

	
	while (exit == false)
	{
		printMenu();
		cin >> choice;
		exit = processChoice(system, choice);
		cout << endl;
	}
}

