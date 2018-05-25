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
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> res(S.size(), S.size());

        if (S.empty())
            return res;

        int last = 0 - S.size();
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                res[i] = 0;
                last = i;
            }
            else
            {
                res[i] = min(res[i], i - last);
            }
        }

        for (auto t : res)
            cout << t << " ";
        cout << endl;

        last = 2 * S.size();
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == C)
            {
                res[i] = 0;
                last = i;
            }
            else
            {
                res[i] = min(res[i], last - i);
            }
        }

        for (auto t : res)
            cout << t << " ";
        cout << endl;

        return res;
    }
};

int main()
{
    Solution a;
    vector<int> res = a.shortestToChar("loveleetcode", 'e');
    for (auto t : res)
        cout << t << " ";
    cout << endl;

    return 0;
}

