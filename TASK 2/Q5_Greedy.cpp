#include "bits/stdc++.h"

using namespace std;


const int MAX_NODES = 100000;
vector<int> components[MAX_NODES];
int parent[MAX_NODES];

void initialize_set(int node) {
    components[node] = vector<int>(1, node);
    parent[node] = node;
}

int find_parent(int node) {
    return parent[node];
}

void merge_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (components[a].size() < components[b].size()) {
            swap(a, b);
        }
        while (!components[b].empty()) {
            int v = components[b].back();
            components[b].pop_back();
            parent[v] = a;
            components[a].push_back(v);
        }
    }
}

vector<vector<pair<int, int>>> graph; 
vector<int> bit_count(200100, 0);
vector<int> visited;
int total_nodes, total_edges;

int depth_first_search(int current_node) {
    visited[current_node] = 1;
    int subtree_size = 1;

    for (auto& neighbor : graph[current_node]) {  
        if (visited[neighbor.first]) continue;

        long long subtree_count = depth_first_search(neighbor.first);
        subtree_size += subtree_count;

        long long weight_combinations = subtree_count * (total_nodes - subtree_count);
        int current_edge = neighbor.second;

        while (weight_combinations > 0) {
            if (weight_combinations % 2) bit_count[current_edge]++;
            weight_combinations /= 2;
            if (bit_count[current_edge] == 2) {
                bit_count[current_edge] = 0;
                weight_combinations++;
            }
            current_edge++;
        }
    }
    return subtree_size;
}

int main() {
    vector<pair<int, pair<int, int>>> edges;

    cin >> total_nodes >> total_edges;

    for (int i = 0; i < total_edges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a - 1, b - 1}});
    }
    graph.resize(total_nodes);

    
    for (int i = 0; i < total_nodes; i++) {
        initialize_set(i);
    }

    sort(edges.begin(), edges.end());

    for (auto& edge : edges) {
        int a = edge.second.first;
        int b = edge.second.second;
        int x = find_parent(a);
        int y = find_parent(b);

        if (x == y) continue;  

        int c = edge.first;
        graph[a].push_back({b, c}); 
        graph[b].push_back({a, c}); 
        merge_sets(a, b);  
    }


    visited = vector<int>(total_nodes, 0);
    depth_first_search(0);


    while (bit_count.back() == 0) {
        bit_count.pop_back();
    }
    reverse(bit_count.begin(), bit_count.end());

  
    for (auto x : bit_count) {
        cout<<x;
    }

    return 0;
}
