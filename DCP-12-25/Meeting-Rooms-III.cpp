1class Solution {
2public:
3    int mostBooked(int n, vector<vector<int>>& meetings) {
4        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){ return a[0] < b[0]; });
5        priority_queue<int, vector<int>, greater<int>> avail;
6        for (int i = 0; i < n; ++i) avail.push(i);
7        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
8        vector<int> cnt(n);
9        for (auto &m : meetings) {
10            long long s = m[0], e = m[1];
11            while (!busy.empty() && busy.top().first <= s) {
12                avail.push(busy.top().second);
13                busy.pop();
14            }
15            long long start;
16            int r, dur = e - s;
17            if (!avail.empty()) {
18                r = avail.top(); avail.pop();
19                start = s;
20            } else {
21                auto p = busy.top(); busy.pop();
22                start = p.first; r = p.second;
23            }
24            busy.emplace(start + dur, r);
25            ++cnt[r];
26        }
27        int best = 0;
28        for (int i = 1; i < n; ++i)
29            if (cnt[i] > cnt[best]) best = i;
30        return best;
31    }
32};