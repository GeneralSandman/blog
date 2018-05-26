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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *pre = nullptr;
        ListNode *forward = head->next;
        while (head != nullptr)
        {
            forward = head->next;

            head->next = pre;
            pre = head;
            head = forward;
        }

        return pre;
    }
};

int main()
{
    return 0;
}
