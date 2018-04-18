#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <string>
#include <set>

#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <climits>

using namespace std;

class Stack
{
  private:
    stack<int> date;
    stack<int> min;

  public:
    void push(int value)
    {
        date.push(value);

        if (min.empty())
            min.push(value);
        else if (value <= min.top())
            min.push(value);
    }

    int pop()
    {
        int res = date.top();
        date.pop();

        if (!min.empty() && min.top() >= res)
            min.pop();
        return res;
    }

    int getMin()
    {
        return min.top();
    }
};

int main()
{

    Stack a;

    // vector<int> tmp = {4, 3, 2, 1, 2, 3, 4, 0, 5, 0};
    // vector<int> tmp = {1, 1, 0, 0, 2, 3};
    vector<int> tmp = {5, 4, 3, 2, 1};

    for (auto t : tmp)
    {
        a.push(t);
        cout << "after push " << t << " " << a.getMin() << endl;
    }
    cout << "--" << endl;
    for (auto t : tmp)
    {
        int min = a.getMin();
        // a.pop();
        cout << "before pop " << a.pop() << " " << min << endl;
    }

    return 0;
}
