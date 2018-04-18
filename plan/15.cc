#include <iostream>
using namespace std;

class A
{
  private:
  public:
    A() { cout << "class A constructor\n"; }
    ~A() { cout << "class A destructor\n"; }
};

template <typename T>
class SmartPointer
{
  private:
    int *nums;
    T *pointer;

    void releaseCount()
    {
        if (pointer != nullptr)
        {
            (*nums)--;
            if (*nums == 0)
            {
                cout << "release space\n";
                delete pointer;
                delete nums;
            }
        }
    }

  public:
    SmartPointer(T *p = nullptr)
    {
        nums = new int;
        pointer = p;
        *nums = (p == nullptr) ? 0 : 1;
    }

    SmartPointer(const SmartPointer &src)
    {
        cout << "copy function\n";
        if (&src != this)
        {
            pointer = src.pointer;
            nums = src.nums;
            (*nums)++;
        }
    }

    SmartPointer &operator=(const SmartPointer &src)
    {
        cout << "placement function\n";
        if (src.pointer == pointer)
        {
            return *this;
        }
        releaseCount();
        pointer = src.pointer;
        nums = src.nums;
        (*nums)++;
        return *this;
    }

    T *operator->()
    {
        if (pointer)
            return pointer;
    }

    T &operator*()
    {
        if (pointer)
            return *pointer;
    }

    ~SmartPointer()
    {
        releaseCount();
    }
};

int main()
{
    {
        SmartPointer<A> p1 = new A;
        
    }
    return 0;
}