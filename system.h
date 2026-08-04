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
	bool followUser(const string& targetUsername);
	bool unfollowUser(const string& targetUsername);
	// getters
	int getPostCount() const;
	string getPostContent(int index) const;
	string getPostAuthorUsername(int index) const;
	int getPostLikeCount(int index) const;
	int getPostViews(int index) const;
	int getPostCommentCount(int index) const;
	string getCurrentUsername() const;
};
