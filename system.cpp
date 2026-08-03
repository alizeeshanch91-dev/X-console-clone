#include "system.h"

void System::resizeUsers()
{
	usersCapacity += usersCount;
	user* temp = new user[usersCapacity];
	for (int i = 0; i < usersCount; i++)
	{
		temp[i] = users[i];
	}
	delete[] users;
	users = temp;
}
void System::resizePosts()
{
	postsCapacity += postsCount;
	Post* temp = new Post[postsCapacity];
	for (int i = 0; i < postsCount; i++)
	{
		temp[i] = posts[i];
	}
	delete[] posts;
	posts = temp;
}
int System::findUserIndex(const string& username) const
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getUsername() == username)
		{
			return i;
		}
	}
	return -1;
}
System::System()
{
	usersCount = 0;
	postsCount = 0;
	currentUserIndex = -1;
	usersCapacity = 5;
	postsCapacity = 5;
	users = new user[usersCapacity];
	posts = new Post[postsCapacity];
}
System::~System()
{
	delete[] users;
	delete[] posts;
}
bool System::signUp(const string& username, const string& password)
{
	if (System::findUserIndex(username) != -1)
	{
		return false;
	}
	if (usersCount == usersCapacity)
	{
		System::resizeUsers();
	}
	users[usersCount] = user(username, password);
	usersCount++;
	return true;
}
bool System::logIn(const string& username, const string& password)
{
	int idx = findUserIndex(username);
	if (idx == -1)
	{
		return false;
	}
	if (!users[idx].checkPassword(password))
	{
		return false;
	}
	currentUserIndex = idx;
	return true;
}
void System::logOut()
{
	currentUserIndex = -1;
}
bool System::isLoggedIn() const
{
	return currentUserIndex != -1;
}
bool System::createPost(const string& content)
{
	if (!isLoggedIn())
	{
		return false;
	}
	if (postsCount == postsCapacity)
	{
		resizePosts();
	}
	posts[postsCount] = Post(currentUserIndex, content);
	postsCount++;
	return true;
}