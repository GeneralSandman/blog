class Solution
{
  public:
    string convertToTitle(int n)
    {
        string res;
        while (n)
        {
            n -= 1;
            res = char('A' + n % 26) + res;
            n /= 26;
        }
        return res;
    }
};
