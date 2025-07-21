#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 1); // Use ll to prevent overflow
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    map<ll, ll> count;
    ll ans = 0;
    
    // We want (prefix[j] - prefix[i]) % M >= 0
    // Which is equivalent to prefix[j] % M == prefix[i] % M
    // So we count occurrences of each modulo of prefix sums

    count[0]++; // Handle prefix[0] = 0 explicitly to include subarrays starting at index 1
    for (int i = 1; i <= n; ++i) {
        ll rem = prefix[i] % M;
        ans += count[rem]; // All previous indices with same remainder
        count[rem]++;
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}