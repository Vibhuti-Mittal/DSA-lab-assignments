#include <iostream>
#include <cctype>   // for isdigit
#include <cmath>    // for pow
using namespace std;

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == MAX - 1);
}

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.arr[++S.top] = x;
    }
}

int pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.arr[S.top--];
    }
    return 0;
}

int evaluatePostfix(string expr) {
    Stack s = init();

    for (char ch : expr) {
        if (isdigit(ch)) {
            push(s, ch - '0'); // convert char to int
        } else {
            int val2 = pop(s);
            int val1 = pop(s);
            switch (ch) {
                case '+': push(s, val1 + val2); break;
                case '-': push(s, val1 - val2); break;
                case '*': push(s, val1 * val2); break;
                case '/': push(s, val1 / val2); break;
                case '^': push(s, pow(val1, val2)); break;
            }
        }
    }
    return pop(s);
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
