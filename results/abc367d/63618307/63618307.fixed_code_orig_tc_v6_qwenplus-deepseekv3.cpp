#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    map<ll, ll> mp;
    mp[0] = 1; // To account for subarrays starting from the first element
    ll ans = 0;
    
    for(int i = 1; i <= n; i++){
        ll mod_val = (prefix[i] % M + M) % M;
        ans += mp[mod_val];
        mp[mod_val]++;
    }
    
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}