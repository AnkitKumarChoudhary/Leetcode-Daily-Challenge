1class Solution {
2public:
3    vector<string> validateCoupons(vector<string>& code,
4                                   vector<string>& businessLine,
5                                   vector<bool>& isActive) {
6        vector<string> e, g, p, r;
7
8        for (int i = 0; i < isActive.size(); i++) {
9            if (!isActive[i]) continue;
10
11            string& bl = businessLine[i];
12            if (bl != "electronics" && bl != "grocery" &&
13                bl != "pharmacy" && bl != "restaurant")
14                continue;
15
16            if (code[i].empty()) continue;
17
18            bool ok = true;
19            for (char c : code[i]) {
20                if (!isalnum(c) && c != '_') {
21                    ok = false; break;
22                }
23            }
24            if (!ok) continue;
25
26            if (bl[0] == 'e') e.push_back(code[i]);
27            if (bl[0] == 'g') g.push_back(code[i]);
28            if (bl[0] == 'p') p.push_back(code[i]);
29            if (bl[0] == 'r') r.push_back(code[i]);
30        }
31
32        sort(e.begin(), e.end());
33        sort(g.begin(), g.end());
34        sort(p.begin(), p.end());
35        sort(r.begin(), r.end());
36
37        vector<string> res;
38        res.insert(res.end(), e.begin(), e.end());
39        res.insert(res.end(), g.begin(), g.end());
40        res.insert(res.end(), p.begin(), p.end());
41        res.insert(res.end(), r.begin(), r.end());
42        return res;
43    }
44};