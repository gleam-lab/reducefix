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
    ll total=s[n];
    ll target=total%M;
    if(target<0) target+=M;
    
    map<ll, ll>mp;
    mp[0]=1;
    ll ans=0;
    for(int i=1; i<=n; i++){
        ll current=s[i]%M;
        if(current<0) current+=M;
        ll needed=(current-target+M)%M;
        ans+=mp[needed];
        mp[current]++;
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