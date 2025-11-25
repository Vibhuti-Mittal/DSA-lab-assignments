#include <iostream>
#include <vector>
using namespace std;
void heapifyMax(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}
void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}
void heapSortIncreasing(vector<int>& arr) {
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);          
        heapifyMax(arr, i, 0);        
    }
}

void heapSortDecreasing(vector<int>& arr) {
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);          
        heapifyMin(arr, i, 0);         
    }
}

int main() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1. Increasing Order\n2. Decreasing Order\nChoose option: ";
    cin >> choice;

    if (choice == 1) {
        heapSortIncreasing(arr);
        cout << "\nSorted (Increasing): ";
    }
    else {
        heapSortDecreasing(arr);
        cout << "\nSorted (Decreasing): ";
    }

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
