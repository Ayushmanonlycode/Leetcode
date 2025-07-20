class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0; 
        }
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        int longestStreak = 1;
     // Initialize with 1, as a single number is a sequence of length 1.

for(auto it : st) {
    // Check if 'it' is the start of a consecutive sequence.
    // 'it' is a start if 'it - 1' is NOT found in the set.
    if(st.find(it - 1) == st.end()) {
        int cnt = 1; // Current streak length, starting with 'it' itself.
        int x = it;  // Current number in the sequence.

        // Extend the sequence by checking for consecutive numbers (x+1, x+2, ...)
        while(st.find(x + 1) != st.end()) {
            x++;   // Move to the next number in the sequence.
            cnt++; // Increment the current streak length.
        }
        // After the while loop, 'cnt' holds the length of the current consecutive sequence.
        longestStreak = max(longestStreak, cnt); // Update the overall longest streak.
    }

        return longestStreak;
    }
};