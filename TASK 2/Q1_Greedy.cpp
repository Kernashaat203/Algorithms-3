#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int findContentChildren(vector<int> g, vector<int>s){
    int count=0;
    int i=0,j=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while(i<g.size()&& j<s.size()){
        if(s[j]>=g[i]){
            count++;
            i++,j++;
        }
        else{
            j++;
        }
    }
    return count;
}
int main() {
    vector<int>g1={1,2,3};
    vector<int>s1={1,1};
    cout<<findContentChildren(g1,s1)<<endl;

    vector<int>g2={1,2};
    vector<int>s2={1,2,3};
    cout<<findContentChildren(g2,s2);

    return 0;
}
