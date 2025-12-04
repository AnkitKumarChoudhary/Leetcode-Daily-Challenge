1class Solution {
2public:
3    int countCollisions(string directions) {
4        int n = directions.size();
5        int ans = 0;
6        bool accident;
7        accident = false;
8        for(int i = 1; i < n; i ++){
9            if(directions[i] == 'L'){
10                if(directions[i - 1] != 'L' || accident){
11                    ans += 1;
12                    accident = true;
13                }
14            }
15        }
16        accident = false;
17        for(int i = n - 2; i >= 0; i --){
18            if(directions[i] == 'R'){
19                if(directions[i + 1] != 'R' || accident){
20                    ans += 1;
21                    accident = true;
22                }
23            }
24        }
25        return ans;
26    }
27};