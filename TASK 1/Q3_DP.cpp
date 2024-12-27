#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();

    vector<vector<int>> V(n + 1, vector<int>(capacity + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weights[i - 1] <= j) { // Item fit
                V[i][j] = max(values[i - 1] + V[i - 1][j - weights[i - 1]], V[i - 1][j]);
            } else { // Item doesn't fit
                V[i][j] = V[i - 1][j];
            }
        }
    }
    return {V[n][capacity], {}};
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int k,m;  // Maximum weight the truck can carry and Number of bags
        cin >> k >> m;

        vector<int> weights(m), values(m);
        for (int j = 0; j < m; ++j) {
            cin >> weights[j] >> values[j];
        }

        pair<int, vector<int>> result = knapsack(weights, values, k);

        cout << "Hey stupid robber, you can get " << result.first << "." ;
    }

    return 0;
}
