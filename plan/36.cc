class BinarySearch
{
  public:
    int getPos(vector<int> A, int n, int val)
    {
        int begin = 0;
        int end = A.size() - 1;
        int middle = 0;

        while (begin <= end)
        {
            middle = begin + (end - begin) / 2;
            if (A[middle] < val)
            {
                begin = middle + 1;
            }
            else if (A[middle] > val)
            {
                end = middle - 1;
            }
            else
            {
                if (middle == 0 || A[middle - 1] != val)
                {
                    return middle;
                }
                else
                {
                    end = middle - 1;
                }
            }
        }

        return -1;
    }
};