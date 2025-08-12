#include <iostream>
using namespace std;
int main()
{
    int r,c;
    int arr[50][50];
    cout << "Enter the number of rows and columns of matrix: " << endl;
    cin >> r >> c;
    int i,j;
    cout << "Enter the elements of the matrix: " << endl;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "The elements of the matrix are : " << endl;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sum of every row is: " << endl;
    int sum;
    for(i=0; i<r; i++)
    {
        sum = 0;
        for(j=0; j<c; j++)
        {
            
            sum = sum + arr[i][j];
        }
        cout << "Sum of row " << i+1 << " is: " << sum << endl;
    }
    cout << "Sum of every column is: " << endl;
    for(i=0; i<r; i++)
    {
        sum = 0;
        for(j=0; j<c; j++)
        {
            
            sum = sum + arr[j][i];
        }
        cout << "Sum of column " << i+1 << " is: " << sum << endl;
    }
    return 0;
}