#include <bits/stdc++.h> 
using namespace std;


class Kthlargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kthLargest;
public:
    Kthlargest(int k, vector<int> &arr) {
        kthLargest = k;

        for(auto &e : arr) {
            minHeap.emplace(e);

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    void add(int num) {
        minHeap.emplace(num);
        if(minHeap.size() > kthLargest){
            minHeap.pop();
        }
    }

    int getKthLargest() {
       return minHeap.top();
    }
};

int main()
{
    int k = 3;
    vector<int> arr = {4, 5, 8, 2};

    Kthlargest obj(k, arr);
    cout << obj.getKthLargest() << " ";

    obj.add(3);
    cout << obj.getKthLargest() << " ";
    
    obj.add(5);
    cout << obj.getKthLargest() << " ";

    obj.add(10);
    cout << obj.getKthLargest() << " ";

    obj.add(9);
    cout << obj.getKthLargest() << " ";

    obj.add(4);
    cout << obj.getKthLargest() << " ";

    return 0;
}

/*
    TC => Construction: O(N * logK)  Adding: O(logK)
    sc =>O(K) (can be reduced to O(1) by reusing memory of the existing array)
*/
