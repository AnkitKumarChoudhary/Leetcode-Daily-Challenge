1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        unordered_set<int> s;
5        for (int x : nums) {
6            if (!s.insert(x).second) return x;
7        }
8        return -1;
9    }
10};