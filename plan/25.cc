class Solution
{
  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int target = 0xfffff;

        vector<string> res;
        if (s.size() <= 10)
            return res;

        map<int, int> hashTable;

        int last = 0;
        int i = 0;
        for (; i < 10; i++)
            last = (target & (last << 2)) | getCode(s[i]);
        hashTable[last] = 1;

        for (i = 10; i < s.size(); i++)
        {
            last = (target & (last << 2)) | getCode(s[i]);
            if (hashTable.find(last) != hashTable.end())
            {
                if (hashTable[last] == 1)
                {
                    string tmp(s.c_str() + i - 9, 10);
                    res.push_back(tmp);
                }
                hashTable[last]++;
            }
            else
                hashTable[last] = 1;
        }

        return res;
    }

  private:
    inline int getCode(char c)
    {
        if (c == 'A')
            return 0;
        else if (c == 'C')
            return 1;
        else if (c == 'G')
            return 2;
        else if (c == 'T')
            return 3;
    }
};
