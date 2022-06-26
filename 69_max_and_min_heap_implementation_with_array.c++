#include<bits/stdc++.h>
using namespace std;

class heap
{
  public:
  int arr[100];
  int size = 0;

  heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val) // TC => O(LOGN)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while(index > 1)
    {
      int parent = index / 2;

      if(arr[parent] < arr[index]) // Just change the from '<' to this '>' and it become min heap
       {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        return;
      }
    }
  } 

  void deletefromHeap()
  {
    if(size == 0)
    {
      cout << "Nothing to Delete" << '\n';
      return;
    }

    //1st condition => put last element to into first index
    arr[1] = arr[size];

    //2nd condition => remove last element by decreasing the size
    size--;

    // 3rd condition => take root to its correct position
    int i = 1;
    while(i < size)
    {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if(leftIndex < size and arr[i] < arr[leftIndex])
      {
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      }
      
      if(rightIndex < size and arr[i] < arr[rightIndex])
      {
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      }
      else
      {
        return;
      }
    }
  }

  void print()
  {
    for(int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }cout << '\n';
  }  
};

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if(left < n and arr[largest] < arr[left])
  {
    largest = left;
  }
  
  if(right < n and arr[largest] < arr[right])
  {
    largest = right;
  }

  if(largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}


int main()
{
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.print();

  h.deletefromHeap();
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;
  for(int i = n / 2; i > 0; i--)
  {
    heapify(arr, n, i);
  }

  cout << "print the array" << '\n';
  for(int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << '\n';


  return 0;
}