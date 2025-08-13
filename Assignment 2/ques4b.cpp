#include <iostream>
using namespace std;
int main() 
{
    char str[50];
    int len = 0;
    cout << "Enter a string: ";
    cin.getline(str, 50);
    while (str[len] != '\0') 
    {
        len++;
    }
    int i;
    for (i = 0; i < len / 2; i++) 
    {
        char temp;
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}
