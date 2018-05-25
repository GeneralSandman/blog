class Solution
{
  public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> hashTable;
        for (auto t : J)
            hashTable.insert(t);
        int res = 0;

        for (auto t : S)
            if (hashTable.find(t) != hashTable.end())
                res++;
        return res;
    }
};
