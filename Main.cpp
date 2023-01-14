#include "helper.h"
using namespace std;


#define new MYDEBUG_NEW

#ifdef _DEBUG
#define MYDEBUG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define MYDEBUG_NEW new

#endif // _DEBUG

#include <crtdbg.h>



void main()
{
	bool exit = false;
	int choice;


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		System system;


		while (exit == false)
		{
			printMenu();
			cin >> choice;
			exit = processChoice(system, choice);
			cout << endl;
		}
	}
}

