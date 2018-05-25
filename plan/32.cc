
class Solution
{
  public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int maxIndex = 0;
        int res = 0;
        if (arr.empty())
            return res;

        for (int i = 0; i < arr.size(); i++)
        {
            maxIndex = max(maxIndex, arr[i]);
            if (i == maxIndex)
                res++;
        }

        return res;
    }
};

