class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int ans = 0;

        vector<int> suffixMax(n);

        int leftMax = height[0];

        suffixMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        for(int i = 0; i < n; i++) {
            if(height[i] > leftMax) leftMax = height[i];
            if(height[i] < leftMax && height[i] < suffixMax[i]) {
                ans += min(leftMax, suffixMax[i]) - height[i];
            }
        }

        return ans;
    } 
};