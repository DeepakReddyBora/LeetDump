class Solution {
public:
    int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;

            b = a % b;
            a = temp;
        }

        return a;
    }
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];

        int ans;

        for(int num : nums) {
            if(num > largest) largest = num;
            if(num < smallest) smallest = num;
        }

        return gcd(largest, smallest);
    }
};