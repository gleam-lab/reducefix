#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 0; i < n - 1; ++i) cin >> vb[i];
    
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    for(int i = 0; i < n - 1; ++i) {
        if(vb[i] < va[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    if(va[n - 1] <= vb[n - 2]) cout << va[n - 1] << '\n';
    else cout << vb[n - 2] + 1 << '\n';
    
    return 0;
}