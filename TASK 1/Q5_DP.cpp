#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Longest Increasing Subsequence

int main(){
    int n;
    cin>>n;
    vector<int>v(n);

    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    vector<int>LIS(n , 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    int result = *max_element(LIS.begin(), LIS.end());
    cout << result ;

    return 0;
}