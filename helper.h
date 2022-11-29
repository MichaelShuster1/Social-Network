#ifndef HELPER
#define HELPER

#include "system.h"


void addNewUserToSystem(System& system); //creates new user and adds him to the system
void addNewPageToSystem(System& system); //creates new page and adds him to the system
void printAllRegisteredEntitiesInSystem(System& system); //prints all the registered entities in system
int chooseOneMember(System& system); //chooses one member from the already existing members in system
int chooseOneFriendOfAMember(System& system,int index);//chooses one friend of the given member in system
int chooseOnePage(System& system); //chooses one page from the already existing pages in system
int chooseOneFanOfAPage(System& system, int index); //chooses one fan of the given page in system
void printAllFriendsOrFansEntity(System& system); //prints all friends or fans of the system
Status* createNewStatus(); //creates new status and returns it
void addNewStatusToFanPageOrMember(System& system);//adds new status to a given fan or member in system
void showAllStatusesOfAFanPageOrMember(System& system);//shows all statuses of a given page or mebmer in system
void ShowTenStatusesOfEachFriend(System& system); //Shows all the last 10 statuses of the user's friends
void linkFriendshipInSystem(System& system); //links two members as friends in system
void unLinkFriendshipInSystem(System& system);  //unlikns two friends in system
void addFanToPageInSystem(System& system); //adds a fan to a given page in system
void removeFanFromPageInSystem(System& system);  //remvoes a fan from a given page in system
void printMenu();// prints the menu
bool processChoice(System& system, int choice); //process the given choice of the user of the system
//int chooseOneLinkOption(System& system,int index);
bool checkValidInput(System& system, int index1, int index2); //checks if the given indexs are vaild input or not

#endif // !HELPER

