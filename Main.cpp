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

	int commentCount = sys.getPostCommentCount(index);
	if (commentCount > 0)
	{
		cout << "--- Comments ---\n";
		for (int i = 0; i < commentCount; i++)
		{
			cout << "- " << sys.getPostComment(index, i) << "\n";
		}
	}
	printLine();
}

void displayPostSummary(const System& sys, int index)
{
	string content = sys.getPostContent(index);
	string preview = content.substr(0, 40);
	if (content.length() > 40)
	{
		preview += "...";
	}
	cout << "[" << index << "] @" << sys.getPostAuthorUsername(index) << ": " << preview << "\n";
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

void handlePostDetails(System& sys, int index)
{
	sys.viewPost(index);

	bool viewingPost = true;
	while (viewingPost)
	{
		system("cls");
		displayPost(sys, index);
		cout << "1. Like\n";
		cout << "2. Comment\n";
		cout << "0. Back\n";
		printLine();
		cout << "Choice: ";

		int choice;
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			if (sys.likePost(index))
			{
				cout << "Liked!\n";
			}
			else
			{
				cout << "Could not like this post.\n";
			}
			system("pause");
		}
		else if (choice == 2)
		{
			string commentText;
			cout << "Your comment: ";
			getline(cin, commentText);

			if (sys.commentOnPost(index, commentText))
			{
				cout << "Comment added!\n";
			}
			else
			{
				cout << "Could not add comment.\n";
			}
			system("pause");
		}
		else if (choice == 0)
		{
			viewingPost = false;
		}
	}
}

void handleViewAllPosts(System& sys)
{
	bool browsing = true;
	while (browsing)
	{
		system("cls");
		int count = sys.getPostCount();
		if (count == 0)
		{
			cout << "No posts yet.\n";
			system("pause");
			return;
		}

		printLine();
		for (int i = count - 1; i >= 0; i--)
		{
			displayPostSummary(sys, i);
		}
		printLine();
		cout << "Enter a post number to view details, or -1 to go back: ";

		int choice;
		cin >> choice;
		cin.ignore();

		if (choice == -1)
		{
			browsing = false;
		}
		else if (choice < 0 || choice >= count)
		{
			cout << "Invalid post number.\n";
			system("pause");
		}
		else
		{
			handlePostDetails(sys, choice);
		}
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
				handleViewAllPosts(sys);
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
