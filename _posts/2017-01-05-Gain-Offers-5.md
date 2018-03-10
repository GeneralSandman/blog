---
layout: post
title: "剑指Offer-5"
description: 用两个栈实现队列
image: 'http://oj8qdsa91.bkt.clouddn.com/badacsony.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 用两个栈实现队列
---


> 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。


```cpp

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp=stack2.top();
        stack2.pop();
        return tmp;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};


```