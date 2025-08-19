#include <iostream>
using namespace std;
int main() 
{
    int i,j;
    int max = 4; 
    int arr[4];
    cout << "Enter elements of array in row major order: " << endl;
    for (i=0; i<max; i++)
    {
        cin >> arr[i];
    }
    cout << "The diagonal matrix is: " << endl;
    for(i=0; i<max; i++)
    {
        for(j=0; j<max; j++)
        {
            if(i==j)
            cout << arr[i] << " ";
            else
            cout << "0 ";
        }
        cout << endl;
    }
    
    return 0;
}
