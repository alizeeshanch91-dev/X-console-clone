#include "Post.h"

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
void Post::resizeViewedBy()
{
	viewedByCapacity += viewedByCount;
	int* temp = new int[viewedByCapacity];
	for (int i = 0; i < viewedByCount; i++)
	{
		temp[i] = viewedBy[i];
	}
	delete[] viewedBy;
	viewedBy = temp;
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

	viewedByCount = 0;
	viewedByCapacity = 10;
	viewedBy = new int[viewedByCapacity];

	commentCounts = 0;
	commentCapacity = 10;
	comments = new string[commentCapacity];
}
Post::Post(int authorIndex, string content)
{
	views = 0;

	likedByCount = 0;
	likedByCapacity = 10;
	likedBy = new int[likedByCapacity];

	viewedByCount = 0;
	viewedByCapacity = 10;
	viewedBy = new int[viewedByCapacity];

	commentCounts = 0;
	commentCapacity = 10;
	comments = new string[commentCapacity];

	this->content = content;
	this->authorIndex = authorIndex;
}
Post::~Post()
{
	delete[] comments;
	delete[] likedBy;
	delete[] viewedBy;
}
Post::Post(const Post& other)
{
	authorIndex = other.authorIndex;
	content = other.content;
	views = other.views;

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

	viewedByCount = other.viewedByCount;
	viewedByCapacity = other.viewedByCapacity;
	viewedBy = new int[viewedByCapacity];
	for (int i = 0; i < viewedByCount; i++)
	{
		viewedBy[i] = other.viewedBy[i];
	}
}
Post& Post::operator=(const Post& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] comments;
	delete[] likedBy;
	delete[] viewedBy;

	authorIndex = other.authorIndex;
	content = other.content;
	views = other.views;

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

	viewedByCount = other.viewedByCount;
	viewedByCapacity = other.viewedByCapacity;
	viewedBy = new int[viewedByCapacity];
	for (int i = 0; i < viewedByCount; i++)
	{
		viewedBy[i] = other.viewedBy[i];
	}

	return *this;
}
void Post::like(int userIndex)
{
	if (!(Post::hasLiked(userIndex)))
	{
		if (likedByCapacity == likedByCount)
		{
			Post::resizeLikedBy();
		}
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
void Post::addView(int userIndex)
{
	if (!(Post::hasViewed(userIndex)))
	{
		if (viewedByCapacity == viewedByCount)
		{
			Post::resizeViewedBy();
		}
		viewedBy[viewedByCount] = userIndex;
		viewedByCount++;
		views++;
	}
}
bool Post::hasViewed(int userIndex) const
{
	for (int i = 0; i < viewedByCount; i++)
	{
		if (viewedBy[i] == userIndex)
		{
			return true;
		}
	}
	return false;
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
