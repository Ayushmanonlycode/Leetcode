class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        vector<vector<int>> freq(nums.size() + 1);

        // Count frequency of each number
        for (int num : nums) {
            hm[num]++;
        }

        // Put numbers into buckets based on frequency
        for (const auto& entry : hm) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;

        // Traverse buckets from high freq to low
        for (int i = freq.size() - 1; i >= 0 && res.size() < k; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};
