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
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int}s(n+10);
    for(int i=0; i<n; i++){
        s[i+1]=s[i]+a[i];
    }
    map<int, int>mp;
    ll ans=0;
    ll L=s[n];
    for(int i=0; i<n; i++){
        // ä½¿ç¨LLONG_MAXæ­£è´æ°æ¨¡è¿ç®é®é¢
        ans += mp[LLONG_MAX - (L - s[i] + M) % M];
        // æ³¨ææ¨¡è¿ç®çç»æå¯è½ä¸º0ï¼æä»¬éè¦å¤ç
        ans += mp[s[i] % M]++;

        // æ´æ°mapï¼è®°å¾å¯¹æ¨¡è¿ç®ç»æåæ¬¡åæ¨¡
        mp[s[i] % M] = (mp[s[i] % M] + 1) % mod;
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