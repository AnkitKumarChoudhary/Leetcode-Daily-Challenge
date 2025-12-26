1class Solution {
2public:
3    int bestClosingTime(string customers) {
4        int n = customers.size();
5        int y_rem = count(customers.begin(), customers.end(), 'Y');
6        int nn = 0;
7        
8        int penalty = nn+y_rem;
9        int minP=penalty, minI=0;
10        
11        for (int i=1; i <= n; i++) {
12            int y=customers[i-1] == 'Y';
13            y_rem -= y;
14            nn+=(1-y); 
15            penalty=nn+y_rem;
16            
17            if (minP> penalty) {
18                minP=penalty;
19                minI=i;
20            }
21        }
22        return minI;
23    }
24};