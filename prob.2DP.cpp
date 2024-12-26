#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int MOD = 1000000007;

int main() {
    string s;
    cout<<"Enter string: ";
    cin >> s;
    int k = s.length();
    for (char c : s) {
        if (c == 'm' || c == 'w') {
            cout << "The output is: "<<0 << endl;
            return 0;
        }
    }
    vector<long long> BottomUp(k + 1, 0);
    BottomUp[0] = 1;
    for (int i = 1; i <= k; ++i) {
        BottomUp[i] = BottomUp[i-1];
        if (i >= 2 && s[i-1] == 'u' && s[i-2] == 'u') {
            BottomUp[i] = (BottomUp[i] + BottomUp[i-2]) % MOD;
        }
        if (i >= 2 && s[i-1] == 'n' && s[i-2] == 'n') {
            BottomUp[i] = (BottomUp[i] + BottomUp[i-2]) % MOD;
        }
    }
    cout<<"The output is: "<<BottomUp[k] << endl;

    return 0;
}
