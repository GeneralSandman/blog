class BSTIterator
{
  private:
    vector<int> nums;
    int index;

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

  public:
    BSTIterator(TreeNode *root)
    {
        inorder(root);
        index = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        if (index < nums.size())
            return true;
        else
            return false;
    }

    /** @return the next smallest number */
    int next()
    {
        return nums[index++];
    }
};



/**********************************/


class BSTIterator
{
  private:
    stack<TreeNode *> nums;
    void initStack(TreeNode *node)
    {
        if (node == nullptr)
            return;
        nums.push(node);
        initStack(node->left);
    }

  public:
    BSTIterator(TreeNode *root)
    {
        initStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return nums.size();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmp = nums.top();
        nums.pop();
        initStack(tmp->right);
        return tmp->val;
    }
};
