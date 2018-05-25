class Trie
{
    typedef struct Node
    {
        bool isWord;
        Node *next[26];
    } Node;

  public:
    Trie()
    {
        root = new Node;
        root->isWord = false;
        for (int i = 0; i < 26; i++)
            root->next[i] = nullptr;
    }

    void insert(string word)
    {
        Node *tmp = root;

        for (int i = word.size() - 1; i >= 0; i--)
        {
            Node *&n = tmp->next[word[i] - 'a'];
            if (n == nullptr)
            {
                n = new Node;
                n->isWord = false;
                for (int i = 0; i < 26; i++)
                    n->next[i] = nullptr;
            }
            tmp = n;
        }
        tmp->isWord = true;
    }

    void findAllString(int &length, int &nums)
    {
        for (int i = 0; i < 26; i++)
        {
            int tmpLength = 0;
            find(root->next[i], 1, tmpLength, nums);
            length += tmpLength;
        }
    }

    void find(Node *node, int cur, int &length, int &nums)
    {
        if (node == nullptr)
            return;

        if (node->isWord)
        {
            bool noSon = true;
            for (int i = 0; i < 26; i++)
            {
                if (nullptr != node->next[i])
                {
                    noSon = false;
                    break;
                }
            }
            if (noSon)
            {
                length = cur;
                nums++;
                return;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            int tmpLength = 0;
            find(node->next[i], cur + 1, tmpLength, nums);
            if (tmpLength)
                length += tmpLength;
        }
    }

    ~Trie()
    {
        deleteTree(root);
    }

  private:
    Node *root;

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < 26; i++)
        {
            deleteTree(node->next[i]);
            node->next[i] = nullptr;
        }
        delete node;
    }
};

class Solution
{
  public:
    int minimumLengthEncoding(vector<string> &words)
    {
        Trie tree;
        for (auto t : words)
            tree.insert(t);

        int length = 0;
        int nums = 0;
        tree.findAllString(length, nums);
        return length + nums;
    }
};
