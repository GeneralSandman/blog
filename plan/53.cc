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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        vector<string> level;
        string res;

        getLevelorder(root, level);
        for (auto t : level)
        {
            res += t;
            res += ',';
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> values;
        getValues(data, values);

        TreeNode *root = nullptr;

        if (values.size() <= 1)
            return nullptr;

        queue<TreeNode *> lastLevel;
        root = new TreeNode(atoi(values.front().c_str()));
        lastLevel.push(root);
        values.pop();

        while (!lastLevel.empty())
        {
            int s = lastLevel.size();

            for (int i = 0; i < s; i++)
            {
                TreeNode *node = lastLevel.front();
                lastLevel.pop();

                string ls = values.front();
                values.pop();
                string rs = values.front();
                values.pop();

                if (ls != "#")
                {
                    TreeNode *tmp = new TreeNode(atoi(ls.c_str()));
                    node->left = tmp;
                    lastLevel.push(tmp);
                }

                if (rs != "#")
                {
                    TreeNode *tmp = new TreeNode(atoi(rs.c_str()));
                    node->right = tmp;
                    lastLevel.push(tmp);
                }
            }
        }

        return root;
    }

  private:
    void getLevelorder(TreeNode *root, vector<string> &res)
    {
        if (root == nullptr)
        {
            res.push_back("#");
            return;
        }

        queue<TreeNode *> next;
        next.push(root);

        double count = 0.5;

        while (!next.empty())
        {
            int s = count * 2;
            count = 0;
            TreeNode *tmp = nullptr;
            for (int i = 0; i < s; i++)
            {
                tmp = next.front();
                next.pop();
                if (tmp != nullptr)
                {
                    count++;
                    res.push_back(to_string(tmp->val));
                    next.push(tmp->left);
                    next.push(tmp->right);
                }
                else
                {
                    res.push_back("#");
                }
            }
        }
    }

    void getValues(const string &data, queue<string> &values)
    {
        string tmp;
        for (auto t : data)
        {
            if (t == ',')
            {
                if (!tmp.empty())
                    values.push(tmp);
                tmp = "";
            }
            else
                tmp += t;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void preorder(TreeNode *node)
{
    if (node == nullptr)
        return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    {
        TreeNode root(1);
        TreeNode a(2);
        TreeNode b(3);
        TreeNode c(4);
        TreeNode d(5);
        TreeNode e(6);
        TreeNode f(7);

        // root.left = &a;
        root.right = &b;
        a.left = &c;
        a.right = &d;
        b.left = &e;
        b.right = &f;

        Codec code;
        string seralize = code.serialize(&root);
        cout << seralize << endl;
        TreeNode *res = code.deserialize(seralize);
        preorder(res);
        cout << endl;
    }
    return 0;
}
