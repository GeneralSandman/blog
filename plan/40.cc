class Flip
{
  public:
    vector<vector<int>> flipChess(vector<vector<int>> A, vector<vector<int>> f)
    {
        // write code here
        int col = A.size();
        if (col == 0)
            return A;
        int row = A[0].size();
        if (row == 0)
            return A;

        for (auto t : f)
        {
            int i = t[0], j = t[1];

            if (i > 0)
                A[i - 1][j] = !A[i - 1][j];
            if (i < col - 1)
                A[i + 1][j] = !A[i + 1][j];
            if (j > 0)
                A[i][j - 1] = !A[i][j - 1];
            if (j < row - 1)
                A[i][j + 1] = !A[i][j + 1];
        }

        return A;
    }
};