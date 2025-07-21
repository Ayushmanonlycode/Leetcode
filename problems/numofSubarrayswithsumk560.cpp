class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int ps=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            ps+=nums[i];
            int rem = ps-k;
            cnt += mpp[rem];
            mpp[ps]+=1;
        }
        return cnt;
    }
};