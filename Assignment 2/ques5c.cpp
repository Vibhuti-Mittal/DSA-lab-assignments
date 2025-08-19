#include <iostream>
using namespace std;
int main()
{
    int i,j, k=0;
    int max = 4;
    int size = max*(max+1)/2;
    int arr[10];
    cout << "Enter elements in row major order: " << endl;
    for(i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    cout << "The lower triangle matrix is: " << endl;
    for(i=0; i<max; i++)
    {
        for(j=0; j<max; j++)
        {
            if(i>=j)
            {
                cout << arr[k] << " ";
                k++;
            }
            else
            cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}