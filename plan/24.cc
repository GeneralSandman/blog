class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, char> hashTable;
        map<char, char> hashTable2;

        for (int i = 0; i < s.size(); i++)
        {
            if (hashTable.find(s[i]) == hashTable.end())
            {
                // cout << "not found " << s[i] << endl;
                hashTable[s[i]] = t[i];

                if (hashTable2.find(t[i]) != hashTable2.end() &&
                    hashTable2[t[i]] != s[i])
                    return false;
                hashTable2[t[i]] = s[i];
            }
            else
            {
                // cout << "found " << s[i] << endl;

                if (hashTable[s[i]] != t[i])
                    return false;
            }
        }

        return true;
    }
};
