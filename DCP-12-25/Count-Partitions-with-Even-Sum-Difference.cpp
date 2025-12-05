1class Solution {
2public:
3    int countPartitions(vector<int>& A) {
4        int total = accumulate(A.begin(), A.end(), 0);
5        return total & 1 ? 0 : A.size() - 1;
6    }
7};