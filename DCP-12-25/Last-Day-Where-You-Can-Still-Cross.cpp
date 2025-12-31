1
2
3class Solution {
4    int R, C;
5    vector<int> dx{1,-1,0,0}, dy{0,0,1,-1};
6
7    bool canCross(int day, vector<vector<int>>& cells) {
8        vector<vector<int>> grid(R, vector<int>(C, 0));
9        for (int i = 0; i < day; i++)
10            grid[cells[i][0]-1][cells[i][1]-1] = 1;
11
12        queue<pair<int,int>> q;
13        vector<vector<int>> vis(R, vector<int>(C, 0));
14
15        for (int j = 0; j < C; j++) {
16            if (grid[0][j] == 0) {
17                q.push({0, j});
18                vis[0][j] = 1;
19            }
20        }
21
22        while (!q.empty()) {
23            auto [x, y] = q.front(); q.pop();
24            if (x == R-1) return true;
25
26            for (int k = 0; k < 4; k++) {
27                int nx = x + dx[k], ny = y + dy[k];
28                if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
29                    !vis[nx][ny] && grid[nx][ny] == 0) {
30                    vis[nx][ny] = 1;
31                    q.push({nx, ny});
32                }
33            }
34        }
35        return false;
36    }
37
38public:
39    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
40        R = row; C = col;
41        int lo = 1, hi = cells.size(), ans = 0;
42
43        while (lo <= hi) {
44            int mid = (lo + hi) / 2;
45            if (canCross(mid, cells)) {
46                ans = mid;
47                lo = mid + 1;
48            } else hi = mid - 1;
49        }
50        return ans;
51    }
52};