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
    
    vector<int> s(n+1);
    ll current_sum = 0;
    for(int i=0; i<n; i++){
        current_sum = (current_sum + a[i]) % mod;
        s[i+1] = current_sum;
    }
    
    map<int, int> mp;
    ll ans = 0;
    ll total_sum = s[n];
    
    for(int i=0; i<=n; i++){
        int remainder = (i < n) ? (s[i] % mod) : total_sum % mod;
        if(remainder >= M){
            continue; // Skip if remainder is 0 or greater than M
        }
        
        ans += mp[M - remainder];
        mp[remainder]++;
    }
    
    cout << ans % mod << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}