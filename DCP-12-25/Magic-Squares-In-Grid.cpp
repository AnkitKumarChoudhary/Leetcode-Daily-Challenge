1class Solution {
2public:
3    int numMagicSquaresInside(vector<vector<int>>& grid) {
4        int r = grid.size(), c = grid[0].size(), ans = 0;
5        if (r < 3 || c < 3) return 0;
6
7        for (int i = 0; i + 2 < r; i++) {
8            for (int j = 0; j + 2 < c; j++) {
9                bool used[10] = {};
10                bool ok = true;
11                for (int x = 0; x < 3; x++) {
12                    for (int y = 0; y < 3; y++) {
13                        int v = grid[i + x][j + y];
14                        if (v < 1 || v > 9 || used[v]) {
15                            ok = false;
16                            break;
17                        }
18                        used[v] = true;
19                    }
20                    if (!ok) break;
21                }
22                if (!ok) continue;
23
24                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
25                for (int x = 0; x < 3; x++)
26                    if (grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2] != s) ok = false;
27                for (int y = 0; y < 3; y++)
28                    if (grid[i][j+y] + grid[i+1][j+y] + grid[i+2][j+y] != s) ok = false;
29                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s) ok = false;
30                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s) ok = false;
31
32                if (ok) ans++;
33            }
34        }
35        return ans;
36    }
37};