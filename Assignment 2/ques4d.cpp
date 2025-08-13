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
    int i,j;
    for (i = 0; i < len - 1; i++) 
    {
        for (j = i + 1; j < len; j++) 
        {
            if (str[i] > str[j]) 
            {
                char temp;
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "String in alphabetical order: " << str << endl;
    return 0;
}
