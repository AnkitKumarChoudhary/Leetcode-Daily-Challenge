1const int mod=1e9+7;
2class Solution {
3public:
4    int specialTriplets(vector<int>& nums) {
5        const int M=100001, n=nums.size();
6        int freq[M]={0}, prev[M]={0};
7        for(int x: nums) freq[x]++;
8        long long cnt=0;
9        prev[nums[0]]++;
10        for(int i=1; i<n-1; i++){
11            const int x=nums[i], x2=x<<1;
12            if (x2<M)
13                cnt+=(long long)prev[x2]*(freq[x2]-prev[x2]-(x==0));
14            prev[x]++;
15        }
16        return cnt%mod;
17    }
18};