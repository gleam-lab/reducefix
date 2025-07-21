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
    vector<ll>s(n+10);
    for(int i=1; i<=n; i++){
        s[i]=s[i-1]+a[i];
    }
    map<int, int>mp;
    mp[0] = 1; // Important: empty prefix sum
    ll ans=0;
    for(int i=1; i<=n; i++){
        int rem = (s[i] % M + M) % M;
        ans += mp[rem];
        mp[rem]++;
    }
    cout<<ans;
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