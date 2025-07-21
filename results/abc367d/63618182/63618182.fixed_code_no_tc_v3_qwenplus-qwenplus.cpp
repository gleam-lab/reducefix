#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 1); // Use ll for better handling of large sums
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 1);
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    map<ll, ll> count; // Map to store frequency of mod values
    ll ans = 0;
    
    // We want (prefix[i] - prefix[j]) % M == 0 => prefix[i] % M == prefix[j] % M
    // So we count how many times each mod has occurred
    count[0] = 1; // Include 0 as prefix[0] = 0

    for(int i = 1; i <= n; i++) {
        ll curr_mod = ((prefix[i] % M) + M) % M; // Ensure non-negative
        ans += count[curr_mod]; // Count previous indices with same mod
        count[curr_mod]++;
    }

    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}