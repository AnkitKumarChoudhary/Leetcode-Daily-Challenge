class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st1;
        unordered_set<int> st2;

        for(auto num : arr1){           
            while(num > 0){
                st1.insert(num);
                num /= 10;
            }
        }

        for(auto num : arr2){           
            while(num > 0){
                st2.insert(num);
                num /= 10;
            }
        }   

        int ans = 0;
        for(auto it : st1){
            if(st2.find(it) != st2.end()){
                int cnt = 0,num = it;
                while(num > 0){
                    cnt++;
                    num /= 10;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;

    }
};