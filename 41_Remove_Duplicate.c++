#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[]) {
  int i = 0;
  for (int j = 1; j < 7; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int k = removeDuplicates(arr);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

/*
    TC => O(N)
    SC => O(1)
*/