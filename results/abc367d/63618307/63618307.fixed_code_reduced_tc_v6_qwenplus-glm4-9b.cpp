#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int>a(n+10), s(n+10);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s[0] = a[0];
    for(int i = 1; i < n; i++) {
        s[i] = (s[i-1] + a[i]) % mod; // Update prefix sum modulo
    }
    map<int, int> mp;
    ll ans = 0;
    ll L = 0;
    for(int i = 0; i < n; i++) {
        ll mod_value = (s[i] - L + M) % M;
        ans = (ans + mp[mod_value]) % mod;
        mp[s[i] % M]++;
        L = (L + s[i]) % mod;
    }
    cout << ans << endl;
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