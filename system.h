#ifndef SYSTEM_H
#define SYSTEM_H

#include "member.h"
#include "page.h"
#include <string.h>
#include <ctime>

const int NAME_LEN = 100;

void copyMemberArr(Member** dest, Member** src, int size);
void reSizeMemberArr(Member*** member_array, int old_size, int new_size);
void AddNewUser(Member*** Users, int& logic_size, int& phyical_size);
int getMin(int num1, int num2);
void copyPageArr(Fan_page** dest, Fan_page** src, int size);
void reSizePagesArr(Fan_page*** page_array, int old_size, int new_size);
void AddNewPage(Fan_page*** Pages, int& size, int& physical_size);
void printAllSysMembers(Member** Users, int size);
void printAllSysPages(Fan_page** Pages, int size);
void printAllRegisteredEntities(Member** Users, int size_u, Fan_page** Pages, int size_p);
int chooseOneMember(Member** Users, int size);
int chooseOnePage(Fan_page** Pages, int size);
void freeMemberArr(Member** Users, int size);
void freePageArr(Fan_page** Pages, int size);
void linkFriends(Member& mem1, Member& mem2);
void unlinkFriends(Member& mem1, Member& mem2);
void printAllfriendsOrFansOfanEntity(Member** Users, int size_u, Fan_page** Pages, int size_p);
void linkFanToPage(Member& mem, Fan_page& page);
void unlinkFanFromPage(Member& mem, Fan_page& page);
Status createNewStatus();
void addNewStatusToFanPageOrMember(Member** System_Members, int members_size, Fan_page** System_Pages, int pages_size);
void showAllStatusesOfAFanPageOrMember(Member** System_Members, int members_size, Fan_page** System_Pages, int pages_size);
void ShowTenLatestStatusesOfEachFriend(Member** System_Members, int members_size);
void linkFriendship(Member** System_Members, int members_size);
void unLinkFriendship(Member** System_Members, int members_size);
void addFanToAFanPage(Member** System_Members, int members_size, Fan_page** System_Pages, int pages_size);
void removeAFanFromAFanPage(Fan_page** System_Pages, int pages_size);
void printMenu();
void createHardcodedEntities(Member** System_Members, Fan_page** System_Pages);
bool checkIfExistNameUser(Member** System_Members, char* name, int size);
bool checkIfExistNamePage(Fan_page** System_pages, char* name, int size);

#endif // !SYSTEM_H
