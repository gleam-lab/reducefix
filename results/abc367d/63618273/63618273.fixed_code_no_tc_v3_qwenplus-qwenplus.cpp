#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> prefix(n + 2); // Use ll to avoid overflow
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    map<int, int> countMap;
    ll ans = 0;
    // We want prefix[j] % M == prefix[i] % M => sum from i+1 to j is divisible by M
    // So we need to count how many times each mod has been seen before
    countMap[0] = 1; // To account for prefix[0] = 0

    for (int i = 1; i <= n; i++) {
        int curr_mod = ((prefix[i] % M) + M) % M; // Ensure positive modulo
        ans += countMap[curr_mod]; // Count previous prefixes with same mod
        countMap[curr_mod]++;
    }

    cout << ans << endl;
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