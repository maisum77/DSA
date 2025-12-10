#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isalnum

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^') // Optional: For exponentiation
        return 3;
    return 0; // For parentheses and other characters
}

// Function to perform the conversion
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> s;
    std::string postfix = "";

    for (const char& token : infix) {
        // 1. If the token is an Operand (alphanumeric)
        if (isalnum(token)) {
            postfix += token;
        }
        // 2. If the token is a Left Parenthesis
        else if (token == '(') {
            s.push(token);
        }
        // 3. If the token is a Right Parenthesis
        else if (token == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            // Discard the opening parenthesis
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        }
        // 4. If the token is an Operator
        else {
            // While the stack is not empty, the top is not '(', 
            // AND the top operator has greater or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(token)) {
                // Pop and output the higher precedence operator
                postfix += s.top();
                s.pop();
            }
            // Push the current operator
            s.push(token);
        }
    }

    // 5. Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Main function to test the conversion
int main() {
    std::string infix1 = "A+B*C-D/E";
    std::string postfix1 = infixToPostfix(infix1);
    std::cout << "Infix: " << infix1 << std::endl;
    std::cout << "Postfix: " << postfix1 << "  (Expected: ABC*+DE/-)" << std::endl;

    std::cout << "---" << std::endl;

    std::string infix2 = "A*(B+C/D)";
    std::string postfix2 = infixToPostfix(infix2);
    std::cout << "Infix: " << infix2 << std::endl;
    std::cout << "Postfix: " << postfix2 << "  (Expected: ABCD/*+)" << std::endl;
    
    std::cout << "---" << std::endl;

    std::string infix3 = "(A+B)*(C-D)";
    std::string postfix3 = infixToPostfix(infix3);
    std::cout << "Infix: " << infix3 << std::endl;
    std::cout << "Postfix: " << postfix3 << "  (Expected: AB+CD-*)" << std::endl;

    return 0;
}