class Solution {         // Define a class named Solution, a common practice in competitive programming.
public:                  // Public access specifier, meaning the method below can be called from outside the class.
    // Function to check if a vector of integers contains any duplicate elements.
    bool hasDuplicate(std::vector<int>& nums) {
        // Create an unordered_set to store numbers encountered so far.
        // unordered_set provides average O(1) time complexity for insertion and lookup.
        std::unordered_set<int> seen;

        // Iterate through each number in the input vector 'nums'.
        // This is a range-based for loop, convenient for iterating over collections.
        for (int num : nums) {
            // Check if the current number 'num' already exists in the 'seen' set.
            // 'seen.count(num)' returns 1 if 'num' is found, and 0 otherwise.
            if (seen.count(num)) {
                // If 'num' is found in 'seen', it means we've encountered this number before,
                // indicating a duplicate.
                // Immediately return true as soon as a duplicate is found.
                return true;
            }
            // If the current number 'num' is NOT in the 'seen' set, it means it's unique so far.
            // Add this number to the 'seen' set so we can track it for future comparisons.
            seen.insert(num);
        }

        // If the loop completes, it means we have iterated through all numbers
        // and have not found any duplicates.
        // Therefore, return false.
        return false;
    }
};
