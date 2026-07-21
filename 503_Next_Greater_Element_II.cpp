class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(2 * n);

        int k = 0;
        for(int i = 0; i < 2 * n; i++) {
            if(k == n) {
                k = k % n; 
            }
            temp[i] = nums[k++];
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n + i + 1; j++) {
                if(temp[j] > temp[i]) {
                    ans.push_back(temp[j]);
                    break;
                }
                if(j == n + i && temp[j] <= temp[i]) {
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};