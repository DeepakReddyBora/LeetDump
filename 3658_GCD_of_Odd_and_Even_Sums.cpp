class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;

        return gcd(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        int temp = n;

        int oddStart = 1;
        int oddSum = 1;
        int evenStart = 2;
        int evenSum = 2;

        while(temp != 1) {
            oddStart += 2;
            oddSum += oddStart;

            evenStart += 2;
            evenSum += evenStart;

            temp--;
        }

        return gcd(oddSum, evenSum);
    }
};