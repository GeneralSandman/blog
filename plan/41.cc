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
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int cols = matrix[0].size();
        if (cols == 0)
            return 0;

        vector<int> tmp(cols, 0);
        vector<vector<int>> down(rows, tmp), right(rows, tmp), result(rows, tmp);

        int res = 0;
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '0')
                    down[i][j] = right[i][j] = 0;
                else
                {
                    if (i == rows - 1)
                        down[i][j] = 1;
                    else
                        down[i][j] = down[i + 1][j] + 1;
                    if (j == cols - 1)
                        right[i][j] = 1;
                    else
                        right[i][j] = right[i][j + 1] + 1;
                }

                if (matrix[i][j] == '1')
                {
                    if (i == rows - 1 || j == cols - 1)
                        result[i][j] = 1;
                    else
                        result[i][j] = min(min(down[i][j], right[i][j]), result[i + 1][j + 1] + 1);
                    res = max(res, result[i][j]);
                }
            }
        }

        // cout << "down\n";
        // for (auto v : down)
        // {
        //     for (auto t : v)
        //     {
        //         cout << t << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "right\n";
        // for (auto v : right)
        // {
        //     for (auto t : v)
        //     {
        //         cout << t << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "matrix\n";
        // for (auto v : result)
        // {
        //     for (auto t : v)
        //     {
        //         cout << t << " ";
        //     }
        //     cout << endl;
        // }

        return res * res;
    }
};

int main()
{
    {
        Solution s;
        vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}};
        cout << s.maximalSquare(matrix) << endl;
    }

    {
        Solution s;
        vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '1', '1', '1'}};
        cout << s.maximalSquare(matrix) << endl;
    }
    return 0;
}