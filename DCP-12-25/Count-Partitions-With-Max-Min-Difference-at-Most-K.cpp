1class Solution {
2public:
3    static int countPartitions(vector<int>& nums, int k) {
4        const int n=nums.size();
5        constexpr int mod=1e9+7;
6        multiset<int> win;
7        long long cnt=0;
8        int* sum=(int*)alloca((n+2)*sizeof(int));
9        memset(sum, 0, sizeof(sum));
10        sum[1]=1;
11    
12        for(int l=0, r=0; r<n; r++){
13            const int x=nums[r];
14            win.insert(x);
15            while(*(prev(win.end()))-*win.begin()>k){
16                auto it=win.lower_bound(nums[l++]);
17                win.erase(it);
18            }
19            cnt=(mod+sum[r+1]-sum[l])%mod;
20            sum[r+2]=(sum[r+1]+cnt)%mod;
21            
22        }
23        return cnt;
24    }
25};