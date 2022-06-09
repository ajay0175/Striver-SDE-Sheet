class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        
        for(int i = 0; i < n; i++)
        {   
            mp[nums[i]]++;
        }
        
        int i = 0;
        
        for(auto &e : mp)
        {
            while(e.second)
            {
                e.second--;
                nums[i] = e.first;
                i++;
            }
        }
    }
};

/*
    TC => O(N)
    SC => O(1)
*/