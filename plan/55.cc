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

class RandomizedSet
{
  public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (hashTable.find(val) != hashTable.end())
            return false;

        hashTable[val] = date.size();
        date.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (hashTable.find(val) == hashTable.end())
            return false;

        int index = hashTable[val];
        date[index] = date.back();
        hashTable[date[index]] = index;

        date.pop_back();
        hashTable.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return date[rand() % date.size()];
    }

  private:
    vector<int> date;
    unordered_map<int, int> hashTable;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    return 0;
}
