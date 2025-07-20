class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1; // Start from the rightmost element
        // Step 1: Find the longest non-increasing suffix (or the "pivot" position)
        while (i > 0 && nums[i - 1] >= nums[i])
        {
            i--; // Move left as long as elements are non-increasing
        }

        // If 'i' is 0, it means the entire array is in non-increasing order
        // (e.g., [5,4,3,2,1]). This is the largest permutation,
        // so we need to reverse the entire array to get the smallest (first) permutation.
        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // At this point, 'i' is the index of the first element in the suffix
        // that is smaller than the element to its right (nums[i-1] is the pivot).
        // Example: nums = [1, 3, 5, 4, 2]
        // i starts at 4 (index of 2).
        // nums[3] (4) >= nums[4] (2) -> i becomes 3.
        // nums[2] (5) >= nums[3] (4) -> i becomes 2.
        // nums[1] (3) < nums[2] (5) -> loop stops. 'i' is 2.
        // So, the pivot is nums[i-1] which is nums[1] = 3.
        // The suffix is from index 'i' to the end: [5, 4, 2].

        int j = nums.size() - 1; // Start from the rightmost element again
        // Step 2: Find the smallest element in the suffix (from 'i' to end)
        // that is greater than nums[i-1] (the pivot).
        while (j >= i && nums[j] <= nums[i - 1])
        {
            j--; // Move left as long as elements are less than or equal to the pivot
        }

        // At this point, nums[j] is the element to swap with nums[i-1].
        // Example (continuing from above): nums = [1, 3, 5, 4, 2], i=2, nums[i-1]=3
        // j starts at 4 (index of 2).
        // nums[4] (2) <= nums[1] (3) -> j becomes 3.
        // nums[3] (4) > nums[1] (3) -> loop stops. 'j' is 3.
        // So, nums[j] is nums[3] = 4.

        // Step 3: Swap the pivot with the found element
        swap(nums[i - 1], nums[j]);
        // Example: nums becomes [1, 4, 5, 3, 2]

        // Step 4: Reverse the suffix starting from index 'i'
        // This makes the suffix the smallest possible permutation.
        reverse(nums.begin() + i, nums.end());
        // Example: reverse [5, 3, 2] to [2, 3, 5]
        // nums becomes [1, 4, 2, 3, 5]
    }
};