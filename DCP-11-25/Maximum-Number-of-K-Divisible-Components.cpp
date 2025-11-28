1class Solution {
2public:
3    int res = 0;
4    vector<vector<int>> adj;
5    long long DFS(int node, int parent, vector<int>& values, int k){
6        long long total = values[node];
7        for (int nei : adj[node]){
8            if (nei == parent)
9                continue;
10            total += DFS(nei, node, values, k);
11        }
12        if (total % k == 0){
13            res++;
14            return 0;
15        }
16        return total;
17    }
18    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
19        adj.assign(n, vector<int>());
20        for (auto &e : edges){
21            adj[e[0]].push_back(e[1]);
22            adj[e[1]].push_back(e[0]);
23        }
24        DFS(0, -1, values, k);
25        return res;
26    }
27};