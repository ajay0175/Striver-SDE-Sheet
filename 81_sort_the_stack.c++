#include<bits/stdc++.h>
using namespace std;


void sort_and_insert(stack<int> &s, int n)
{
    if(s.empty() or (!s.empty() and s.top() < n))
    {
        s.push(n);
        return;
    }
    
    int num = s.top();
    s.pop();
    
    // recursive call
    sort_and_insert(s, n);
    s.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
        return;
    
    int n = stack.top();
    stack.pop();
    
    //recursive call
    sortStack(stack);
    sort_and_insert(stack, n);
}


void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << '\n';
}

int main(void)
{
    stack<int> s;

    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
 
    cout << "Stack elements before sorting:\n";
    printStack(s);
 
    sortStack(s);
    cout << "\n";
 
    cout << "Stack elements after sorting:\n";
    printStack(s);
 
    return 0;
}

/*
    TC => O(N*N)
    AUXILARY SPACE => O(N)
*/