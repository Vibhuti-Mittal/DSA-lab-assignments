#include <iostream>
using namespace std;
int main()
{
    int r,c;
    int arr[50][50];
    cout << "Enter the number of rows and columns of matrix: "<< endl;
    cin >> r >> c;
    int i,j;
    cout << "Enter the elements of the array: " << endl;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Original matrix: " << endl;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
           if(i>j)
           {
            int temp;
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
           }
        }
    }
    cout << "Transpose: " << endl;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}