#include <iostream>
using namespace std;

typedef struct {
    char element[50];
    int top;
} stack;
stack init() {
    stack S;
    S.top = -1;
    return S;
}
int isEmpty(stack S) {
    return (S.top == -1);
}
int isFull(stack S) {
    return (S.top == 49);
}
void push(stack &S, char x) {
    if (isFull(S))
        cout << "Overflow" << endl;
    else {
        ++S.top;
        S.element[S.top] = x;
    }
}
char pop(stack &S) {
    if (isEmpty(S)) {
        cout << "Underflow" << endl;
        return '\0';
    } else {
        return S.element[S.top--];
    }
}
string reverseString(string str) {
    stack s = init();
    string reversed = "";
    for (char ch : str) {
        push(s, ch);
    }
    while (!isEmpty(s)) {
        reversed += pop(s);
    }

    return reversed;
}

int main() {
    string input = "DataStructure";
    cout << "Original String: " << input << endl;
    cout << "Reversed String: " << reverseString(input) << endl;
    return 0;
}
