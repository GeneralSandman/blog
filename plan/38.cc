class Coder
{
  private:
    int findCurNums(string src, const string &pattern)
    {
        for (int i = 0; i < src.size(); i++)
            src[i] = tolower(src[i]);

        int findPos = 0;
        int nums = 0;
        while ((findPos = src.find(pattern, findPos)) != string::npos)
        {
            findPos += 5;
            nums++;
        }
        return nums;
    }

    typedef pair<int, int> key;

    static bool comp(const key &a, const key &b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second < b.second;
        }
    }

  public:
    vector<string> findCoder(vector<string> A, int n)
    {
        string pattern = "coder";

        vector<key> tmp;
        for (int i = 0; i < A.size(); i++)
        {
            int nums = findCurNums(A[i], pattern);
            cout << nums << endl;
            if (nums)
            {
                key tmpkey(nums, i);
                tmp.push_back(tmpkey);
            }
        }

        sort(tmp.begin(), tmp.end(), comp);

        vector<string> res(tmp.size());
        for (int i = 0; i < tmp.size(); i++)
        {
            res[i] = A[tmp[i].second];
        }
        return res;
    }
};