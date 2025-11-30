1class Solution {
2public:
3    int minSubarray(vector<int>& nums, int p) {
4        int remainder=0;
5        for(int& num : nums){
6            remainder=(remainder+num)%p;
7        }
8        if(remainder==0){
9            return 0;
10        }
11        unordered_map<int, int> modIndexMap;
12        modIndexMap[0]=-1;
13        int n=nums.size();
14        int minLength=n;
15        int currentSum=0;
16
17        for(int i=0;i<n;++i){
18            currentSum=(currentSum+nums[i])%p;
19            int target=(currentSum-remainder+p)%p;
20            if(modIndexMap.count(target)){
21                minLength=min(minLength,i-modIndexMap[target]);
22            }
23            modIndexMap[currentSum]=i;
24        }
25        return minLength==n?-1:minLength;
26    }
27};