1class Solution {
2public:
3    bool can(int i,string n,string b,unordered_map<string,vector<char>> &mp,unordered_map<string,bool> &me){
4        if(b.size()==1) return true;
5        if(i==b.size()-1){
6            if(me.count(n))
7            return me[n];
8            return me[n]=can(0,"",n,mp,me);
9        }
10        string k=b.substr(i,2);
11        if(mp.find(k)==mp.end()) return false;
12        for(char ch:mp[k]){
13            if(can(i+1,n+ch,b,mp,me)) return true;
14        }
15        return false;
16    }
17    bool pyramidTransition(string bottom, vector<string>& allowed) {
18        unordered_map<string,vector<char>>mp;
19        unordered_map<string,bool>me;
20        for(string &s:allowed)
21        mp[s.substr(0,2)].push_back(s[2]);
22        return can(0,"",bottom,mp,me);
23    }
24};