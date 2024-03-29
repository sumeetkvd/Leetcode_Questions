// Complexity

// Time:  O(n)

// Space: O(1)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int count = 10;  
        for (int k = 2, fk = 9; k <= n; ++k) {
            fk *= 10 - (k - 1);
            count += fk;
        }
        return count;  
    }
};
