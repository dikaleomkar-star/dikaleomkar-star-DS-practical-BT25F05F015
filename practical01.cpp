
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int b = s.pop();
            int a = s.pop();

            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.pop();
}

int main() {
    string exp;

    cout << "Enter postfix expression: ";
    getline(cin, exp);

    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}
