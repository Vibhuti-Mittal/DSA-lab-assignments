#include <iostream>
using namespace std;
int main()
{
    int i,j,k=1;
    int arr[20][3], brr[20][3];
    int row,col,terms;
    cout << "Enter the number of rows, columns and non-zero terms: "<< endl;
    cin >> row >> col >> terms;
    arr[0][0] = row;
    arr[0][1] = col;
    arr[0][2] = terms;
    cout << "Enter the elements in triplets (row column value): " << endl;
    for(i=1; i<=terms; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
     brr[0][0] = col;
     brr[0][1] = row;
     brr[0][2] = terms;
    int c;
     for(c=0; c<col; c++)
     {
        for(i=1; i<=terms; i++)
        {
            if(arr[i][1] == c)
            {
                brr[k][0] = arr[i][1];
                brr[k][1] = arr[i][0];
                brr[k][2] = arr[i][2];
                k++;
            }
        }
     }
     cout << "The transpose is: " << endl;
     cout << "Row Column Value" << endl;
     for(i=0; i<=terms; i++)
     {
        cout << brr[i][0] << " " << brr[i][1] << " " << brr[i][2] << endl;
     }

    return 0;
}