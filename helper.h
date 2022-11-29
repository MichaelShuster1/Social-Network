#ifndef HELPER
#define HELPER

#include "system.h"


void addNewUserToSystem(System& system);
void addNewPageToSystem(System& system);
void printAllRegisteredEntitiesInSystem(System& system);
int chooseOneMember(System& system);
int chooseOneFriendOfAMember(System& system,int index);
int chooseOnePage(System& system);
int chooseOneFanOfAPage(System& system, int index);
void printAllFriendsOrFansEntity(System& system);
Status* createNewStatus();
void addNewStatusToFanPageOrMember(System& system);
void showAllStatusesOfAFanPageOrMember(System& system);
void ShowTenStatusesOfEachFriend(System& system);
void linkFriendshipInSystem(System& system);
void unLinkFriendshipInSystem(System& system); 
void addFanToPageInSystem(System& system);
void removeFanFromPageInSystem(System& system); 
void printMenu();
bool processChoice(System& system, int choice);
int chooseOneLinkOption(System& system,int index);
bool checkValidInput(System& system, int index1, int index2);

#endif // !HELPER

