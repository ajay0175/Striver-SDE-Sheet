class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

/*
    TC => O(N! * N) n IS NO. OF ELEMENT AND N! IS A ALL POSSIBLE PERMUTATIOJN SEARCH
    SC => O(1) WE ARE USING ONLY STACK SPACE FOR RECURSION CALLS
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

/*
    TC => O(N)
    SC => O(1)
*/