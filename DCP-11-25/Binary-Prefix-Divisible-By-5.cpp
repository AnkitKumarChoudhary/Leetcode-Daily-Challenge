class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), x = 0;
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            x = (x * 2 + nums[i]) % 5;
            ans[i] = (x % 5 == 0);
        }
        return ans;
    }
};