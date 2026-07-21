class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0) return grid;

        int m = grid.size();
        int n = grid[0].size();

        k = k % (m * n);

        vector<int> temp;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());

        int a = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = temp[a++];
            }
        }

        return grid;
    }
};