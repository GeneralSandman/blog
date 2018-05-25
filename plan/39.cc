class LongestDistance
{
  public:
    int getDis(vector<int> A, int n)
    {
        // write code here
        if (n <= 1)
            return 0;

        int res = 0;
        int minNum = A[0];

        for (int i = 1; i < n; i++)
        {
            res = max(A[i] - minNum, res);
            minNum = min(minNum, A[i]);
        }

        return res;
    }
};