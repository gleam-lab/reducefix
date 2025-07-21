#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> PII;
const int N=2e5+10, mod=1e9+7;

void solve()
{
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n+1);
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefixSum(n+1, 0);
    for(int i=1; i<=n; ++i) {
        prefixSum[i] = (prefixSum[i-1] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;
    cnt[0] = 1;

    for(int i=1; i<=n; ++i) {
        ans += cnt[prefixSum[i]];
        cnt[prefixSum[i]]++;
    }

    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}