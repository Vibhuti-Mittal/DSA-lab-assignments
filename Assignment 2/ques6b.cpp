#include <iostream>
using namespace std;
int main()
{
    int i,j,k=1;
    int a1[20][3], a2[20][3], sum[40][3];
    int t1,t2; 
    cout << "Enter the number of rows, columns and non-zero terms of matrix 1: " << endl;
    cin >> a1[0][0] >> a1[0][1] >> t1;
    a1[0][2] = t1;
    cout << "Enter the triplet form of matrix 1 (row column value) : " << endl;
    for(i=1; i<=t1; i++)
    {
        cin >> a1[i][0] >> a1[i][1] >> a1[i][2];
    }
    
    cout << "Enter the number of rows, columns and non-zero terms of matrix 2: " << endl;
    cin >> a2[0][0] >> a2[0][1] >> t2;
    a2[0][2] = t2;
    cout << "Enter the triplet form of matrix 2 (row column value) : " << endl;
    for(i=1; i<=t2; i++)
    {
        cin >> a2[i][0] >> a2[i][1] >> a2[i][2];
    }
    
    if(a1[0][0] != a2[0][0] || a1[0][1] != a2[0][1])
    {
        cout << "Dimensions of matrices must be same for addition" << endl;
    }
    else{
        i=1,j=1,k=1;
        while(i<=t1 && j<=t2)
        {
            if((a1[i][0] < a2[j][0]) || (a1[i][0] == a2[j][0] && a1[i][1] < a2[j][1]))
            {
                sum[k][0] = a1[i][0];
                sum[k][1] = a1[i][1];
                sum[k][2] = a1[i][2];
                i++;k++;
            }
            else if((a1[i][0] > a2[j][0]) || (a1[i][0] == a2[j][0] && a1[i][1] > a2[j][1]))
            {
                sum[k][0] = a2[j][0];
                sum[k][1] = a2[j][1];
                sum[k][2] = a2[j][2];
                j++;k++;
            }
            else
            {
                int val = a1[i][2] + a2[j][2] ;
                if(val!=0)
                {
                sum[k][0] = a2[j][0];
                sum[k][1] = a2[j][1];
                sum[k][2] = val;
                i++; j++; k++;
                }

            }
        }
        while(i<=t1)
        {
            sum[k][0] = a1[i][0];
            sum[k][1] = a1[i][1];
            sum[k][2] = a1[i][2];
            i++;k++;
        }
        while(j<=t2)
        {
            sum[k][0] = a2[j][0];
            sum[k][1] = a2[j][1];
            sum[k][2] = a2[j][2];
            j++;k++;
        }
    }
    sum[0][0] = a1[0][0];
    sum[0][1] = a1[0][1];
    sum[0][2] = k-1;
    cout << "Row Column Value " << endl;
    for(i=0; i<k; i++)
    {
        cout << sum[i][0] << " " << sum[i][1] << " " <<  sum[i][2] << endl;
    }

    return 0;
}