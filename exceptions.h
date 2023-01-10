#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

/*----------------------------------User Exceptions---------------------------------------*/

class UserException : public std::exception
{
public:
	virtual const char* what() const override { return "user error"; }
};

class EmptyUserNameException : public UserException
{
public:
	virtual const char* what() const override { return "the given name for the new user is empty\n"; }
};

class UserLinkingException : public UserException
{
public:
	virtual const char* what() const override { return "the given two users are already linked in the system\n"; }
};

class UserLinkingPageException : public UserException
{
public:
	virtual const char* what() const override { return "the given page is already followed by the given member\n"; }
};

class UnLinkingException : public UserException
{
public:
	virtual const char* what() const override { return "those users are already not linked\n"; }
};

class RemovePageException : public UserException
{
public:
	virtual const char* what() const override { return "the given page is not followed by the given member\n"; }
};

class invalidUserNameException : public UserException
{
public:
	virtual const char* what() const override { return "the name must start with a latter\n"; }
};

/*---------------------------------System Exceptions----------------------------------------*/

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
	virtual const char* what() const override { return "the first user entered doesn't have friends to delete\n"; }
};


class NoFriendsSecondException : public SystemException
{
public:
	virtual const char* what() const override { return "the second user entered doesn't have friends to delete\n"; }
};

/*----------------------------------Date Exceptions-------------------------------------*/

class DateException : public std::exception
{
public:
	virtual const char* what() const override { return "date error"; }
};

class DateFormatException : public DateException
{
public:
	virtual const char* what() const override { return "Incorrect birth date\n"; }
};

/*---------------------------------Fan Page Exceptions---------------------------------------*/

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

class invalidPageNameException : public FanPageException
{
public:
	virtual const char* what() const override { return "the name must start with a latter\n"; }
};

/*----------------------------------Status Exceptions---------------------------------------*/

class StatusException : public std::exception
{
public:
	virtual const char* what() const override { return "Status error"; };
};


class EmptyTextException : public StatusException
{
public:
	virtual const char* what() const override { return "the given status text is empty\n"; };
};


class EmptyTimeException : public StatusException
{
public:
	virtual const char* what() const override { return "the given time is empty\n"; };
};

class EmptyPictureException : public StatusException
{
public:
	virtual const char* what() const override { return "the given picture name is empty\n"; };
};

class PictureExtensionException : public StatusException
{
public:
	virtual const char* what() const override { return "the only permitted extensions for pictures are jpg and png\n"; };
};

class EmptyVideoException : public StatusException
{
public:
	virtual const char* what() const override { return "the given video name is empty\n"; };
};









#endif // !

