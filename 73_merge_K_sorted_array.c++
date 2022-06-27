#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < nums[i].size(); j++)
        {
            minheap.emplace(nums[i][j]);
        }
    }
       
    vector<int> ans;
    while(!minheap.empty())
    {
        ans.emplace_back(minheap.top());
        minheap.pop();
    }
    
    return ans;
}

int main()
{
    int k = 2;
    int t = k;
    vector<vector<int>> nums;
    while(t--)
    {
        int n; cin >> n;
        vector<int> temp(n);
        
        for(int i = 0; i < n; i++) cin >> temp[i];
        nums.push_back(temp);
    }
}
