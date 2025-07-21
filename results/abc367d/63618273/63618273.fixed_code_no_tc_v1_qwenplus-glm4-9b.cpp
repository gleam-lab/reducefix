#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10, mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+10);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> prefix_sums(n+2);
    for(int i = 1; i <= n; i++){
        prefix_sums[i+1] = (prefix_sums[i] + a[i]) % mod;
    }
    map<int, int> mp;
    ll ans = 0;
    ll L = prefix_sums[n+1];
    for(int i = 1; i <= n; i++){
        ans = (ans + mp[(prefix_sums[i] - L + mod) % mod]) % mod;
        mp[prefix_sums[i] % mod]++;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}