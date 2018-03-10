---
layout: post
title: "剑指Offer-3"
description: 从尾到头打印链表
image: 'http://oj8qdsa91.bkt.clouddn.com/anemonepoolreflections.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 从尾到头打印链表
---


> 输入一个链表，从尾到头打印链表每个节点的值。


```cpp

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if(nullptr==head)
            return result;
        push(head,result);
        return result;
    }
private:
    void push(ListNode *node,vector<int>&result){
        if(nullptr==node)
            return;
        push(node->next,result);
        result.push_back(node->val);
    }
};

```