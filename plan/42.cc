#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>

#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class MyStack
{
  public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int s = date.size();
        date.push(x);
        for (int i = 0; i < s; i++)
        {
            date.push(date.front());
            date.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int res = date.front();
        date.pop();
        return res;
    }

    /** Get the top element. */
    int top()
    {
        return date.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return date.empty();
    }

  private:
    queue<int> date;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main()
{
    return 0;
}