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
bool System::followUser(const string& targetUsername)
{
	if (!isLoggedIn())
	{
		return false;
	}
	int idx = findUserIndex(targetUsername);
	if (idx == -1)
	{
		return false;
	}
	if (idx == currentUserIndex)
	{
		return false;
	}
	users[currentUserIndex].follow(idx);
	return true;
}
bool System::unfollowUser(const string& targetUsername)
{
	if (!isLoggedIn())
	{
		return false;
	}
	int idx = findUserIndex(targetUsername);
	if (idx == -1)
	{
		return false;
	}
	if (idx == currentUserIndex)
	{
		return false;
	}
	users[currentUserIndex].unfollow(idx);
	return true;
}
// getters
int System::getPostCount() const
{
	return postsCount;
}
string System::getPostContent(int index) const
{
	return posts[index].getContent();
}
string System::getPostAuthorUsername(int index) const
{
	int authorIdx = posts[index].getAuthorIndex();
	return users[authorIdx].getUsername();
}
int System::getPostLikeCount(int index) const
{
	return posts[index].getLikeCount();
}
int System::getPostViews(int index) const
{
	return posts[index].getViews();
}
int System::getPostCommentCount(int index) const
{
	return posts[index].getCommentCount();
}
string System::getCurrentUsername() const
{
	return users[currentUserIndex].getUsername();
}
// features
bool System::likePost(int index)
{
	if (!isLoggedIn())
	{
		return false;
	}
	if (index < 0 || index >= postsCount)
	{
		return false;
	}
	posts[index].like(currentUserIndex);
	return true;
}
bool System::commentOnPost(int index, const string& commentText)
{
	if (!isLoggedIn())
	{
		return false;
	}
	if (index < 0 || index >= postsCount)
	{
		return false;
	}
	posts[index].addComment(commentText);
	return true;
}
void System::viewPost(int index)
{
	if (index < 0 || index >= postsCount)
	{
		return;
	}
	posts[index].addView(currentUserIndex);
}
string System::getPostComment(int postIndex, int commentIndex) const
{
	return posts[postIndex].getComment(commentIndex);
}
