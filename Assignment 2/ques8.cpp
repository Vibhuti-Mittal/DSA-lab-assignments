#include <iostream>
using namespace std;
int main()
{
    int n;
     int arr[20];
     cout << "Enter the number of elements in the array: ";
     cin >> n;
     int i,j;
     cout << "Enter the elements of the array: ";
     for(i=0; i<n; i++)
     {
        cin >> arr[i];
     }
     int count = 0;
     int flag = 0;
     for(i=0; i<n; i++)
     {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] != arr[j])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            count ++;
        }
     }
     cout << "The number of distinct elements in the array is: " << count << endl;
    return 0;
}