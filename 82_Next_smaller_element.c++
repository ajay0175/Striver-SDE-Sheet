#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nse(n, -1);
      stack < int > st;
      for (int i = n - 1; i >= 0; i--) {
        while (st.top() >= nums[i]) {
          st.pop();
        }

        nse[i] = st.top();
        st.push(nums[i]);
      }
      return nse;
    }
};

int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}

/*
    TC => O(N)
    SC => O(N)
*/