#pragma once
#include "User.h"
#include "Post.h"
#include <string>
using namespace std;

class System
{
private:
	user* users;
	int usersCount;
	int usersCapacity;
	void resizeUsers();

	Post* posts;
	int postsCount;
	int postsCapacity;
	void resizePosts();

	int currentUserIndex;
	int findUserIndex(const string& username) const;

public:
	System();
	~System();
	bool signUp(const string& username, const string& password);
	bool logIn(const string& username, const string& password);
	void logOut();
	bool isLoggedIn() const;
	bool createPost(const string& content);
};