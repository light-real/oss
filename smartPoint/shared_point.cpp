#include <iostream>
#include <memory>

using namespace std;
//避免循环引用：通常的做法是owner持有指向child的shared_ptr,child持有指向owner的weaker_ptr
class B;
class A
{
public:
    // shared_ptr<B> pb; //循环引用，两个shared_ptr指向对方
    weak_ptr<B> pb;
    ~A()
    {
        cout << "delete A" << endl;
    }
    void dosomething()
    {
        shared_ptr<B> pp = pb.lock();
        if (pp)
        {
            cout << "pp.use_count() = " << pp.use_count() << endl;
        }
    }
};

class B
{
public:
    shared_ptr<A> pa;
    ~B()
    {
        cout << "delete B" << endl;
    }
};

int main()
{
    shared_ptr<A> sa(new A());
    shared_ptr<B> sb(new B());
    if (sa && sb)
    {
        sa->pb = sb;
        sb->pa = sa;
    }
    cout << "sa.use_count() = " << sa.use_count() << endl;
    sa->dosomething();
    return 0;
}