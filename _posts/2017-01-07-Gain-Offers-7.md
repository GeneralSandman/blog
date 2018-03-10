---
layout: post
title: "剑指Offer-7"
description: 斐波那契数列
image: 'http://oj8qdsa91.bkt.clouddn.com/baldeagle.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 斐波那契数列
---


> 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。


```cpp

class Solution {
public:
    int Fibonacci(int n) {
        if(n<=1)
            return n;
         
        int f1=0,f2=1;
        int tmp=1;
        int result=0;
        while(tmp!=n){
            tmp++;
            result=f1+f2;
            f1=f2;
            f2=result;
        }
         
        return result;
    }
};

```