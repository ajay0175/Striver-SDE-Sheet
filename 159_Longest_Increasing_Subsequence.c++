#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence
int get(vector<int> &v, int target)
{
    return lower_bound(v.begin(), v.end(), target) - v.begin();
}

int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> LIS;
    
    for(auto &currVal : nums)
    {
        if(LIS.empty() or currVal > LIS.back())
        {
            LIS.emplace_back(currVal);
        }
        else
        {
            LIS[get(LIS, currVal)] = currVal;
        }
    }
    
    return LIS.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(nums) << '\n';
    
    return 0;
}

/*
    APPROACH: DP with Binary Search

    Time Complexity: O(NLog(N))
        lower_bound which has a time complexity of O(log N).

    Space Complexity: O(N)
*/