// Same has problem no. 72
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0) {
            maxHeap.push(num);
        }
        else if(size & 1) {
            int top = maxHeap.top();
            if(top < num) {
                minHeap.push(num);
            }
            else {
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(top);
            }
        }
        else {
            int top = minHeap.top();
            if(top > num) {
                maxHeap.push(num);
            }
            else {
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(top);
            }   
        }

        size++;
    }
    
    int findMedian() {
       if(maxHeap.size() == minHeap.size()) {
            return floor((maxHeap.top() + minHeap.top()) / 2);
       }
       else {
            return maxHeap.top();
       }
    }
};

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    MedianFinder obj;
    
    for(auto &e : arr) {
        obj.addNum(e);
        int median = obj.findMedian();
        ans.emplace_back(median);
    }

    return ans;
}

int main() {

    vector<int> arr = {5, 3, 8};
    int n = 3;

    vector<int> ans = findMedian(arr, n);

    for(auto &e : ans) {
        cout << e << " ";
    }
}

/*
    TC => O(NlOGN)
    SC => O(N)
*/