#include<algorithm>
class Solution {
public:
    double area_below(double mid, vector<vector<int>>& squares){
        double area = 0;
        for(int i = 0; i < squares.size(); i++){
            double bottom = squares[i][1];
            double len = squares[i][2];
            if(bottom + len <= mid){
                area += len * len;
            } else if(bottom <= mid){
                area += len * (mid - bottom);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0;
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i = 0; i < squares.size(); i++){
            int len = squares[i][2];
            total_area += (double)len * (double)len;
            minimum = min(minimum, squares[i][1]);
            maximum = max(maximum, squares[i][1] + len);
        }
        double target = total_area / 2;
        double low = minimum, high = maximum;
        double y=0;
        while(low < high){
            if(high - low < pow(10, -5)){
                break;
            }
            double mid = (low + high) / 2;
            if(area_below(mid, squares) < target){
                low = mid;
            }else{
                y = mid;
                high = mid;
            }
        }
        return y;
    }
};