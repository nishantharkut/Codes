#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, const vector<vector<int>>& adj, const vector<long long>& a, int c, vector<vector<long long>>& dp) {
    dp[u][0] = 0;       // Case when camp u is not strengthened
    dp[u][1] = a[u];    // Case when camp u is strengthened, starting with its own gold
    
    for (int v : adj[u]) {
        if (v == parent) continue; // Skip the parent node
        
        // Perform DFS for child node v
        dfs(v, u, adj, a, c, dp);
        
        // If camp u is not strengthened, we take the maximum of either strengthening or not strengthening v
        dp[u][0] += max(dp[v][0], dp[v][1]);
        
        // If camp u is strengthened, we can only add the case where v is not strengthened (because strengthening u reduces v's gold)
        dp[u][1] += dp[v][0] - c; // Deduct c from v when u is strengthened
    }
    
    // Ensure that dp[u][1] is not negative because it doesn't make sense to have negative gold in a camp.
    dp[u][1] = max(dp[u][1], 0LL);
}

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n, c;
        cin >> n >> c; // Read number of camps and gold deduction
        
        vector<long long> a(n); // Store gold values of each camp
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<int>> adj(n); // Adjacency list for the camps (tree structure)
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v; // Read the edges between camps
            adj[u - 1].push_back(v - 1); // Convert to 0-based indexing
            adj[v - 1].push_back(u - 1); // Add undirected edge
        }
        
        // DP table: dp[u][0] = max gold if u is not strengthened, dp[u][1] = max gold if u is strengthened
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        
        // Start DFS from the root camp (node 0)
        dfs(0, -1, adj, a, c, dp);
        
        // The result is the maximum between not strengthening and strengthening the root
        cout << max(dp[0][0], dp[0][1]) << endl;
    }
    return 0;
}
