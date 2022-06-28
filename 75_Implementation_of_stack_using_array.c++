#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int size;

public:
    Stack()
    {
        top = -1;
        size = 10001;
        arr = new int[size];
    }
   
   void push(int val)
   {
    top++;
    arr[top] = val;
   }

   int pop()
   {
    if(top == -1)
    {
        cout << "Stack is empty" << '\n';
        return -1;
    }
    
    int x = arr[top];
    top--;
    return x;
   }

    int Size()
    {
        return top + 1;
    }

    int Top()
    {
        return arr[top];
    }

};


int main()
{

    Stack s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(9);
    cout << "Size of stack is " << s.Size() << '\n';
    cout << "The deleted element is " <<  s.pop()  << endl;
    cout << "size of stack is " << s.Size() << '\n';
    cout << "Top Element of stack is " << s.Top() << '\n'; 

    return 0;
}

/*
    Tc => O(N)
    SC => O(N)
*/