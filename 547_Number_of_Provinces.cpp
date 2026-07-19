class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();

        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                ans++;
            }
        }

        return ans;        
    }
};