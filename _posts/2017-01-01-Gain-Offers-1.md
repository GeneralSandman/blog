---
layout: post
title: "剑指Offer-1"
description: 二维数组中的查找
image: 'http://oj8qdsa91.bkt.clouddn.com/afishermanandavolcano.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 二维数组中的查找
---


> 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


```cpp

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        if(array[0].empty())
            return false;
        int i=0,j=array[0].size()-1;
         
        while(i<array.size()&&j>=0){
            if(target>array[i][j])
                i++;
            else if(target<array[i][j])
                j--;
            else
                return true;
        }
         
        return false;
    }
};

```