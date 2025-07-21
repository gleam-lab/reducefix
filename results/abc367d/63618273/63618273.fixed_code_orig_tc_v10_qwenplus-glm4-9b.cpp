#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n, M;
    cin>>n>>M;
    vector<int>a(n+10);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    vector<int>s(n+10);
    for(int i=1; i<=n; i++){
        s[i+1] = (s[i] + a[i]) % mod; // Take modulo M of the prefix sum
    }
    map<int, int>mp;
    ll ans=0;
    ll L = s[1]; // Initialize L with the first prefix sum
    for(int i=1; i<=n; i++){
        // Increment ans by the count of (s[i] - L + mod) % mod in the map
        ans += mp[(s[i] - L + mod) % mod];
        // Increment the count of s[i] % mod in the map
        mp[s[i] % mod]++;
        // Update L to the current prefix sum
        L = s[i];
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