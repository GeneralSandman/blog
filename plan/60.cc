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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode *front = head;
        ListNode *back = head;
        while (front != nullptr && back != nullptr && back->next != nullptr)
        {
            front = front->next;
            back = back->next->next;
        }
        ListNode *tmp = head;
        int count = 0;
        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }

        tmp = head;
        stack<int> before;
        while (tmp != front)
        {
            before.push(tmp->val);
            tmp = tmp->next;
        }

        if (count % 2 == 1)
            before.push(front->val);

        while (front != nullptr)
        {
            if (front->val != before.top())
                return false;
            before.pop();
            front = front->next;
        }

        return before.empty();
    }
};

int main()
{
    {
        Solution s;
        s.isPalindrome(nullptr);
    }
    cout << "------" << endl;
    {
        Solution s;
        ListNode a(1);
        if (s.isPalindrome(&a))
            cout << "yes\n";
    }
    cout << "------" << endl;
    {
        Solution s;
        ListNode a(1);
        ListNode b(1);
        a.next = &b;
        if (s.isPalindrome(&a))
            cout << "yes\n";
    }
    cout << "------" << endl;
    {
        Solution s;
        ListNode a(1);
        ListNode b(2);
        ListNode c(1);
        a.next = &b;
        b.next = &c;
        if (s.isPalindrome(&a))
            cout << "yes\n";
    }
    cout << "------" << endl;
    {
        Solution s;
        ListNode a(1);
        ListNode b(2);
        ListNode c(2);
        ListNode d(1);
        a.next = &b;
        b.next = &c;
        c.next = &d;
        if (s.isPalindrome(&a))
            cout << "yes\n";
    }
    cout << "------" << endl;
    {
        Solution s;
        ListNode a(1);
        ListNode b(2);
        ListNode c(3);
        ListNode d(2);
        ListNode e(1);
        a.next = &b;
        b.next = &c;
        c.next = &d;
        d.next = &e;
        if (s.isPalindrome(&a))
            cout << "yes\n";
    }
    cout << "------" << endl;
    {
        Solution s;
        ListNode a(1);
        ListNode b(2);
        ListNode c(3);
        ListNode d(3);
        ListNode e(2);
        ListNode f(1);
        a.next = &b;
        b.next = &c;
        c.next = &d;
        d.next = &e;
        e.next = &f;
        if (s.isPalindrome(&a))
            cout << "yes\n";
    }
    return 0;
}
