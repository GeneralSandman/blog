class Solution
{
    vector<bool> nums;

  public:
    int numComponents(ListNode *head, vector<int> &G)
    {
        nums.resize(10001, false);
        for (auto t : G)
            nums[t] = true;

        int index = 0;
        int lastIndex = -2;
        int res = 0;

        while (head != nullptr)
        {
            if (nums[head->val])
            {
                if (index - lastIndex > 1)
                {
                    res++;
                }
                lastIndex = index;
            }
            head = head->next;
            index++;
        }

        return res;
    }
};
