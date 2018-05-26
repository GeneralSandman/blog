#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>

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
    bool isPalindrome(string s)
    {
        string tmp;
        for (auto t : s)
        {
            if ('a' <= t && t <= 'z')
                tmp += t;
            else if ('A' <= t && t <= 'Z')
                tmp += tolower(t);
            else if ('0' <= t && t <= '9')
                tmp += t;
        }
        // cout << tmp << endl;
        if (tmp.size() <= 1)
            return true;

        int i = 0, j = tmp.size() - 1;
        while (i < j)
        {
            if (tmp[i] != tmp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    if (s.isPalindrome("aa"))
        cout << "yes\n";
    return 0;
}
