#include <iostream>
#include <string>
#include <stack> // Used for demonstration in conversion logic
#include <algorithm>

using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(char x)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    char pop()
    {
        if (isEmpty())
            return '\0';
        Node *temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    char peek()
    {
        if (top != nullptr)
            return top->data;
        else
            return '\0';
    }
    bool isEmpty() { return top == nullptr; }

    int precedence(char c)
    {
        if (c == '^')
            return 3;
        if (c == '*' || c == '/')
            return 2;
        if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    // 1. Infix to Postfix
    string infixToPostfix(string s)
    {
        Stack st;
        string res;
        for (char c : s)
        {
            if (isalnum(c))
                res += c;
            else if (c == '(')
                st.push('(');
            else if (c == ')')
            {
                while (st.peek() != '(')
                    res += st.pop();
                st.pop();
            }
            else
            {
                while (!st.isEmpty() && precedence(c) <= precedence(st.peek()))
                    res += st.pop();
                st.push(c);
            }
        }
        while (!st.isEmpty())
            res += st.pop();
        return res;
    }

    // 2. Reverse String
    string reverseString(string s)
    {
        Stack st;
        for (char c : s)
            st.push(c);
        string rev = "";
        while (!st.isEmpty())
            rev += st.pop();
        return rev;
    }

    // 3. Simple Expression Solver (Postfix Evaluation)
    int evaluatePostfix(string exp)
    {
        stack<int> st; // Using standard stack for integer math simplicity
        for (char c : exp)
        {
            if (isdigit(c))
                st.push(c - '0');
            else
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                switch (c)
                {
                case '+':
                    st.push(val2 + val1);
                    break;
                case '-':
                    st.push(val2 - val1);
                    break;
                case '*':
                    st.push(val2 * val1);
                    break;
                case '/':
                    st.push(val2 / val1);
                    break;
                }
            }
        }
        return st.top();
    }
};
int main()
{
    Stack s;
    string text = "DataStructures";
    cout << "Original: " << text << endl;
    cout << "Reversed: " << s.reverseString(text) << endl ;

    string infix = "a+b*(c^d-e)";
    string postfix = s.infixToPostfix(infix);
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    string exp = "231*+9-"; // (2 + (3*1)) - 9 = -4
    cout << "Postfix Expression: " << exp << endl;
    cout << "Evaluation Result:  " << s.evaluatePostfix(exp) << endl;
}