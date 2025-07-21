#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n,M;
    cin>>n>>M;
    vector<int>a(n+10);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    vector<int>s(n+10);
    ll sum = 0;
    for(int i=1; i<=n; i++){
        sum += a[i];
        s[i] = (s[i-1] + a[i]) % mod;
    }
    map<int, int>mp;
    ll ans=0;
    for(int i=0; i<n; i++){
        ans = (ans + mp[(s[i] - s[n] + mod) % mod]) % mod;
        ans = (ans + mp[s[i] % mod]) % mod;
        mp[s[i] % mod]++;
        mp[(s[i] - s[n] + mod) % mod]--;
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}