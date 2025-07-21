#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

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
        prefix[i] = prefix[i - 1] + a[i];
    }

    ll ans = 0;
    map<ll, int> freq;
    for(int i = 0; i <= n; i++) {
        ll rem = (prefix[i] % M + M) % M;  // Normalize remainder to be positive
        ans += freq[rem]++;
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}