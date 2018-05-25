#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

class Solution
{
  public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices)
    {
        int num = prices.size();
        if (num == 0)
            return 0;
        vector<int> before(num, 0);
        vector<int> after(num, 0);

        int minNum = prices[0];

        for (int i = 1; i < num; i++)
        {
            before[i] = max(before[i - 1], prices[i] - minNum);
            minNum = min(minNum, prices[i]);
        }

        int maxNum = prices[num - 1];
        for (int i = num - 2; i >= 0; i--)
        {
            after[i] = max(after[i + 1], maxNum - prices[i]);
            maxNum = max(maxNum, prices[i]);
        }

        // for (auto t : before)
        //     cout << t << " ";
        // cout << endl;

        // for (auto t : after)
        //     cout << t << " ";
        // cout << endl;

        int res = 0;
        for (int i = 0; i < num; i++)
        {
            res = max(before[i] + after[i], res);
        }

        return res;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {3, 8, 5, 1, 7, 8};
    cout << a.calculateMax(nums) << endl;

    return 0;
}
