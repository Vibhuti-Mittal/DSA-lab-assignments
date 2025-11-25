#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = n - 1; i >= 0; i--) {
           
            bool didSwap = false;
            for (int j = 0; j <= i - 1; j++) {
               
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    didSwap = true;
                }
            }
          
            if (!didSwap) {
                break;
            }
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
    
    cout << "Before Using Bubble Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    nums = solution.bubbleSort(nums);

    cout << "Array After Using Bubble Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
