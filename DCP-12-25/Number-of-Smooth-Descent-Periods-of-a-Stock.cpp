1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& nums) {
4        int n = nums.size();
5        int64_t ans = 1;
6        int64_t cnt = 1;
7        int prev = nums[0];
8
9        for (int i = 1; i < n; i++) {
10            if (prev - nums[i] == 1) {
11                cnt += 1;
12            } else {
13                cnt = 1;
14            }
15            prev = nums[i];
16            ans += cnt;
17        }
18        return ans;
19    }
20};