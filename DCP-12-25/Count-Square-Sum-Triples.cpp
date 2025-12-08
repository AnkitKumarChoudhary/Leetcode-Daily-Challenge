1class Solution {
2public:
3    static int GCD(unsigned x, unsigned y){
4        const int bx=countr_zero(x), by=countr_zero(y);
5        const int bb=min(bx, by);
6        x>>=bx, y>>=by;
7        for(unsigned r; y; y=min(y, r)){
8            r=x%y;
9            x=exchange(y, r);
10        }
11        return x<<bb;
12    }
13    static int countTriples(int n) {
14        int cnt=0;
15        int nsqrt=sqrt(n);
16        for (int s=2; s<=nsqrt; s++) {
17            for (int t=1+(s&1); t<s; t+=2) {
18                if (GCD(s, t)!=1) continue;
19
20                int c=s*s+t*t;
21
22                if (c>n) break;
23
24                int kmax=n/c;
25                cnt+=2*kmax;
26            }
27        }
28        return cnt;
29    }
30};