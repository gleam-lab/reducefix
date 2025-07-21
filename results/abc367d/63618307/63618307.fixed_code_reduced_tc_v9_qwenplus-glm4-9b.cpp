#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n,M;
    cin>>n>>M;
    vector<int>a(n+1);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int>s(n+1);
    for(int i=1; i<=n; i++){
        s[i] = (s[i-1] + a[i-1]) % mod;
    }
    map<int, int>mp;
    ll ans=0;
    for(int i=0; i<=n; i++){
        if (i == 0) {
            ans += a[i];
        } else {
            int k = (s[i] - a[i] + mod) % mod;
            ans += mp[k] + (i - mp[k] - 1);
            mp[s[i] % mod]++;
        }
    }
    cout<<ans;
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