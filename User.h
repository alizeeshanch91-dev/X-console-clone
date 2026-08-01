#pragma once

#include <string>
using namespace std;
class user
{
private:
	string username;
	string password;
	int* following;
	int followingCount;
	int followingCapacity;
	void resizeFollowing();
public:
	user();
	user(string username, string password);
	user(const user& other);
	~user();
	user& operator = (const user& other);
	void follow(int userIndex);
	void unfollow(int userIndex);
	bool isFollowing(int userIndex) const;
	string getUsername() const;
	bool checkPassword(const string& attempt) const;
	const int* getFollowing() const;
	int getFollowingCount() const;
};
