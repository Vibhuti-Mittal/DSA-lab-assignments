#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    vector<int> selectionSort(vector<int>& nums) {
     
        for (int i = 0; i < nums.size() - 1; i++) {
          
            int minIndex = i;
            
            for (int j = i + 1; j <nums.size(); j++) {
                
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
        
            if (minIndex != i) {
                swap(nums[minIndex], nums[i]);
            }
        }
        return nums;
    }
};

int main() {

    vector<int> arr;
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;
    cout << "Enter elements of array: " << endl;
    for(int i = 0; i<n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    Solution s1;

    vector<int> sortedArr = s1.selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}