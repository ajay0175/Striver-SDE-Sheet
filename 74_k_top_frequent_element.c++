#include<bits/stdc++.h>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int, int> freq;
        
        for(auto &e : nums)
            freq[e]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto &e : freq)
            pq.push({e.second, e.first});
        
        
        while(k--)
        {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
            
    }

int main()
{
    int k = 2;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = topKFrequent(nums, k);

    for(auto &e : ans)
    {
        cout << e << " ";
    }
}

/*
    TC => O(N) // N IS A SIZE NUMS
    SC => O(P + Q) P IS SIZE OF MAP AND Q IS THE SIZE OF MAX HEAP
*/