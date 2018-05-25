class FirstRepeat
{
  public:
    char findFirstRepeat(string A, int n)
    {
        vector<bool> hashTable(256, false);

        int i = 0;
        for (; i < n; i++)
        {
            if (hashTable[int(A[i])])
                break;
            else
                hashTable[int(A[i])] = true;
        }

        return A[i];
    }
};