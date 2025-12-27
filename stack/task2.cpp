#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    int size = 5;
    int arr[5];
    int count = 0;

public:
    void push(int val)
    {
        if (count < size)
        {
            arr[count] = val;
            count++;
        }
    }
    void pop()
    {
        if (count > 0)
            count--;
    }
    int top()
    {
        return arr[count - 1];
    }
    bool empty()
    {
        return count == 0;
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
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}