#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getPrecedence(char op)
{

    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (c == ' ')
            continue;

        if (isalnum(c))
        {

            postfix += c;
        }

        else if (isOperator(c))
        {

            while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }

        else
        {
            return "error";
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{

    string result = infixToPostfix("A/B+C*D");

    cout << "Postfix Result: " << result << endl;

    return 0;
}