//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    // Initialize your data structure here
    unordered_map<int,unordered_set<int>> list;
    vector<pair<int,int>> posts;
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int cnt = 1;
        vector<int> ans;
        for(int i=posts.size()-1;i>=0 && cnt<=10;i--){
            int postUserID = posts[i].second;
            int postId = posts[i].first;

            if(postUserID == userId || list[userId].find(postUserID) != list[userId].end()){
                ans.push_back(postId);
                cnt++;
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        list[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        list[followerId].erase(followeeId);
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends