class Trie
{
  public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node;
        root->isWord = false;
        for (int i = 0; i < 26; i++)
            root->next[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
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
                for (int i = 0; i < 26; i++)
                    n->next[i] = nullptr;
            }
            tmp = n;
        }
        tmp->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = tolower(word[i]);

        Node *tmp = root;
        for (auto t : word)
        {
            if (tmp->next[t - 'a'] == nullptr)
                return false;
            tmp = tmp->next[t - 'a'];
        }
        if (tmp->isWord == true)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        for (int i = 0; i < prefix.size(); i++)
            prefix[i] = tolower(prefix[i]);

        Node *tmp = root;
        for (auto t : prefix)
        {
            if (tmp->next[t - 'a'] == nullptr)
                return false;
            tmp = tmp->next[t - 'a'];
        }
        return true;
    }

    ~Trie()
    {
        deleteTree(root);
    }

  private:
    typedef struct Node
    {
        bool isWord;
        Node *next[26];
    } Node;

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

        // cout << "delete node:" << endl;
        delete node;
    }
};