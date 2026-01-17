class Solution {
public:
    int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        vFences.push_back(n);
        hFences.push_back(m);
        sort(vFences.begin(),vFences.end());
        sort(hFences.begin(),hFences.end());

        vector<int> st_v;
        vector<int> st_h;

        vector<int> prev;

        int prevFence = 1;

        for(int hFence : hFences){
            int diff = hFence-prevFence;
            vector<int> curr;
            
            st_h.push_back(diff);
            curr.push_back(diff);

            for(int i : prev){
                st_h.push_back(i+diff);
                curr.push_back(i+diff);
            }
            prev = curr;
            prevFence = hFence;
        } 

        prev.clear();
        prevFence = 1;

        for(int vFence : vFences){
            int diff = vFence-prevFence;
            vector<int> curr;
            
            st_v.push_back(diff);
            curr.push_back(diff);

            for(int i : prev){
                st_v.push_back(i+diff);
                curr.push_back(i+diff);
            }
            prev = curr;
            prevFence = vFence;
        }   
        
        sort(st_h.begin(), st_h.end());
        sort(st_v.begin(), st_v.end());

        int i=st_h.size()-1;
        int j=st_v.size()-1;
        while(i>=0 && j>=0){
            if(st_h[i] == st_v[j]){
                return (1LL*st_h[i]*st_v[j])%MOD;
            }else if(st_h[i] > st_v[j]){
                i--;
            }else{
                j--;
            }
        }
        return -1;
    }
};