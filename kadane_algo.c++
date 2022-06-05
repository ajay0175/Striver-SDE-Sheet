class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0], ans = nums[0];
        
        for(int i = 1; i < n ; i++)
        {
           sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        
        return ans;
    }
};

// Both work in same Time complexity

long long maxSubarraySum(int nums[], int n)
{
        long long sum = 0;
        long long ans = 0;
        
        for(int i = 0; i < n ; i++)
        {
            if(nums[i] <= (sum + nums[i]))
                 sum += nums[i];  
           
            ans = max(ans, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return ans;
}

/*
    TC=> O(N)
    SC => O(1)
*/