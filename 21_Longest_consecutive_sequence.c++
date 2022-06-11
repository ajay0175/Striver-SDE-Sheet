#include<bits/stdc++.h>
using namespace std;

    int longestConsecutive1(vector<int>& nums) {
      if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        int ans = 1;
        int cur = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                cur++;
            }
            else if(nums[i] != nums[i - 1]){
                cur = 1;
            }
            ans = max(ans, cur);
        }
        return ans;
    }

int longestConsecutive2(vector<int>& nums) {
    unordered_set<int>s;
    int cnt=1,ans=0;
    for(int x:nums)s.insert(x);
    for(auto i:s){
        if(s.find(i-1)==s.end()){
            int cnt=1;
            while(s.find(i+1)!=s.end()){
                s.erase(i+1);
                i++;
                cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{100,200,1,2,3,4};
    int lon = longestConsecutive1(arr);
    cout<<"The longest consecutive sequence is "<<lon<<endl;
        
}

/*
    longestConsecutive1
    TC => O(NLOGN)
    SC=> O(1)
*/

/*
    longestConsecutive12
    TC => O(N)
    SC=> O(N)
*/