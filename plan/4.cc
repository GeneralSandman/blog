class MapSum
{
  public:
    /** Initialize your data structure here. */
    MapSum()
    {
        root = new Node;
        root->isWord = false;
        root->num = 0;
        for (int i = 0; i < 26; i++)
            root->next[i] = nullptr;
    }

    void insert(string word, int val)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = tolower(word[i]);
        Node *tmp = root;

        for (auto t : word)
        {
            Node *&n = tmp->next[t - 'a'];
            if (n == nullptr)
            {
                n = new Node;
                n->isWord = false;
                n->num=0;
                for (int i = 0; i < 26; i++)
                    n->next[i] = nullptr;
            }
            tmp = n;
        }
        tmp->isWord = true;
        tmp->num = val;
    }

    int sum(string prefix)
    {
        int res = 0;

        Node *tmp = root;

        for (auto t : prefix)
        {
            tmp = tmp->next[t - 'a'];
            if (tmp == nullptr)
                break;
        }

        if (tmp == nullptr)
            return 0;
        res = getNum(tmp);
        return res;
    }

    ~MapSum()
    {
        deleteTree(root);
    }

  private:
    typedef struct Node
    {
        bool isWord;
        int num;
        Node *next[26];
    } Node;

    Node *root;

    int getNum(Node *node)
    {
        if (node == nullptr)
            return 0;
        int res = node->num;
        for (int i = 0; i < 26; i++)
            if (node->next[i] != nullptr)
                res += getNum(node->next[i]);
        return res;
    }

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < 26; i++)
        {
            deleteTree(node->next[i]);
            node->next[i] = nullptr;
        }

        // cout << "delete node:" << endl;
        delete node;
    }
};