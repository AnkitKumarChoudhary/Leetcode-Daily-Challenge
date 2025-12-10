1class Solution {
2public:
3    static const long long MOD = 1e9 + 7;
4    long long factorial(long long n) {
5        long long res = 1;
6        for (long long i = 1; i <= n; i++)
7            res = (res * i) % MOD;
8        return res;
9    }
10    int countPermutations(vector<int>& complexity) {
11        int n = complexity.size();
12        long long mn = complexity[0];
13        for (int i = 1; i < n; i++) {
14            if (mn >= complexity[i]) {
15                return 0;
16            }
17            mn = min(mn, (long long)complexity[i]);
18        }
19        return factorial(n - 1);
20    }
21};