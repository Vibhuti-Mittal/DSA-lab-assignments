#include <iostream> 
using namespace std;
int main()
{
    int n;
    int arr[50];
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    int i;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<n;i++)
    {
        if(arr[i]!= i+1)
        {
            cout << "The missing number is: " << i+1 << endl;
            break;
        }
    }
    return 0;
}