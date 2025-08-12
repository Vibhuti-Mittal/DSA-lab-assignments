#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    int arr[50];
    cout << "Enter the elements of the array: " << endl;
    int i;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "The elements of the array are: " << endl;
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " " << endl;
    }
    for(i=0; i<=n/2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    cout << "The elements of the array after reversing are: " << endl;
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " " << endl;
    }
    return 0;
}