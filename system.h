#ifndef SYSTEM_H
#define SYSTEM_H

#include "member.h"
#include "page.h"
#include <string.h>
#include <ctime>

const int NAME_LEN = 100;

void copyMemberArr(Member** dest, Member** src, int size);
void reSizeMemberArr(Member*** member_array, int old_size, int new_size);
void AddNewUser(Member*** Users, int& size);
void copyPageArr(Fan_page** dest, Fan_page** src, int size);
void reSizePagesArr(Fan_page*** page_array, int old_size, int new_size);
void AddNewPage(Fan_page*** Pages, int& size);
void printAllSysMembers(Member*** Users, int size);
void printAllSysPages(Fan_page*** Pages, int size);
void printAllRegisteredEntities(Member*** Users, int size_u, Fan_page*** Pages, int size_p);
int chooseOneMember(Member*** Users, int size);
int chooseOnePage(Fan_page*** Pages, int size);
void freeMemberArr(Member** Users, int size);
void freePageArr(Fan_page** Pages, int size);
void linkFriends(Member& mem1, Member& mem2);
void unlinkFriends(Member& mem1, Member& mem2);


#endif // !SYSTEM_H
