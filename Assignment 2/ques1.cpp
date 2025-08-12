#include <iostream>
using namespace std;
int main(){
    int n;
    int arr[50];
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    int i;
    cout << "Enter the elements of the array: " << endl;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "The elements of the array are: "<< endl;
    for(i = 0; i<n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
    cout << "Enter element that you want to search : "<< endl;
    int ele;
    cin >> ele;
    int start, mid, end;
    start = 0, end = n;
   
    int flag = -1;
    while(start <= end)
    {
        mid = (start + end)/2;
        if(arr[mid] == ele)
        {
            flag = mid;
            break;
        }
        else if(arr[mid] < ele)
        {
            start = mid +1;
        }
        else{
            end = mid - 1;
        }
    }
    if(flag >=0)
    {
        cout << "Element found at index: " << flag << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}