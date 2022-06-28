#include<bits/stdc++.h>
using namespace std;

class Stack {
  queue <int> q;
  int size;
  public:
    Stack()
    {
        size = -1;
    }

    void Push(int x) {
      size++;
      q.push(x);
      for (int i = 0; i < size; i++) {

        q.push(q.front());
        q.pop();
      }
    }

    int Pop() 
    {
        int n = q.front();
        q.pop();
        size--;
        return n;
    }

    int Top() 
    {
        return q.front();
    }
    
    int Size() 
    {
        return size + 1;
    }

    bool empty() {
        return (size == -1);
    }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}

/*
    Tc => O(N)
    SC => O(N)
*/