#include<bits/stdc++.h>

using namespace std;
int maxProfit(int arr[]) {
  int maxProfit = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < 6; i++) {
    minPrice = min(minPrice, arr[i]);
    maxProfit = max(maxProfit, arr[i] - minPrice);
  }
  return maxProfit;
}
int main() {
  int arr[] = {7,1,5,3,6,4};
  int maxPro = maxProfit(arr);
  cout << "Max profit is: " << maxPro << endl;
}

/*
  TC => O(N)
  SC => O(1)
*/