/*
Concepts Learnt: Max Queue

Statement: 
You are given an array of integers nums, there is a sliding window 
of size k which is moving from the very left of the array to the very 
right. You can only see the k numbers in the window. Each time the 
sliding window moves right by one position.
Return the sliding window maximums.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> q;
    
    for(int i = 0; i < k; i++){
        while(!q.empty() && q.back() < nums[i]){
            q.pop_back();
        } 
        q.push_back(nums[i]);
    }
    ans.push_back(q.front());
    
    for(int i = k; i < (int)nums.size(); i++){
        if(q.front() == nums[i-k]) q.pop_front();
        while(!q.empty() && q.back() < nums[i]){
            q.pop_back();
        } 
        q.push_back(nums[i]);
        ans.push_back(q.front());
    }
    return ans;
}

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7}; //Array of numbers;
    int k = 3; //Sliding window size;
    vector<int> sol = maxSlidingWindow(arr, k);
    cout<<"The sliding window maximums are: "<<endl;
    for(int m : sol){
        cout<<m<<" ";
    }
    return 0;
}