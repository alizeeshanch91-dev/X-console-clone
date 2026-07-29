// temporary main.cpp, just to verify it builds
#include "User.h"
#include <iostream>

int main()
{
	user u("alice", "pass123");
	u.follow(5);
	u.follow(2);
	std::cout << u.isFollowing(5) << std::endl;
	u.unfollow(5);
	std::cout << u.isFollowing(5) << std::endl;
	return 0;
}