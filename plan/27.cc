class Solution
{
  public:
    int titleToNumber(string s)
    {
        int res = 0;

        for (auto t : s)
        {
            res = res * 26 + (t - 'A' + 1);
        }

        return res;
    }
};

