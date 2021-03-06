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

class NumArray
{
  public:
    NumArray(vector<int> nums)
    {
        vector<int> tmp(nums.size(), 0);
        date.resize(nums.size(), tmp);

        for (int i = 0; i < nums.size(); i++)
            date[i][i] = nums[i];

        int i = 0, j = 1;

        for (int k = 1; k < nums.size(); k++)
        {
            while (i < nums.size() && j < nums.size())
            {
                date[i][j] = date[i][j - 1] + date[i + 1][j] - date[i + 1][j - 1];
                i++;
                j++;
            }

            i = 0;
            j = k + 1;
        }
    }

    void update(int index, int val)
    {
        if (!(0 <= index && index < date.size()))
            return;
        int change = val - date[index][index];
        if (change == 0)
            return;

        for (int i = 0; i <= index; i++)
        {
            for (int j = index; j < date.size(); j++)
            {
                date[i][j] += change;
            }
        }
    }

    int sumRange(int i, int j)
    {
        if (0 <= i && i < date.size() && 0 <= j && j < date.size())
            return date[i][j];
        return INT_MIN;
    }

  private:
    vector<vector<int>> date;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main()
{
    {
        vector<int> nums = {1, 2, 3, 4};
        NumArray a(nums);
        cout << a.sumRange(0, 3) << endl;
        a.update(2, 4);
        cout << a.sumRange(0, 3) << endl;
    }
    return 0;
}