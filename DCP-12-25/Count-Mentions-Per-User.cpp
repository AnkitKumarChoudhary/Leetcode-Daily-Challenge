1class Solution {
2public:
3    int stoi(string s){
4        int x = 0;
5        for(auto c : s){
6            x = x * 10 + (c - '0');
7        }
8        return x;
9    }
10    int extract_id(string s){
11        return stoi(s.substr(2));
12    }
13    const int OFFLINE = 0;
14    const int MESSAGE = 1;
15    struct EVENT{
16        int type;
17        int time;
18        bool flag_all;
19        bool flag_here;
20        vector<int> ids;
21        EVENT(){
22            flag_all  = false;
23            flag_here = false;
24        }
25    };
26    
27    vector<EVENT> convert(vector<vector<string> > events){
28        vector<EVENT> EVENTS;
29        for(auto event : events){
30            EVENT new_event;
31            string type   = event[0];
32            int timestamp = stoi(event[1]);
33            new_event.time = timestamp;
34            if(type == "OFFLINE"){
35                new_event.type = OFFLINE;
36                new_event.ids  = {stoi(event[2])};
37                EVENTS.push_back(new_event);
38                continue;
39            }
40            new_event.type = MESSAGE;
41
42            if(event[2] == "ALL"){
43                new_event.flag_all  = true;
44                EVENTS.push_back(new_event);
45                continue;
46            }
47            if(event[2] == "HERE"){
48                new_event.flag_here = true;
49                EVENTS.push_back(new_event);
50                continue;
51            }
52            vector<string> stringids = {""};
53            for(auto c : event[2]){
54                if(c == ' '){
55                    stringids.push_back("");
56                    continue;
57                }
58                stringids.back() += c;
59            }
60            vector<int> ids;
61            for(auto stringid : stringids){
62                ids.push_back(extract_id(stringid));
63            }
64            new_event.ids = ids;
65            EVENTS.push_back(new_event);
66        }
67        return EVENTS;
68    }
69    
70    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
71        int n = numberOfUsers;
72        vector<int> mentions(n, 0);
73        
74        vector<EVENT> EVENTS = convert(events);
75        int all_count  = 0;
76        int here_count = 0;
77        unordered_map<int, int> here_at;
78        
79        for(auto event : EVENTS){
80            if(event.type == MESSAGE){
81                if(event.flag_all){
82                    all_count += 1;
83                    continue;
84                }
85                if(!event.flag_here){
86                    for(auto id : event.ids){
87                        mentions[id] += 1;
88                    }
89                    continue;
90                }
91                here_count += 1;
92                here_at[event.time] += 1;
93            }
94        }
95        for(int i = 0; i < n; i ++){
96            mentions[i] += all_count;
97            mentions[i] += here_count;
98        }
99        for(auto event : EVENTS){
100            if(event.type == MESSAGE) continue;
101            int id = event.ids[0];
102            for(int i = event.time; i < event.time + 60; i += 1){
103                mentions[id] -= here_at[i];
104            }
105        }
106        return mentions;
107    }
108};