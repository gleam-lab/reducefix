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
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<ll>s(n+1);
    s[0] = 0;
    for(int i=0; i<n; i++)
        s[i+1] = (s[i] + a[i]) % mod;
    map<ll, int>mp;
    ll ans=0;
    mp[0]++;
    for(int i=0; i<n; i++)
    {
        ans += mp[(s[i] * M - s[n] + mod) % mod];
        ans %= mod;
        mp[s[i]]++;
    }
    cout<<(ans + mod) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}