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
    
    vector<ll>prefix(n+1,0);
    for(int i=0; i<n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }
    
    map<int, int>mod_count;
    mod_count[0] = 1; // empty prefix case
    
    ll result = 0;
    for(int i=1; i<=n; i++){
        int current_mod = (prefix[i] % M + M) % M;
        result += mod_count[current_mod];
        mod_count[current_mod]++;
    }
    
    cout<<result;
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