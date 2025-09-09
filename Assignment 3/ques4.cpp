#include <iostream>
#include <cctype>   
using namespace std;
struct Stack {
    char arr[50];
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
    return (S.top == 49);
}

void push(Stack &S, char x) {
    if (!isFull(S)) {
        S.arr[++S.top] = x;
    }
}

char pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.arr[S.top--];
    }
    return '\0';
}

char peek(Stack S) {
    if (!isEmpty(S)) return S.arr[S.top];
    return '\0';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return (op == '^'); //we check this because if there are two consecutive right associative operators with the same precedence , then too we push the second operator onto the stack without popping the first one already present in the stack like in all other cases
}

string infixToPostfix(string infix) {
    Stack s = init();
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {  
            postfix += ch;
        }
        else if (ch == '(') {
            push(s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix += pop(s);
            }
            pop(s); 
        }
        else { 
            while (!isEmpty(s) && precedence(peek(s)) > 0 &&
                   (precedence(peek(s)) > precedence(ch) ||
                    (precedence(peek(s)) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += pop(s);
            }
            push(s, ch);
        }
    }

    while (!isEmpty(s)) {
        postfix += pop(s);
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
