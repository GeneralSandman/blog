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
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> hashTable(26, 0);
        for (auto t : magazine)
            hashTable[t - 'a']++;

        for (auto t : ransomNote)
        {
            if (hashTable[t - 'a'] > 0)
                hashTable[t - 'a']--;
            else
                return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}
