# X-console-clone
# Console Twitter/X Clone (C++)

A text-based, console-only clone of Twitter/X, built as a portfolio project.
Implements user accounts, following, posts, likes, and a personalized timeline —
all using manually managed dynamic arrays (no STL containers).

## Features
- User sign up / login
- Follow / unfollow other users
- Create posts
- Like posts
- Timeline: posts from followed users, most recent first
- Persistent storage between runs (save/load to file)

## Build
Requires a C++ compiler (tested with Visual Studio 2022 / MSVC).

    g++ src/*.cpp -o twitter_clone
    ./twitter_clone

## Project structure
- `User.h` / `User.cpp` — user accounts, following/unfollowing
- `Post.h` / `Post.cpp` — posts and likes
- `main.cpp` — program entry point / menu loop

## Status
🚧 In progress — currently implemented: User system.
Next: Post system, timeline, persistence.
