#include <iostream>
using namespace std;
struct Stack {
    char arr[20];
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
    return (S.top == 19);
}
void push(Stack &S, char x) {
    if (isFull(S)) {
        cout << "Stack Overflow\n";
    } else {
        S.arr[++S.top] = x;
    }
}
char pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack Underflow\n";
        return '\0';
    } else {
        return S.arr[S.top--];
    }
}
char peek(Stack S) {
    if (isEmpty(S)) return '\0';
    return S.arr[S.top];
}
bool isBalanced(string expr) {
    Stack s = init();

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(s, ch);  
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(s)) return false; 
            char top = pop(s); 
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; 
            }
        }
    }
    return isEmpty(s); 
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
