#include <iostream>
using namespace std;
int main() {
    int mat1[20][3], mat2[20][3], trans[20][3], result[20][3];
    int t1, t2;
    cout << "Enter number of rows, columns and non-zero elements for Matrix 1: " << endl;
    cin >> mat1[0][0] >> mat1[0][1] >> t1;
    mat1[0][2] = t1;

    cout << "Enter triplets (row col value) for Matrix 1: " << endl;
    for (int i = 1; i <= t1; i++) cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];

    cout << "Enter number of rows, columns and non-zero elements for Matrix 2: " << endl;
    cin >> mat2[0][0] >> mat2[0][1] >> t2;
    mat2[0][2] = t2;

    cout << "Enter triplets (row col value) for Matrix 2: " << endl;
    for (int i = 1; i <= t2; i++) 
    {
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];
    }
    if (mat1[0][1] != mat2[0][0]) 
    {
        cout << "Matrix dimensions do not match for multiplication!" << endl;
        
    }

    else
    {
    trans[0][0] = mat2[0][1];
    trans[0][1] = mat2[0][0];
    trans[0][2] = mat2[0][2];

    int k = 1;
    for (int col = 0; col < mat2[0][1]; col++) {
        for (int i = 1; i <= t2; i++) {
            if (mat2[i][1] == col) {
                trans[k][0] = mat2[i][1];
                trans[k][1] = mat2[i][0];
                trans[k][2] = mat2[i][2];
                k++;
            }
        }
    }

    int r = mat1[0][0], c = mat2[0][1];
    int total = 0, resk = 1;

    for (int i = 1; i <= t1;) {
        int row = mat1[i][0];
        for (int j = 1; j <= t2;) {
            int col = trans[j][0];
            int sum = 0, ti = i, tj = j;

            while (ti <= t1 && mat1[ti][0] == row &&
                   tj <= t2 && trans[tj][0] == col) {
                if (mat1[ti][1] < trans[tj][1]) ti++;
                else if (mat1[ti][1] > trans[tj][1]) tj++;
                else {
                    sum += mat1[ti][2] * trans[tj][2];
                    ti++; tj++;
                }
            }

            if (sum != 0) {
                result[resk][0] = row;
                result[resk][1] = col;
                result[resk][2] = sum;
                resk++;
                total++;
            }

            while (j <= t2 && trans[j][0] == col) j++;
        }
        while (i <= t1 && mat1[i][0] == row) i++;
    }

    result[0][0] = r;
    result[0][1] = c;
    result[0][2] = total;

    cout << "Product in triplet form is: " << endl;
    cout << "Row Col Val" << endl;
    for (int x = 0; x <= total; x++) {
        cout << result[x][0] << "   " << result[x][1] << "   " << result[x][2] << endl;
    }
}
    return 0;
}
