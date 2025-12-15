1class Solution {
2public:
3    const int mod = 1e9 + 7;
4    int numberOfWays(string corridor) {
5        vector<int> pos;
6        for (int i = 0; i < corridor.size(); i++) {
7            if (corridor[i] == 'S') {
8                pos.push_back(i);
9            }
10        }
11        
12        if (pos.size() % 2 or pos.size() == 0) {
13            return 0;
14        }
15        
16        long res = 1;
17        for (int i = 2; i < pos.size(); i += 2) {
18            int len_of_gap = pos[i] - pos[i - 1];
19            res = (res * len_of_gap) % mod;
20        }
21
22        return res;
23    }
24};