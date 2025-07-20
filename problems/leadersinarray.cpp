#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> leaders(std::vector<int>& nums) {
        std::vector<int> ans;
        if (nums.empty()) {
            return ans;
        }

        // Initialize currentMax with the smallest possible integer value.
        // Or, you can start with the last element and add it to ans,
        // then iterate from the second last element.
        int currentMax = -2147483648; // Equivalent to INT_MIN from <limits> or <climits>

        // Traverse the array from right to left
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > currentMax) {
                ans.push_back(nums[i]);
                currentMax = nums[i];
            }
        }

        // Leaders were added from right to left, so they are in reverse order.
        // Reverse the 'ans' vector to get them in the original array's order.
        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};