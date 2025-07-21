#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> s(n+1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    map<int, int> mp;
    ll ans = 0;
    ll L = s[n];
    
    // Iterate from right to left to use the map efficiently
    for(int i = n; i >= 1; i--){
        // Find the remainder of the difference L - s[i] when divided by M
        int diff_mod = (L - s[i]) % M;
        if (diff_mod < 0) diff_mod += M;
        // Add the count of this remainder in the map to the answer
        ans += mp[diff_mod];
        // Increment the count of the current s[i] % M in the map
        mp[s[i] % M]++;
    }
    
    cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}