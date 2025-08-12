#include <iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2;
    int arr[50][50];
    cout << "Enter the number of rows and columns in the matrix 1: " << endl;
    cin >> r1 >> c1; 
    cout << "Enter the number of rows and columns in the matrix 2: " << endl;
    cin >> r2 >> c2;
    int brr[50][50];
    int crr[50][50];
    int i,j,k;
    cout << "Enter elements of first matrix: " << endl;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            cin >> arr[i][j]; 
        }
    }
    cout << "Enter elements of second matrix: " << endl;
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            cin >> brr[i][j]; 
        }
    }
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            crr[i][j] = 0;
            for(k=0; k<r2; k++){
            crr[i][j] += arr[i][k]*brr[k][j];
            }
        }
    }
    cout << "First matrix is: " << endl;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
           cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
    cout << "Second matrix is: " << endl;
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
           cout << brr[i][j] << " "; 
        }
        cout << endl;
    }
    cout << "Resultant matrix is: " << endl;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
           cout << crr[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}