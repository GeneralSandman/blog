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

class Solution
{
  public:
    bool isValidSerialization(string preorder)
    {
        stack<string> tmp;
        vector<string> nodes;
        getNodes(preorder, nodes);

        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i] == "#")
            {
                while (!tmp.empty() && tmp.top() == "#")
                {
                    tmp.pop();
                    if (tmp.empty())
                        return false;
                    if (tmp.top() == "#")
                        return false;
                    tmp.pop();
                }
            }
            tmp.push(nodes[i]);
        }

        return tmp.size() == 1 && tmp.top() == "#";
    }

  private:
    void getNodes(const string &preorder, vector<string> &res)
    {
        string tmp;

        for (int i = 0; i < preorder.size(); i++)
        {
            if (preorder[i] == ',')
            {
                if (!tmp.empty())
                    res.push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += preorder[i];
            }
        }
        if (!tmp.empty())
            res.push_back(tmp);
    }
};

int main()
{
    {
        Solution s;
        string str = "9,3,4,#,#,1,#,#,2,#,6,#";

        if (s.isValidSerialization(str))
            cout << "yes" << endl;
    }
    return 0;
}