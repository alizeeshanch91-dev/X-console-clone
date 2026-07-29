#include"User.h"

user::user(string username, string password)
{
	this->username = username;
	this->password = password;
	followingCapacity = 4;
	following = new int[followingCapacity];
	followingCount = 0;
}
user::user(const user& other)
{
	username = other.username;
	password = other.password;
	followingCount = other.followingCount;
	followingCapacity = other.followingCapacity;
	following = new int[followingCapacity];
	for (int i = 0; i < followingCount; i++)
	{
		following[i] = other.following[i];
	}
}
user& user::operator=(const user& other)
{
	if (this == &other)
		return *this;

	delete[] following;

	username = other.username;
	password = other.password;
	followingCount = other.followingCount;
	followingCapacity = other.followingCapacity;

	following = new int[followingCapacity];
	for (int i = 0; i < followingCount; i++)
	{
		following[i] = other.following[i];
	}

	return *this;
}
void user::resizeFollowing()
{
	followingCapacity += followingCount;
	int* temp = new int[followingCapacity];

	for (int i = 0; i < followingCount; i++)
	{
		temp[i] = following[i];
	}
	delete[] following;             
	following = temp;
}
user::~user()
{
	delete[] following;
}
void user::follow(int userIndex)
{
	if (!user::isFollowing(userIndex))
	{
		if (followingCount == followingCapacity)
		{
			user::resizeFollowing();
		}
		following[followingCount]=userIndex;
		followingCount++;
	}
}
bool user::isFollowing(int userIndex) const
{
	for (int i = 0; i < followingCount; i++)
	{
		if (userIndex == following[i])
		{
			return true;
		}
	}
	return false;
}
string user::getUsername() const
{
	return username;
}
bool user::checkPassword(const string& attempt) const
{
	return password == attempt;
}
void user::unfollow(int userIndex)
{
	for (int i = 0; i < followingCount; i++)
	{
		if (following[i] == userIndex)
		{
			for (int j = i; j < followingCount - 1; j++)
			{
				following[j] = following[j + 1];
			}
			followingCount--;
			return;
		}
	}
}
const int* user::getFollowing() const
{
	return following;
}
int user::getFollowingCount() const
{
	return followingCount;
}