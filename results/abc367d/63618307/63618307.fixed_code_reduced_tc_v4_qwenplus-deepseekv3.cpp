#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    map<ll, ll> freq;
    ll total = prefix[n];
    ll ans = 0;
    
    for (int i = 0; i <= n; i++) {
        // Calculate the desired remainder
        ll desired = (prefix[i] - total % M + M) % M;
        ans += freq[desired];
        
        // Count current prefix mod M
        freq[prefix[i] % M]++;
    }
    
    cout << ans << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}