#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& items_weight, vector<int>& items_value, int total_capacity) {
    int n = items_weight.size();

    //first all values equal 0
    vector<vector<int>> DP(n + 1, vector<int>(total_capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total_capacity; j++) {
            //if the current item can be added or not
            if (items_weight[i - 1] <= j) {
                //we can tak  or leave the item based on which is maximum
                DP[i][j] = max(items_value[i - 1] + DP[i - 1][j - items_weight[i - 1]], DP[i - 1][j]);

            } else {
                //will not take the item
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    return DP[n][total_capacity];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k,m;
        cin>>k>>m;
        vector<int> w(m);
        vector<int>v(m);
        for (int j = 0; j < m; ++j) {
            cin >> w[j] >> v[j];
        }
        int answer = knapsack(w, v, k);
        cout << "Hey stupid robber, you can get " << answer << "." <<'\n';
    }
    return 0;
}
