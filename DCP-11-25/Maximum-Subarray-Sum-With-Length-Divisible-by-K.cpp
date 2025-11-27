1class Solution {
2public:
3    using ll=long long;
4    static long long maxSubarraySum(vector<int>& nums, int k) {
5        const int n=nums.size();
6        vector<ll> minS(k, LLONG_MAX/2);
7        ll prefix=0, ans=LLONG_MIN;
8        minS[k-1]=0;
9        for(int i=0; i<n; i++){
10            prefix+=nums[i];
11            ll& ksum=minS[i%k];
12            ans=max(ans, prefix-ksum);
13            ksum=min(prefix, ksum);  
14        }
15        return ans;
16    }
17};