#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10, mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+10);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> s(n+10);
    s[0] = 0; // Initialize s[0] to 0 for correct summation
    for(int i = 0; i < n; i++){
        s[i + 1] = (s[i] + a[i]) % mod; // Update s[i+1] and take modulo
    }
    map<int, int> mp;
    ll ans = 0;
    int L = s[n]; // Store last value of s for modulo calculation
    for(int i = n; i >= 0; i--){ // Traverse from the end to start
        ans = (ans + mp[(s[i] - L + mod) % mod]) % mod; // Adjust for modulo and use the map
        ans = (ans + mp[s[i] % mod]) % mod; // Add current modulo frequency
        mp[s[i] % mod]++; // Increment the frequency of the current modulo
        L = s[i]; // Update L to current value
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}