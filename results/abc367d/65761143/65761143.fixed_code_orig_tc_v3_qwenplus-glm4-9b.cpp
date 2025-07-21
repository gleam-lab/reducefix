#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> prefixSum(n);
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        prefixSum[i] = sum % m;
    }

    map<int, int> count;
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += count[prefixSum[i]];
        count[prefixSum[i]]++;
    }
    
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}