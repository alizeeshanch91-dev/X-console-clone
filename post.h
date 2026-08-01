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
	int linkedByCapacity;
	void resizeLikedBy();

	string* comments;
	int commentCounts;
	int commentCapacity;
	void resizeComments();
public:
	post();
	Post(int authorIndex, string content);
	~Post();
	Post(const Post& other);
	Post& operator=(const Post& other);
	void like(int userIndex);
	bool hasLiked(int userIndex) const;
	void addView();
	void addComment(const string& commentyText);
	//getters
	int getAuthorIndex() const;
	string getContent() const;
	int getViews() const;
	int getLikeCount() const;
	int getCommentCount() const;
	string getComment(int index) const;
};
