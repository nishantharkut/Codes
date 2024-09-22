#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

// Function to run Dijkstra's algorithm
vector<int> dijkstra(int n, int start, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            int newDist = dist[u] + w;
            if (dist[v] > newDist) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    return dist;
}

// Function to run Dijkstra's algorithm with horse effect (halving travel time after getting a horse)
vector<int> dijkstraWithHorse(int n, int start, const vector<vector<pair<int, int>>>& adj, const unordered_set<int>& horseVertices) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            // Check if we are at a horse vertex and halve the travel time
            int travelTime = (horseVertices.count(u) ? w / 2 : w);
            int newDist = dist[u] + travelTime;
            if (dist[v] > newDist) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    return dist;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        
        unordered_set<int> horseVertices;
        for (int i = 0; i < h; i++) {
            int horseVertex;
            cin >> horseVertex;
            horseVertices.insert(horseVertex);
        }
        
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        
        // Dijkstra for Marian (starting from vertex 1) and Robin (starting from vertex n)
        vector<int> marianDist = dijkstra(n, 1, adj);
        vector<int> robinDist = dijkstra(n, n, adj);
        
        // Dijkstra with horse effect
        vector<int> marianDistWithHorse = dijkstraWithHorse(n, 1, adj, horseVertices);
        vector<int> robinDistWithHorse = dijkstraWithHorse(n, n, adj, horseVertices);
        
        int earliestMeetingTime = INF;
        for (int i = 1; i <= n; i++) {
            // Calculate the minimum maximum time Marian and Robin can meet at vertex i
            int marianTime = min(marianDist[i], marianDistWithHorse[i]);
            int robinTime = min(robinDist[i], robinDistWithHorse[i]);
            earliestMeetingTime = min(earliestMeetingTime, max(marianTime, robinTime));
        }
        
        if (earliestMeetingTime == INF) {
            cout << -1 << endl;  // No meeting possible
        } else {
            cout << earliestMeetingTime << endl;  // Earliest meeting time
        }
    }
    return 0;
}
