#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] = (s[i - 1] + a[i]) % M;
    }

    map<ll, ll> mp;
    ll ans = 0;
    mp[0] = 1; // To handle subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        ans += mp[s[i]]++;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}