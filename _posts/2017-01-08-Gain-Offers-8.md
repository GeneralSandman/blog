---
layout: post
title: "剑指Offer-8"
description: 跳台阶
image: 'http://oj8qdsa91.bkt.clouddn.com/bardenasreales.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 跳台阶
---


> 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。


```cpp

class Solution {
public:
    int jumpFloor(int number) {
        if(number<=3)
            return number;
         
        int tmp=3;
        int f1=2,f2=3;
        int result=0;
         
        while(tmp!=number){
            tmp++;
            result=f1+f2;
            f1=f2;
            f2=result;
        }
         
        return result;
    }
};

```