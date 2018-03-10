---
layout: post
title: "剑指Offer-6"
description: 旋转数组的最小数字
image: 'http://oj8qdsa91.bkt.clouddn.com/badlandsintheafternoonsun.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 旋转数组的最小数字
---


> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。


```cpp

class Solution {
public:
    int minNumberInRotateArray(vector<int> array) {
        if(array.empty())
            return -1;
        if(array.size()==1)
            return array[0];
        int i=1;
        while(i<array.size()){
            if(array[i]<array[i-1])
                break;
            i++;
        }
         
        return array[i];
    }
};

```