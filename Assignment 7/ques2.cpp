#include <iostream>
#include <vector>
using namespace std;

void improvedSelectionSort(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;

        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr);

    cout << "Sorted array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
