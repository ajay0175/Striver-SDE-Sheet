#include <bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int K, int N)
{
    unordered_map<int, int> hashMap;

    int distinctElement = 0;

    // Traverse the first window and store count
    // of every element in hash map
    for (int i = 0; i < K; i++) {
        if (hashMap[arr[i]] == 0) {
            distinctElement++;
        }
        
        hashMap[arr[i]] += 1;
    }

    // Print count of first window
    cout << distinctElement << " ";

    // Traverse through the remaining array
    for (int i = K; i < N; i++) {

        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if (hashMap[arr[i - K]] == 1) {
            distinctElement--;
        }
        // reduce count of the removed element
        hashMap[arr[i - K]] -= 1;

        // Add new element of current window
        // If this element appears first time,
        // increment distinct element count

        if (hashMap[arr[i]] == 0) {
            distinctElement++;
        }
        hashMap[arr[i]] += 1;

        cout << distinctElement << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int n = 7, k = 4;

    countDistinct(arr, k, n);

    return 0;
}
/*
    TC => O(N)
    SC => O(N)
*/
