class Solution
{
  public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        prune(root);
        return root;
    }

  private:
    void prune(TreeNode *&node)
    {
        if (node == nullptr)
            return;

        prune(node->left);
        prune(node->right);

        if (node->val == 0 &&
            node->left == nullptr &&
            node->right == nullptr)
        {
            delete node;
            node = nullptr;
            return;
        }
    }
};
