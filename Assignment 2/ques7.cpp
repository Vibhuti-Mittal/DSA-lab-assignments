#include <iostream>
using namespace std;
int main()
{
    int n;
    int arr[20];
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    int i,j,count = 0;
    cout << "Enter the elements of array: " << endl;
    for(i=0; i<n; i++)
    cin >> arr[i];
    cout << "The array is: " << endl;
    for(i=0; i<n; i++)
    cout << arr[i] << " ";
    cout << endl;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n;j++)
        {
            if(i<j && arr[i]>arr[j])
            count++;
        }
    }
    cout << "The number of inversions in the array are: " << count;
    return 0;
}