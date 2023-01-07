#ifndef HELPER
#define HELPER

#include "system.h"
#include <string>

const int MEMBER = 1;
const int FAN_PAGE = 2;
const int NO = 'n';
const int YES = 'y';
const int ADD_NEW_USER = 1;
const int ADD_NEW_PAGE = 2;
const int ADD_NEW_STATUS = 3;
const int SHOW_ALL_STATUSES = 4;
const int SHOW_TEN_STATUSES = 5;
const int LINK_FRIENDS = 6;
const int UNLINK_FRIENDS = 7;
const int ADD_FAN = 8;
const int REMOVE_FAN = 9;
const int PRINT_ALL_ENTITIES = 10;
const int PRINT_ALL_FANS_FRIENDS = 11;
const int EXIT = 12;
const int TEXT_STATUS = 1;
const int PICTURE_STATUS = 2;
const int VIDEO_STATUS = 3;

void addNewUserToSystem(System& system); //creates new user and adds him to the system
void addNewPageToSystem(System& system); //creates new page and adds him to the system
void printAllRegisteredEntitiesInSystem(System& system); //prints all the registered entities in system
void chooseOneMember(std::string& name); //chooses one member from the already existing members in system
void chooseOnePage(std::string& name); //chooses one page from the already existing pages in system
void printAllFriendsOrFansEntity(System& system); //prints all friends or fans of the system
void createNewStatus(Status** newStatus); //creates new status and returns it by pointer
void addNewStatusToFanPageOrMember(System& system);//adds new status to a given fan or member in system
void showAllStatusesOfAFanPageOrMember(System& system);//shows all statuses of a given page or mebmer in system
void ShowTenStatusesOfEachFriend(System& system); //Shows all the last 10 statuses of the user's friends
void linkFriendshipInSystem(System& system); //links two members as friends in system
void unLinkFriendshipInSystem(System& system);  //unlikns two friends in system
void addFanToPageInSystem(System& system); //adds a fan to a given page in system
void removeFanFromPageInSystem(System& system);  //remvoes a fan from a given page in system
void printMenu();// prints the menu
bool processChoice(System& system, int choice); //process the given choice of the user of the system
void choosePagesOrMembers(int& choice); //chooses if the user want to make an action on members or users

#endif // !HELPER

