#include "bits/stdc++.h"

using namespace std;
int main() {
       ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, w;
    cin>>t>>w;
        int n;
        cin >> n; 

        vector<int> depth(n), gold(n), time_required(n);
        for (int i = 0; i < n; i++) {
            cin >> depth[i] >> gold[i];
            time_required[i] = 3 * w * depth[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        vector<vector<bool>> taken(n, vector<bool>(t + 1, false));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (time_required[i - 1] <= j) {
                    int include_gold = gold[i - 1] + dp[i - 1][j - time_required[i - 1]];
                    int exclude_gold = dp[i - 1][j];
                    dp[i][j] = max(include_gold, exclude_gold);

                    if (include_gold > exclude_gold) {
                        taken[i - 1][j] = true;
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

      
        int ans = dp[n][t];
        vector<pair<int, int>> treasures;
        int time_left = t;
        for (int i = n - 1; i >= 0; i--) {
            if (taken[i][time_left]) {
                treasures.push_back({depth[i], gold[i]});
                time_left -= time_required[i];
            }
        }

        reverse(treasures.begin(), treasures.end());
        cout << ans << endl;
        cout << treasures.size() << endl;
        for (auto& treasure : treasures) {
            cout << treasure.first << " " << treasure.second << endl;
        }
        cout << endl;


    return 0;
}
