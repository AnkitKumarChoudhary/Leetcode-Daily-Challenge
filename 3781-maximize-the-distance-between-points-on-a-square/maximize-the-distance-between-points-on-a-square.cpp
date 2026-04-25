class Solution {
public:

    long long getPerimeterPos(int x, int y, int side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 2LL*side + (side - x);
        return 3LL*side + (side - y); 
    }

    bool isPossible(int k, long long perimeter, int d, vector<long long> &dup) {
        int n = dup.size() / 2; 

        vector<int> next(2*n);
        int j = 0;

        for (int i = 0; i < 2*n; i++) {
            while (j < 2*n && dup[j] < dup[i] + d) j++;
            next[i] = j;
        }

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            int idx = i;
            while (cnt < k) {
                idx = next[idx];
                if (idx >= i + n) break;
                cnt++;
            }

            if (cnt == k && dup[i] + perimeter >= dup[idx] + d) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        pos.reserve(points.size());
        long long perimeter = 4LL*side;

        for (auto& p : points) {
            pos.push_back(getPerimeterPos(p[0], p[1], side));
        }

        sort(pos.begin(), pos.end());
        int n = pos.size();
        vector<long long> dup(2*n); 

        for (int i = 0; i < n; i++) {
            dup[i] = pos[i];
            dup[i + n] = pos[i] + perimeter;
        }

        int low = 0, high = perimeter / k; 
        
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(k, perimeter, mid, dup)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};