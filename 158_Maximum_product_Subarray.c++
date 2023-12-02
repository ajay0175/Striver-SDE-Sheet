#include<bits/stdc++.h>
using namespace std;

/*Approach 1*/
int maxProductSubArray1(vector<int>& nums) {
    int result = nums[0];
    for(int i = 0; i < nums.size() - 1; i++) {
        int p = nums[i];
        for(int j = i + 1; j < nums.size(); j++) {
           result = max(result, p);
           p *= nums[j];
        }
        result = max(result, p);//manages (n-1)th term 
    }
    return result;
}

/*Approach 2*/
int maxProductSubArray2(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, -3, 0, -4, -5, 24, -2, -4, -9};
    cout<<"The maximum product subarray1: "<<maxProductSubArray1(nums) << '\n';
    cout<<"The maximum product subarray2: "<<maxProductSubArray2(nums) << '\n';
    return 0;
}

/*
    APPROACH 1

    Time Complexity: O(N^2)
        We are using two nested loops.

    Space Complexity: O(1)


    APPROACH 2
    
    Time Complexity: O(N)

    Space Complexity: O(1)

*/