#include "System.h"
#include <iostream>

using namespace std;

int main()
{
	System s;

	cout << s.signUp("alice", "pass123") << endl;   // expect 1
	cout << s.signUp("alice", "different") << endl; // expect 0 (duplicate)

	cout << s.logIn("alice", "wrong") << endl;      // expect 0
	cout << s.logIn("alice", "pass123") << endl;    // expect 1
	cout << s.isLoggedIn() << endl;                 // expect 1

	cout << s.createPost("Hello world!") << endl;   // expect 1

	s.logOut();
	cout << s.isLoggedIn() << endl;                 // expect 0
	cout << s.createPost("Should fail") << endl;    // expect 0

	return 0;
}
