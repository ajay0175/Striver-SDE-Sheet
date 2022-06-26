#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int l, int r)
{
	int f = arr[r] ;
	int i = l;

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= f) {
			swap(arr[i], arr[j]) ;
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}


int kth_Smallest_Element(vector<int>&arr, int l, int r, int k)
{
	if (k <= r - l + 1 && k > 0) {

		int ind = partition(arr, l, r);


		if (ind - l == k - 1) {
			return arr[ind];
		}
		if (ind - l > k - 1) {
			return kth_Smallest_Element(arr, l, ind - 1, k);
		}


		return kth_Smallest_Element(arr, ind + 1, r, k - ind + l - 1);
	}
	return INT_MAX;
}

int main()
{

	vector<int>arr ;
	arr.push_back(12) ;
	arr.push_back(3)  ;
	arr.push_back(5) ;
	arr.push_back(7)  ;
	arr.push_back(4) ;
	arr.push_back(19)  ;
	arr.push_back(26) ;

	int n = arr.size(), k = 1;
	cout << "Kth smallest element is " << kth_Smallest_Element(arr, 0, n - 1, k);
	return 0;
}

/*
    TC => O(N)
    SC => O(1)
*/