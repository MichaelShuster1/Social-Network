#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

/*-------------------------------------------------------------------------*/

class UserException : public std::exception
{
public:
	virtual const char* what() const override { return "user error"; }
};

class EmptyUserNameException : public UserException
{
public:
	virtual const char* what() const override { return "the given name for the new page is empty"; }
};

class UserLinkingException : public UserException
{
public:
	virtual const char* what() const override { return "the given two users are already linked in the system"; }
};

class UserLinkingPageException : public UserException
{
public:
	virtual const char* what() const override { return "the given page is already followed by the given member"; }
};

class UnLinkingException : public UserException
{
public:
	virtual const char* what() const override { return "those users are already not linked"; }
};

class RemovePageException : public UserException
{
public:
	virtual const char* what() const override { return "the given page is not followed by the given member"; }
};

/*---------------------------------User Exceptions----------------------------------------*/

class SystemException : public std::exception
{
public:
	virtual const char* what() const override { return "system error"; }
};


class UserNotFoundException : public SystemException
{
public:
	virtual const char* what() const override { return "the user with the given name was not found in the system\n"; }
};


class FirstUserNotFoundException : public SystemException
{
public:
	virtual const char* what() const override { return "the first user was not found in the system\n"; }
};

class SecondUserNotFoundException : public SystemException
{
public:
	virtual const char* what() const override { return "the second user was not found in the system\n"; }
};

class SameUsersException : public SystemException
{
public:
	virtual const char* what() const override { return "the given two users are the same user\n"; }
};

class UserNameTakenException : public SystemException
{
public:
	virtual const char* what() const override { return "the name is already taken!\n"; }
};


class PageNotFoundException : public SystemException
{
public:
	virtual const char* what() const override { return "the page with the given name was not found in the system\n"; }
};


class NoFriendsFirstException : public SystemException
{
public:
	virtual const char* what() const override { return "the first user entered doesn't have friends to delete"; }
};


class NoFriendsSecondException : public SystemException
{
public:
	virtual const char* what() const override { return "the second user entered doesn't have friends to delete"; }
};

/*----------------------------------System Exceptions-------------------------------------*/

class DateException : public std::exception
{
public:
	virtual const char* what() const override { return "date error"; }
};

class DateFormatException : public DateException
{
public:
	virtual const char* what() const override { return "Incorrect birth date"; }
};

/*---------------------------------Date Exceptions---------------------------------------*/

class FanPageException : public std::exception
{
public:
	virtual const char* what() const override { return "Fan page error"; }
};


class EmptyPageNameException : public FanPageException
{
public:
	virtual const char* what() const override { return "the given name for the new page is empty\n"; }
};


class NotFanException : public FanPageException
{
public:
	virtual const char* what() const override { return "the given member is not a fan of the given page\n"; }
};

class NoFansException : public SystemException
{
public:
	virtual const char* what() const override { return "the given page doesn't have any fans to delete\n"; }
};


class AddFanException : public FanPageException
{
public:
	virtual const char* what() const override { return "the given member is already a fan of the given page\n"; }
};

/*----------------------------------Fan Page Exceptions---------------------------------------*/

class StatusException : public std::exception
{
public:
	virtual const char* what() const override { return "Status error"; };
};


class EmptyTextException : public StatusException
{
public:
	virtual const char* what() const override { return "the given text is empty\n"; };
};


class EmptyTimeException : public StatusException
{
public:
	virtual const char* what() const override { return "the given time is empty\n"; };
};


/*-----------------------------------Status Exceptions-----------------------------------*/








#endif // !

