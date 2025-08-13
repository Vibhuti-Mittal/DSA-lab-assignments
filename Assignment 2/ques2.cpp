#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    int i,j;
    for(i=0; i<7; i++)
    {
        for(j=0; j<7-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;            
            }
        }
    }
    cout << "Sorted array: " << endl;
    for(i=0; i<7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}