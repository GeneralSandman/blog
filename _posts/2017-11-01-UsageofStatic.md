---
layout: post
title: C/C++中static用法
description: static主要在单例模式中，当时他的规则具体来说是什么？是什么时候定义的，什么时候释放的，与普通变量有什么区别，希望这个blog可以清晰的解释这个问题。
img: atsea.jpg
width: medium
color: 00FF00
author: GeneralSandman
---

### 1.我们新建立一个类，通过类的构造、析构函数来查看static修饰的变量与不同变量有什么不同。代码如下

{% highlight html %}
{% endhighlight %}

- ```class.h```
{% highlight html %}
#ifndef CLASS_H
#define CLASS_H
#include <iostream>

class A
{
  public:
    int num;
    A(int n)
    {
        num = n;
        std::cout << "A (" << num << ") constructor\n";
    }
    ~A()
    {
        std::cout << "A (" << num << ") destructor\n";
    }
};

static A a4(4);

#endif // !CLASS_H

{% endhighlight %}


### 2.static修饰局部变量
在main文件中，a1为static全局变量，a2普通全局变量，a3为局部变量，a4为所在文件被include多次的static全局变量。观察运行结果

- ```header1.h```
{% highlight html %}
#ifndef HEADER1_H
#define HEADER1_H

void print();

#endif // !HEADER1_H

{% endhighlight %}

- ```header1.cc```
{% highlight html %}
#include "header1.h"
#include "class.h"
#include <iostream>

void print()
{
    std::cout << "print() block\n";
    a4.num = 44;
    std::cout << a4.num << std::endl;
    std::cout << "exit print() block\n";
}
{% endhighlight %}

- ```test1.cc```
{% highlight html %}
#include "class.h"
#include "header1.h"
#include <iostream>

static A a1(1);
A a2(2);

int main()
{
    std::cout << "main() block\n";
    print();
    {
        std::cout << "local block\n";
        A a3(3);

        a1.num=11;
        a2.num=22;
        
        std::cout << a4.num << std::endl;
    }
    std::cout << "exit main() block\n";
}
{% endhighlight %}

- 运行结果如下：
{% highlight html %}
A (1) constructor
A (4) constructor
A (1) constructor
A (2) constructor
A (4) constructor
main() block
print() block
44
exit print() block
local block
A (3) constructor
4
A (3) destructor
exit main() block
A (44) destructor
A (22) destructor
A (11) destructor
A (4) destructor
{% endhighlight %}

- 结论如下：
<blockquote>
<p>
1.a1和a2比较：静态全局变量与普通全局变量的存储形式没有区别，都是存储在静态区，在开始主函数时分配内存，主函数结束时释放内存。
</p>

<p>
2.观察a4:因为包含了两次class.h,所以在程序开始定义了两个a4变量，程序结束后释放。每个文件中的a4是相互独立的，print()中a4的成员变量不会影响主函数中的a4。static使全局变量可以同名。大家可以试试a4的static去掉有什么结果。
</p>

<p>
3.如果去掉a4中的static，链接会失败。
</p>

<p>
4.a1和a4比较：改变静态变量之后，只对本文件生效。间接证明2
</p>

</blockquote>






{% highlight html %}
{% endhighlight %}


{% highlight html %}
{% endhighlight %}

{% highlight html %}
{% endhighlight %}
<blockquote>
</blockquote>

