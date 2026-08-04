#include "post.h"

void Post::resizeLikedBy()
{
	likedByCapacity += likedByCount;
	int* temp = new int[likedByCapacity];
	for (int i = 0; i < likedByCount; i++)
	{
		temp[i] = likedBy[i];
	}
	delete[] likedBy;
	likedBy = temp;
}
void Post::resizeComments()
{
	commentCapacity += commentCounts;
	string* temp = new string[commentCapacity];
	for (int i = 0; i < commentCounts; i++)
	{
		temp[i] = comments[i];
	}
	delete[] comments;
	comments = temp;
}
Post::Post()
{
	authorIndex = -1;
	content = "";
	views = 0;
	likedByCount = 0;
	likedByCapacity = 10;
	likedBy = new int[likedByCapacity];
	commentCounts = 0;
	commentCapacity = 10;
	comments = new string[commentCapacity];
}
Post::Post(int authorIndex, string content)
{
	views = 0;
	likedByCount = 0;
	likedByCapacity = 10;
	commentCounts = 0;
	commentCapacity = 10;
	likedBy = new int[likedByCapacity];
	comments = new string[commentCapacity];
	this->content = content;
	this->authorIndex = authorIndex;
}
Post::~Post()
{
	delete[] comments;
	delete[] likedBy;
}
Post::Post(const Post& other)
{
	authorIndex = other.authorIndex;
	content = other.content;
	commentCounts = other.commentCounts;
	commentCapacity = other.commentCapacity;
	comments = new string[commentCapacity];
	for (int i = 0; i < commentCounts; i++)
	{
		comments[i] = other.comments[i];
	}
	likedByCount = other.likedByCount;
	likedByCapacity = other.likedByCapacity;
	likedBy = new int[likedByCapacity];
	for (int i = 0; i < likedByCount; i++)
	{
		likedBy[i] = other.likedBy[i];
	}
	views = other.views;
}
Post& Post::operator=(const Post& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] comments;
	delete[] likedBy;
	authorIndex = other.authorIndex;
	content = other.content;
	commentCounts = other.commentCounts;
	commentCapacity = other.commentCapacity;
	comments = new string[commentCapacity];
	for (int i = 0; i < commentCounts; i++)
	{
		comments[i] = other.comments[i];
	}
	likedByCount = other.likedByCount;
	likedByCapacity = other.likedByCapacity;
	likedBy = new int[likedByCapacity];
	for (int i = 0; i < likedByCount; i++)
	{
		likedBy[i] = other.likedBy[i];
	}
	views = other.views;
	return *this;
}
void Post::like(int userIndex)
{
	if (!(Post::hasLiked(userIndex)))
	{
		if(likedByCapacity == likedByCount)
		Post::resizeLikedBy();

		likedBy[likedByCount] = userIndex;
		likedByCount++;
	}
}
bool Post::hasLiked(int userIndex) const
{
	for (int i = 0; i < likedByCount; i++)
	{
		if (likedBy[i] == userIndex)
		{
			return true;
		}
	}
	return false;
}
void Post::addView()
{
	views++;
}
void Post::addComment(const string& comment_Text)
{
	if (commentCapacity == commentCounts)
	{
		Post::resizeComments();
	}
	comments[commentCounts] = comment_Text;
	commentCounts++;
}
int Post::getAuthorIndex() const
{
	return authorIndex;
}

string Post::getContent() const
{
	return content;
}

int Post::getViews() const
{
	return views;
}

int Post::getLikeCount() const
{
	return likedByCount;
}

int Post::getCommentCount() const
{
	return commentCounts;
}

string Post::getComment(int index) const
{
	return comments[index];
}
