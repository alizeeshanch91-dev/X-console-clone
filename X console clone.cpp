#include "Post.h"
#include "User.h"
#include <iostream>

using namespace std;

int main()
{
	Post p(0, "Hello world!");
	p.like(1);
	p.like(2);
	p.like(1); // duplicate — should be ignored
	cout << p.getLikeCount() << endl;      // expect 2
	cout << p.hasLiked(1) << endl;          // expect 1
	cout << p.hasLiked(5) << endl;          // expect 0

	p.addComment("Nice post!");
	p.addComment("Second comment");
	cout << p.getCommentCount() << endl;    // expect 2
	cout << p.getComment(0) << endl;         // expect "Nice post!"

	p.addView();
	p.addView();
	cout << p.getViews() << endl;            // expect 2

	return 0;
}
