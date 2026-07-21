class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        int m = nums2.size();

        vector<int> temp(m, -1);

        for(int i = m - 1; i >= 0; i--) {
            mp[nums2[i]] = i;
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(!st.empty()) {
                mp[nums2[i]] = st.top();
            }
            else if(st.empty()) {
                mp[nums2[i]] = -1;
            }
           
            st.push(nums2[i]); 
        }

        int n = nums1.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = mp[nums1[i]];
        }
        
        return ans;
    }
};