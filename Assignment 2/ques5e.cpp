#include <iostream>
using namespace std;
int main()
{
    int i,j,k=0;
    int max=4; 
    int size = max*(max+1)/2;
    int arr[10];
    cout << "Enter the elements in row major order: " << endl;
    for(i=0; i<size ; i++)
    {
        cin >> arr[i];
    }
    cout << "The symmetric matrix is: " << endl;
    for(i=0; i<max; i++)
    {
        for(j=0; j<max; j++)
        {
            int index;
            if(i>=j)
            {
                index = (i*(i+1)/2) + j;
            }
            else{
                index = (j*(j+1)/2) + i;
            }
            cout << arr[index] << " ";
        }
        cout << endl;
    }
    return 0;
}