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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        typedef pair<int, int> key;
        deque<key> tmp;
        vector<int> res;

        for (int i = 0; i < k - 1; i++)
        {
            if (tmp.empty())
                tmp.push_back(key({nums[i], i}));
            else
            {
                while (!tmp.empty() && tmp.front().first <= nums[i])
                    tmp.pop_front();

                while (!tmp.empty() && tmp.back().first <= nums[i])
                    tmp.pop_back();

                tmp.push_back(key({nums[i], i}));
            }
        }
        int lastIndex = 0;
        for (int i = k - 1; i < nums.size(); i++)
        {
            if (tmp.empty())
                tmp.push_back(key({nums[i], i}));
            else
            {
                if (i - tmp.front().second == k)
                    tmp.pop_front();
                while (!tmp.empty() && tmp.front().first <= nums[i])
                    tmp.pop_front();
                while (!tmp.empty() && tmp.back().first <= nums[i])
                    tmp.pop_back();
                tmp.push_back(key({nums[i], i}));
            }
            res.push_back(tmp.front().first);
        }

        return res;
    }
};

int main()
{
    {
        Solution s;
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        vector<int> res = s.maxSlidingWindow(nums, 3);
        for (auto t : res)
            cout << t << " ";
        cout << endl;
    }

    {
        Solution s;
        vector<int> nums = {1, 2, 3, 1, 1, 1, 2, 1};
        vector<int> res = s.maxSlidingWindow(nums, 3);
        for (auto t : res)
            cout << t << " ";
        cout << endl;
    }

    {
        Solution s;
        vector<int> nums = {1, 3, 1, 2, 0, 5};
        vector<int> res = s.maxSlidingWindow(nums, 3);
        for (auto t : res)
            cout << t << " ";
        cout << endl;
    }
    return 0;
}