#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stdio.h>
#include <cmath>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
    typedef pair<string, double> node;
    map<string, vector<node>> graph;

  public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values,
                                vector<pair<string, string>> queries)
    {

        set<string> all;

        for (int i = 0; i < values.size(); i++)
        {
            node tmp1(equations[i].second, values[i]);
            graph[equations[i].first].push_back(tmp1);

            node tmp2(equations[i].first, 1 / values[i]);
            graph[equations[i].second].push_back(tmp2);

            all.insert(equations[i].second);
            all.insert(equations[i].first);
        }

        vector<double> result(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); i++)
        {
            string a = queries[i].first;
            string b = queries[i].second;

            if (all.find(a) == all.end() || all.find(b) == all.end())
                continue;
            if (a == b)
            {
                result[i] = 1.0;
                continue;
            }
            set<string> visited;
            visited.insert(a);
            // cout << a << " " << b << endl;
            result[i] = get(a, b, visited);
        }
        return result;
    }

  private:
    double get(const string &a, const string &b, set<string> &visited)
    {
        if (a == b)
            return 1.0;
        visited.insert(a);
        // cout << a << " " << b << endl;

        for (int i = 0; i < graph[a].size(); i++)
        {
            string next = graph[a][i].first;
            if (visited.find(next) != visited.end())
                continue;

            if (graph[a][i].second == 0.0)
                return 0.0;
            else
            {
                double av = get(graph[a][i].first, b, visited);
                if (av != -1.0)
                    return graph[a][i].second * av;
                // return graph[a][i].second * av;
            }
        }

        return -1.0;
    }
};

int main()
{
    {
        Solution a;
        vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
        vector<double> values = {2.0, 3.0};
        vector<pair<string, string>> queries = {{"a", "c"}, {"b", "c"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
        // vector<pair<string, string>> queries = {{"b", "c"}};

        vector<double> res = a.calcEquation(equations, values, queries);

        for (auto t : res)
            cout << t << " ";
        cout << endl;
    }

    {
        Solution a;
        vector<pair<string, string>> equations = {{"a", "e"}, {"b", "e"}};
        vector<double> values = {4.0, 3.0};
        vector<pair<string, string>> queries = {{"a", "e"}, {"a", "b"}, {"e", "e"}, {"x", "x"}};
        vector<double> res = a.calcEquation(equations, values, queries);

        for (auto t : res)
            cout << t << " ";
        cout << endl;
    }

    return 0;
}

