#include "System.h"
#include <iostream>
using namespace std;

void printLine()
{
	cout << "----------------------------------------\n";
}

void showAuthMenu()
{
	printLine();
	cout << "1. Sign Up\n";
	cout << "2. Log In\n";
	cout << "0. Exit\n";
	printLine();
	cout << "Choice: ";
}

void showMainMenu(const string& username)
{
	printLine();
	cout << "Logged in as: " << username << "\n";
	printLine();
	cout << "1. Create Post\n";
	cout << "2. View All Posts\n";
	cout << "3. Follow User\n";
	cout << "4. Unfollow User\n";
	cout << "0. Log Out\n";
	printLine();
	cout << "Choice: ";
}

void displayPost(const System& sys, int index)
{
	cout << "\n@" << sys.getPostAuthorUsername(index) << "\n";
	cout << sys.getPostContent(index) << "\n";
	cout << "Likes: " << sys.getPostLikeCount(index)
		<< "  Views: " << sys.getPostViews(index)
		<< "  Comments: " << sys.getPostCommentCount(index) << "\n";
	printLine();
}

void handleSignUp(System& sys)
{
	string username, password;
	cout << "Choose a username: ";
	getline(cin, username);
	cout << "Choose a password: ";
	getline(cin, password);

	if (sys.signUp(username, password))
	{
		cout << "Account created. You can now log in.\n";
	}
	else
	{
		cout << "That username is already taken.\n";
	}
}

void handleLogIn(System& sys, bool& loggedIn)
{
	string username, password;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	if (sys.logIn(username, password))
	{
		cout << "Welcome back, " << username << "!\n";
		loggedIn = true;
	}
	else
	{
		cout << "Incorrect username or password.\n";
	}
}

void handleCreatePost(System& sys)
{
	string content;
	cout << "What's happening? ";
	getline(cin, content);

	if (sys.createPost(content))
	{
		cout << "Posted!\n";
	}
	else
	{
		cout << "Could not create post.\n";
	}
}

void handleViewAllPosts(System& sys)
{
	int count = sys.getPostCount();
	if (count == 0)
	{
		cout << "No posts yet.\n";
		return;
	}

	printLine();
	for (int i = count - 1; i >= 0; i--)
	{
		displayPost(sys, i);
	}
}

void handleFollow(System& sys)
{
	string target;
	cout << "Username to follow: ";
	getline(cin, target);

	if (sys.followUser(target))
	{
		cout << "You are now following " << target << ".\n";
	}
	else
	{
		cout << "Could not follow that user.\n";
	}
}

void handleUnfollow(System& sys)
{
	string target;
	cout << "Username to unfollow: ";
	getline(cin, target);

	if (sys.unfollowUser(target))
	{
		cout << "You unfollowed " << target << ".\n";
	}
	else
	{
		cout << "Could not unfollow that user.\n";
	}
}
int main()
{
	System sys;
	bool running = true;
	bool loggedIn = false;
	int choice;

	while (running)
	{
		system("cls");

		if (!loggedIn)
		{
			showAuthMenu();
			cin >> choice;
			cin.ignore();

			if (choice == 1)
			{
				system("cls");
				handleSignUp(sys);
				system("pause");
			}
			else if (choice == 2)
			{
				system("cls");
				handleLogIn(sys, loggedIn);
				system("pause");
			}
			else if (choice == 0)
			{
				running = false;
			}
		}
		else
		{
			showMainMenu(sys.getCurrentUsername());
			cin >> choice;
			cin.ignore();

			if (choice == 1)
			{
				system("cls");
				handleCreatePost(sys);
				system("pause");
			}
			else if (choice == 2)
			{
				system("cls");
				handleViewAllPosts(sys);
				system("pause");
			}
			else if (choice == 3)
			{
				system("cls");
				handleFollow(sys);
				system("pause");
			}
			else if (choice == 4)
			{
				system("cls");
				handleUnfollow(sys);
				system("pause");
			}
			else if (choice == 0)
			{
				sys.logOut();
				loggedIn = false;
				cout << "Logged out.\n";
				system("pause");
			}
		}
	}

	system("cls");
	cout << "Goodbye!\n";
	return 0;
}
