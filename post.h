#pragma once
#include <string>
using namespace std;

class Post
{
private:
	int authorIndex;
	string content;
	int views;

	int* likedBy;
	int likedByCount;
	int likedByCapacity;
	void resizeLikedBy();

	int* viewedBy;
	int viewedByCount;
	int viewedByCapacity;
	void resizeViewedBy();

	string* comments;
	int commentCounts;
	int commentCapacity;
	void resizeComments();
public:
	Post();
	Post(int authorIndex, string content);
	~Post();
	Post(const Post& other);
	Post& operator=(const Post& other);
	void like(int userIndex);
	bool hasLiked(int userIndex) const;
	void addView(int userIndex);
	bool hasViewed(int userIndex) const;
	void addComment(const string& comment_Text);
	//getters
	int getAuthorIndex() const;
	string getContent() const;
	int getViews() const;
	int getLikeCount() const;
	int getCommentCount() const;
	string getComment(int index) const;
};
