#include <iostream>
using namespace std;
typedef struct{
    int element[20];
    int top;
}stack;
stack init()
{
    stack S;
    S.top = -1;
    return S;
}
int isEmpty(stack S)
{
    if(S.top==-1)
    return 1;
    else
    return 0;
}
int isFull(stack S)
{
    if(S.top == 19)
    return 1;
    else
    return 0;
}
int peek (stack S)
{
    if (isEmpty(S))
    cout << "Empty stack" << endl;
    else
    return S.element[S.top];
}
stack push(stack S, int x)
{
    if(isFull(S))
    cout << "Overflow" << endl;
    else{
        ++S.top;
        S.element[S.top] = x;
    }
    return S;
}
stack pop(stack S)
{
    if(isEmpty(S))
    cout << "Underflow" << endl;
    else
    --S.top;
    return S;
}
void display(stack S)
{
    int i;
    for(i=S.top; i>=0; --i)
    cout << S.element[i] << " ";
    cout << endl;
}
int main()
{
    stack S;
    S = init();
    S = push(S,10);
    S = push(S,45);
    S = push(S,15);
    S = push(S,20);
    cout << "Current stack: " << endl;
    display(S);
    cout << "Stack's top = " << peek(S) << endl;
    S = pop(S);
    S = pop(S);
    cout << "Stack after two pop operations: " << endl;
    display(S);
    cout << "Stack's top = " << peek(S) << endl;
    return 0;
}