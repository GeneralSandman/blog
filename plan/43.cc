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

class MyQueue
{
  public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        dateA.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (dateB.empty())
        {
            while (!dateA.empty())
            {
                dateB.push(dateA.top());
                dateA.pop();
            }
        }
        int res = dateB.top();
        dateB.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        if (dateB.empty())
        {
            while (!dateA.empty())
            {
                dateB.push(dateA.top());
                dateA.pop();
            }
        }

        return dateB.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return dateA.empty() && dateB.empty();
    }

  private:
    stack<int> dateA;
    stack<int> dateB;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main()
{
    return 0;
}