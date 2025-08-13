#include <iostream>
using namespace std;
int main() 
{
    char str1[50], str2[20];
    int len1 = 0, len2 = 0;
    cout << "Enter first string: ";
    cin.getline(str1, 50);
    cout << "Enter second string: ";
    cin.getline(str2, 20);
    while (str1[len1] != '\0')
    {
        len1++;
    }
    while (str2[len2] != '\0')
    {
        len2++;
    }
    int i;
    for (i = 0; i <= len2; i++)
    { 
        str1[len1 + i] = str2[i];
    }
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
