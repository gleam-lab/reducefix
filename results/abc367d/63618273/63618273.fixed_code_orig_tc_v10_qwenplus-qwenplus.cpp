#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> prefix_sum(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    map<ll, ll> count_map;
    ll result = 0;
    
    // We want prefix_sum[j] % M == prefix_sum[i] % M => contributes to subarray [j+1..i]
    // So we track how many times each modulo has been seen before
    count_map[0] = 1;  // To include subarrays starting from index 0
    
    for (int i = 1; i <= n; ++i) {
        ll current_mod = (prefix_sum[i] % M + M) % M;  // ensure non-negative
        result += count_map[current_mod];
        count_map[current_mod]++;
    }

    cout << result << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}