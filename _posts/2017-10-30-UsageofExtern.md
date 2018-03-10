---
layout: post
title: "Extern 用法"
description: 面试中经常被问道extern的用法，这个问题也困扰我很久了，终于有时间好好研究这个问题了，发现这个问题真的有点复杂，还涉及到编译原理的问题。extern与static有什么不同呢？他们的作用域有什么不同呢？希望这篇文章可以解释清楚这些问题。
image: 'http://oj8qdsa91.bkt.clouddn.com/1%E5%86%B0%E4%B8%8E%E7%81%AB%E4%B9%8B%E6%AD%8C--%E8%B0%B7%E5%9C%B0%E7%BA%B9%E7%AB%A0.jpg'
category: 'blog'
tags:
- C++
-
-
twitter_text: 
introduction: 
---


## 1.extern 变量简单用法

当extern修饰变量或者函数时，一般用法如下

例

- ``` header1.h ``` 在头文件中声明extern变量

{% highlight html %}
#ifndef HEADER1_H
#define HEADER1_H

extern int global_num;

#endif // !HEADER1_H
{% endhighlight %}


- ``` header1.cc ``` 在源码文件中定义变量

{% highlight html %}
#include "header1.h"

int global_num = 10;
{% endhighlight %}


- ``` test1.cc ``` 在main文件中使用extern变量

{% highlight html %}
#include <iostream>
#include "header1.h"
using namespace std;
int main()
{
    extern int global_num;
    cout << global_num << endl;
    return 0;
}
{% endhighlight %}


- 编译运行，结果输出为10

{% highlight html %}
g++ -std=c++11 test1.cc header1.cc
./a.out 
{% endhighlight %}


## 2.extern 函数简单用法


在复杂项目中，extern一般用来取代``` #include"xx.h" ```


- ``` header2.h ``` 声明一个extern函数，有没有extern都一样，test2.cc都可以不用包含头文件而使用extern使用该函数。

{% highlight html %}
#ifndef HEADER2_H
#define HEADER2_H

extern void global_fun();

#endif // !HEADER1_H
{% endhighlight %}


- ``` header2.cc ``` 定义global_fun()函数

{% highlight html %}

#include "header2.h"
#include <iostream>

void global_fun()
{
    std::cout << "invoke global_fun()\n";
}
{% endhighlight %}


- ``` test2.cc ``` 这样在使用global_fun()函数的时候就不用包含头文件了，只需要extern一下就可以了

{% highlight html %}
#include <iostream>
extern void global_fun();
int main()
{
    global_fun();
    return 0;
}
{% endhighlight %}


- 编译运行，结果如下：

{% highlight html %}
g++ -std=c++11 test2.cc header2.cc
./a.out 
invoke global_fun()
{% endhighlight %}



## 3.extern 修饰变量和函数共同使用

- ``` header3.h ``` 

{% highlight html %}
#ifndef HEADER3_H
#define HEADER3_H
#include <string>

extern std::string global_str;
void printGlobalStr();

#endif // !HEADER3_H

{% endhighlight %}

- ``` header3.cc ``` 定义变量和函数

{% highlight html %}
#include "header3.h"
#include <string>
#include <iostream>

std::string global_str = "xxxx";
void printGlobalStr()
{
    std::cout << global_str << std::endl;
}
{% endhighlight %}

- ``` test3.cc ``` 不用include,只需要extern外部函数

{% highlight html %}
#include <iostream>
extern void printGlobalStr();
int main()
{
    printGlobalStr();
}
{% endhighlight %}

- 编译运行，结果如下：

{% highlight html %}
{% endhighlight %}


## 3.extern 和编译单元的问题
在上面的例子中，增加两个文件``` header31.h ```、``` header31.cc ```

- ``` header31.h ```
{% highlight html %}
#ifndef HEADER31_H
#define HEADER31_H

#include <string>
void printGlobalStr2();
#endif // !HEADER31_H

{% endhighlight %}

- ``` header31.cc ```
{% highlight html %}
#include "header3.h"
#include <string>
#include <iostream>

// extern std::string global_str;
void printGlobalStr2()
{
    std::cout << "printGlobalStr2():" << global_str << std::endl;
}
{% endhighlight %}


- ```test3.cc```更改为：
{% highlight html %}
#include <iostream>
extern void printGlobalStr();
extern void printGlobalStr2();
int main()
{
    printGlobalStr();
    printGlobalStr2();
}
{% endhighlight %}

- 编译运行

{% highlight html %}
g++ -std=c++11 test3.cc header3.cc header31.cc
./a.out 
printGlobalStr():xxxx
printGlobalStr2():xxxx
{% endhighlight %}


- 但是如果把header31.cc更改为：

{% highlight html %}
// #include "header3.h"
#include <string>
#include <iostream>

extern std::string global_str;
void printGlobalStr2()
{
    std::cout << "printGlobalStr2():" << global_str << std::endl;
}
{% endhighlight %}

<p>
这样编译连接没有问题，与上面的运行结果相同，所以说，在新的编译单元中，extern和include至少包含一项。
</p>



## 4.在声明extern变量的时候不要初始化，就是说，不要把声明和定义放在一块。这样会有意想不到的后果，导致在别的编译单元中只能使用extern，不能使用include。如果有很多函数的时候，这样会变得很麻烦，因为要一个个extern修饰。

{% highlight html %}
extern std::string global_str="xxxx";//不推荐
{% endhighlight %}
-----------------
## extern和static区别
