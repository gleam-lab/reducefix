#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        sum = (sum + a[i]) % m;
    }
    
    LL res = 0;
    unordered_map<int, int> prefix_count;
    prefix_count[0]++;
    
    for(int i = 0; i < n; ++i) {
        sum = (sum + a[i]) % m;
        int need = (sum * 2) % m;
        if(prefix_count.count(need)) {
            res = (res + prefix_count[need]) % MOD;
        }
        prefix_count[sum]++;
    }
    
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    
    return 0;
}