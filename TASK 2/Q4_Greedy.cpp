#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


struct DSU {
    vector<int> parent, size;
    //disjoint set union
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    //find the parent of x
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    //merge if not already connected
    void unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return;
        if (size[rootU] > size[rootV]) swap(rootU, rootV);
        size[rootV] += size[rootU];
        size[rootU] = 0;
        parent[rootU] = rootV;
    }
    //check if having the same parent
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

struct Edge {
    int start, end, g, s;
    //used for comparing
    bool operator <(const Edge& other) const {
        return s < other.s;
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, g, s;
    cin >> n >> m >> g >> s;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].start >> edges[i].end >> edges[i].g >> edges[i].s;
    }

    sort(edges.begin(), edges.end(),  [](const Edge& a, const Edge& b) {
        return a.g < b.g;
    });

    long long totalMinCost = LLONG_MAX;
    vector<Edge> tempEdges;

    for (int mid = 0; mid < m; ++mid) {
        long long gold = edges[mid].g;
        tempEdges.push_back(edges[mid]);

        sort(tempEdges.begin(), tempEdges.end(), [](const Edge& a, const Edge& b) {
            return a.s < b.s;
        });

        long long silver = 0;
        DSU dsu(n);
        int numOfEdges = 0;
        vector<Edge> usedEdges;

        for (const auto& edge : tempEdges) {
            if (!dsu.connected(edge.start, edge.end)) {
                usedEdges.push_back(edge);
                dsu.unite(edge.start, edge.end);
                numOfEdges++;
                silver = edge.s;
            }
        }

        if (numOfEdges == n - 1) {
            totalMinCost = min(totalMinCost, gold * g + silver * s);
        }

        tempEdges = usedEdges;
    }
    if(totalMinCost == LLONG_MAX)
        cout<<-1;
    else
        cout<<totalMinCost;
    return 0;
}
