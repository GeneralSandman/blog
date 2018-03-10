---
layout: post
title: "剑指Offer-2"
description: 替换空格
image: 'http://oj8qdsa91.bkt.clouddn.com/alittledream.jpg'
category: 'blog'
tags:
- Gain-Offers
- Algorithm
twitter_text: 
introduction: 替换空格
---


> 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。


```cpp

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(0==length)
             return ;
        int count=0;
        for(int i=0;i<length;i++)
            if(str[i]==' ')
                count++;
        int i=length;
        int j=length+2*count;
        str[j]='\0';
        i--;
        j--;
         
        while(count){
            if(str[i]!=' '){
                str[j]=str[i];
                i--;
                j--;
            }
            else{
                count--;
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
                i--;
            }
        }
         
    }
};

```