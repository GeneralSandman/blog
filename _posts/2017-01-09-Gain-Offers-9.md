---
layout: post
title: "剑指Offer-9"
description: 变态跳台阶
image: 'http://oj8qdsa91.bkt.clouddn.com/bassharborlight.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 变态跳台阶
---


> 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。


```cpp

class Solution {
public:
    int jumpFloorII(int number) {
        int result=2;
        if(number==1)
               return 1;
        for(int i=0;i<number-2;i++)
            result*=2;
        return result;
    }
};

```