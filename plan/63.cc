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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        stack<int> s1, s2;
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int tmp = 0;
        ListNode *pre = nullptr;
        while (!s1.empty() || !s2.empty())
        {
            if (!s1.empty())
            {
                tmp += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                tmp += s2.top();
                s2.pop();
            }

            ListNode *node = new ListNode(tmp % 10);
            tmp /= 10;
            node->next = pre;
            pre = node;
        }

        if (tmp >= 1)
        {
            ListNode *node = new ListNode(tmp);
            node->next = pre;
            return node;
        }
        return pre;
    }
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
    }
};

int main()
{
    return 0;
}
