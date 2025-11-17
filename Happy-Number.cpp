class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        
        do {
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        } while (slow != fast);
        
        return slow == 1;
    }

private:
    int findSquare(int num) {
        int ans = 0;
        while (num > 0) {
            int digit = num % 10;
            ans += digit * digit;
            num /= 10;
        }
        return ans;
    }
};