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
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        vector<int> result;
        if (n <= 2)
        {
            for (int i = 0; i < n; i++)
                result.push_back(i);
            return result;
        }
        vector<set<int>> graph(n);

        for (auto t : edges)
        {
            graph[t.first].insert(t.second);
            graph[t.second].insert(t.first);
        }

        queue<int> next;
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].size() == 1)
            {
                next.push(i);
            }
        }

        while (1)
        {
            int s = next.size();

            for (int i = 0; i < s; i++)
            {
                int tmp = next.front();
                next.pop();

                int other = *(graph[tmp].begin());
                graph[tmp].clear();
                graph[other].erase(tmp);

                if (graph[other].size() == 1)
                    next.push(other);
            }

            bool contin = false;
            for (int i = 0; i < graph.size(); i++)
            {
                if (graph[i].size() > 1)
                {
                    contin = true;
                    break;
                }
            }

            if (contin == false)
                break;
        }

        while (!next.empty())
        {
            result.push_back(next.front());
            next.pop();
        }

        return result;
    }
};

int main()
{
    {
        Solution s;
        vector<pair<int, int>> edges;
        vector<int> result = s.findMinHeightTrees(1, edges);

        for (auto t : result)
            cout << t << " ";
        cout << endl;
    }
    {
        Solution s;
        vector<pair<int, int>> edges = {{0, 1}};
        vector<int> result = s.findMinHeightTrees(2, edges);

        for (auto t : result)
            cout << t << " ";
        cout << endl;
    }
    {
        Solution s;
        vector<pair<int, int>> edges = {{1, 0}, {1, 2}, {1, 3}};
        vector<int> result = s.findMinHeightTrees(4, edges);

        for (auto t : result)
            cout << t << " ";
        cout << endl;
    }

    {
        Solution s;
        vector<pair<int, int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
        vector<int> result = s.findMinHeightTrees(6, edges);

        for (auto t : result)
            cout << t << " ";
        cout << endl;
    }
    return 0;
}
