#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n,M;
    cin>>n>>M;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<ll>prefix(n+1, 0);
    for(int i=0; i<n; i++){
        prefix[i+1] = (prefix[i] + a[i]) % mod;
    }
    
    map<ll, int>mp;
    ll ans=0;
    mp[0]++;
    for(int i=0; i<n; i++){
        int rem = (prefix[i+1] * M / n) % mod;
        ll target = (prefix[i+1] - rem + mod) % mod;
        ans = (ans + mp[target]) % mod;
        mp[target]++;
    }
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}