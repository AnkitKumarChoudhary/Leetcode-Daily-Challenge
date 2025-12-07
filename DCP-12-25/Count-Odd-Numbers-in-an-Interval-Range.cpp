1class Solution {
2public:
3    int countOdds(int low, int high) {
4        return (high+(high&1)-low+(low&1))>>1;
5    }
6};