#include<bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int Front;
    int *arr;
    int size;
    int rear;
    int maxsize;

public:
    Queue() // Default size queue
    {
        Front = -1;
        size = 0;
        rear = -1;
        arr = new int[16];
    }

    Queue(int maxsize) // Customize size queue
    {
        (*this).maxsize = maxsize;
        arr = new int[maxsize];
        Front = -1;
        rear = -1;
        size = 0;
    }
   
   void push(int val)
   {
        if(size == maxsize)
        {
            cout << "Queue is full" << '\n';
            return;
        }

        if(rear == -1)
        {
            Front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % maxsize;
        }

        arr[rear] = val;
        cout << "The ELememt push is " << val << '\n';
        size++;
   }

   int pop()
   {
        if (Front == -1) {
            cout << "Queue Empty\nExiting..." << endl;
        }

        int popped = arr[Front];

        if (size == 1)
        {
            Front = -1;
            rear = -1;
        } 
        else
            Front = (Front + 1) % size;
        size--;
        return popped;
   }

    int Size()
    {
        return size;
    }

    int Top()
    {
        if (Front == -1) 
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[Front];
    }

};


int main()
{

  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.Top() << endl;
  cout << "The size of the queue before deletion " << q.Size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.Top() << endl;
  cout << "The size of the queue after deleting an element " << q.Size() << endl;

    return 0;
}

/*
    Tc => O(1) for each function the time is o(1)
    SC => O(N)
*/