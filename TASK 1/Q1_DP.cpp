#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDifference(vector<int>& coins) {
    int sum = 0;
    for(int i=0;i<coins.size();i++)
        sum+=coins[i];
    int target = sum/2;

    vector<bool> dp(target + 1, false);
    dp[0]=true;
    for (int coin : coins) {
        for (int j=target;j >= coin;j--) {
            dp[j]=dp[j] || dp[j - coin];
        }
    }
    for (int j = target; j >= 0; --j) {
        if (dp[j]) {
            int s1=j;
            int s2=sum-s1;
            return abs(s2-s1);
        }
    }
    return sum;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> coins(n);
        for (int i=0; i<n; i++) {
            cin>>coins[i];
        }
        cout<<minDifference(coins)<<endl;
    }
    return 0;
}
