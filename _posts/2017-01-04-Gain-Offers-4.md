---
layout: post
title: "剑指Offer-4"
description: 重建二叉树
image: 'http://oj8qdsa91.bkt.clouddn.com/aragolighthousesunsetii.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 重建二叉树
---


> 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。


```cpp

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() != inorder.size() ||
            preorder.size() == 0)
            return nullptr;
        TreeNode *root = createTree(preorder, 0, preorder.size(),
                                    inorder, 0, inorder.size());
 
        return root;
    }
 
  private:
    TreeNode *createTree(vector<int> &preorder, int b1, int e1,
                         vector<int> &inorder, int b2, int e2)
    {
        if (b1 == e1)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[b1]);
 
        int i = b2;
        for (; i < e2; i++)
        {
            if (inorder[i] == preorder[b1])
                break;
        }
        int left_length = i - b2;
        int right_length = e2 - i;
        node->left = createTree(preorder, b1 + 1, b1 + 1 + left_length,
                                inorder, b2, b2+left_length);
        node->right = createTree(preorder, b1 + 1 + left_length, e1,
                                 inorder, i + 1, i+1+right_length);
        return node;
    }
};

```