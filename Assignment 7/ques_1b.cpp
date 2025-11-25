#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 1; i < n; i++) {
            int key = nums[i]; 
            int j = i - 1; 
            
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            
            nums[j + 1] = key; 
        }
        
        return nums;
    }
};


int main() {
    Solution solution;
    
   vector<int> nums;
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;
    cout << "Enter elements of array: " << endl;
    for(int i = 0; i<n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    
    cout << "Before Using Insertion Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    nums = solution.insertionSort(nums);

    cout << "After Using Insertion Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
