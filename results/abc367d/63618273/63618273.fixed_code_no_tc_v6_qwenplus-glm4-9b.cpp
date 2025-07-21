#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int>a(n+10);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int>prefixSum(n+2);
    for(int i = 1; i <= n; i++){
        prefixSum[i+1] = (prefixSum[i] + a[i]) % mod;
    }
    map<int, int>mp;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int currentMod = (prefixSum[i] - prefixSum[1] + M) % M;
        ans = (ans + mp[currentMod]) % mod;
        mp[prefixSum[i]]++;
    }
    cout << ans;
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