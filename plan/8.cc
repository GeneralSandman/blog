class Solution
{
  public:
    int monotoneIncreasingDigits(int N)
    {
        string tmp = to_string(N);

        for (int i = tmp.size() - 1; i > 0; i--)
        {
            if (tmp[i] < tmp[i - 1])
            {
                tmp[i] = '9';
                if (tmp[i - 1] == '0')
                    tmp[i - 1] = '9';
                else
                {
                    tmp[i - 1]--;
                }
            }
        }
        // cout << tmp << endl;

        for (int i = 0; i < tmp.size() - 1; i++)
        {
            if (tmp[i + 1] < tmp[i])
                tmp[i + 1] = '9';
        }

        int result = atoi(tmp.c_str());

        return result;
    }
};