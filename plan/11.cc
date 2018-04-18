class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {

        vector<int> result;
        if (matrix.empty())
            return result;
        if (matrix[0].empty())
            return result;
        result.reserve(matrix.size() * matrix[0].size());

        int begin1 = 0, end1 = matrix.size() - 1, begin2 = 0, end2 = matrix[0].size() - 1;

        while (begin1 <= end1 && begin2 <= end2)
        {
            int i = begin1, j = begin2;
            for (; j <= end2; j++)
                result.push_back(matrix[begin1][j]);
            for (i = begin1 + 1; i <= end1; i++)
                result.push_back(matrix[i][end2]);
            if (begin1 != end1)
                for (j = end2 - 1; j >= begin2; j--)
                    result.push_back(matrix[end1][j]);
            if (begin2 != end2)
                for (i = end1 - 1; i > begin1; i--)
                    result.push_back(matrix[i][begin2]);
            begin1++;
            begin2++;
            end1--;
            end2--;
        }

        return result;
    }
};

