#include "bits/stdc++.h"

using namespace std;


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> g[n];
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) {
                return true;
            }

            for (int neighbor : g[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);  
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source, destination;
    cin >> source >> destination;
    validPath(n,graph,source,destination);
    return 0;
}
