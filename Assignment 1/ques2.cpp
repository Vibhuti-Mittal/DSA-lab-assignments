#include <iostream>
using namespace std;
int main()
{
    int n;
    int arr[50];
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    int i,j,k;
    cout << "Enter elements of the array: " << endl;
    for (i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "The elements of the array are: " << endl;
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(i=0; i<n; i++)
    {
        for(j = n-1; j>i; j--)
        {
            if(arr[i] == arr[j])
            {
                for(k=j; k<n; k++)
                arr[k] = arr[k+1];
                n--;
            }
        }
    }
    cout << "Array after removing duplicates: " << endl;
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}