#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 2);  // Use ll to avoid overflow
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 2);
    for(int i = 1; i <= n; i++) {
        prefix[i] = (prefix[i - 1] + a[i]) % M;
    }

    map<ll, ll> count;
    count[0] = 1;  // Handle subarrays starting from index 0
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += count[prefix[i]]++;
    }

    cout << ans << "\n";
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