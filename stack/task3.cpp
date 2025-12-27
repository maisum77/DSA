#include <iostream>
#include <vector>
#include<list>
using namespace std;
class Stack
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        ll.pop_front();
    }
    int top()
    {
        ll.front();
    }
    bool empty()
    {
        return ll.front() == NULL;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}