1const int SZ=100001;
2int xMin[SZ], xMax[SZ], yMin[SZ], yMax[SZ];
3class Solution {
4public:
5    static int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
6        int M=0, N=0;
7        for(auto& B: buildings){
8            const int x=B[0], y=B[1];
9            M=max(x, M);
10            N=max(y, N);
11        }
12        memset(xMax, 0, sizeof(int)*(N+1));
13        memset(yMax, 0, sizeof(int)*(M+1));
14        fill(xMin, xMin+(N+1), INT_MAX);
15        fill(yMin, yMin+(M+1), INT_MAX);
16
17        for(auto& B: buildings){
18            const int x=B[0], y=B[1];
19            xMin[y]=min(xMin[y], x);
20            xMax[y]=max(xMax[y], x);
21            yMin[x]=min(yMin[x], y);
22            yMax[x]=max(yMax[x], y);
23        }
24        int cnt=0;
25        for(auto& B: buildings){
26            const int x=B[0], y=B[1];
27            const bool coverX=(xMin[y]<x & x<xMax[y]);
28            const bool coverY=(yMin[x]<y & y<yMax[x]);
29            cnt+=(coverX & coverY);
30        }
31        return cnt;
32    }
33};