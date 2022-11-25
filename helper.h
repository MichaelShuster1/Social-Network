#ifndef HELPER
#define HELPER

#include "system.h"


void addNewUserToSystem(System& system);
void addNewPageToSystem(System& system);
void printAllRegisteredEntitiesInSystem(System& system);
int chooseOneMember(System& system);
int chooseOnePage(System& system);
void printAllFriendsOrFansEntity(System& system);
void unlinkFanFromPage(Member& mem, Fan_page& page);
Status* createNewStatus();
void addNewStatusToFanPageOrMember(System& system);
void showAllStatusesOfAFanPageOrMember(System& system);
void ShowTenStatusesOfEachFriend(System& system);
void linkFriendshipInSystem(System& system);
void unLinkFriendshipInSystem(System& system); //not working for the meantime
void addFanToPageInSystem(System& system);
void removeFanFromPageInSystem(System& system); //not working for the meantime
void printMenu();
bool processChoice(System& system, int choice);

#endif // !HELPER

