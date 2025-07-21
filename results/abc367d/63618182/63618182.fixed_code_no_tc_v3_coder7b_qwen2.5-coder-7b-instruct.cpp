#include<bits/stdc++.h>
using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n,M;
    cin>>n>>M;
    vector<ll>a(n+10),s(n+10);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        s[i]=(s[i-1]+a[i])%M;
    }
    map<ll, int>mp;
    mp[0]++; // Initialize with one count for remainder 0
    ll ans=0;
    for(int i=1; i<=n; i++){
        ans=(ans+mp[s[i]])%mod;
        mp[s[i]]++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}