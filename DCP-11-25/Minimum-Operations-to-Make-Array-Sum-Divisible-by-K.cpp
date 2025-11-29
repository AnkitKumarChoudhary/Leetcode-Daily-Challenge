1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        int ans=0;
5        for(int i=0;i<nums.size();i++){
6            ans+=nums[i];
7        }
8        return ans%k;
9    }
10};