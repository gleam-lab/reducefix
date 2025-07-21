#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 10);  // Use ll to prevent overflow
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<ll> s(n + 10);  // Prefix sum array as ll
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
    }

    map<ll, ll> mp;  // Use ll for key and count to avoid overflow
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll rem = s[i] % M;
        if(rem < 0) rem += M;  // Ensure non-negative remainder

        // Count how many prefix sums have the same remainder
        ans += mp[rem]++;
    }

    // Add all counts because each prefix sum itself can be a subarray starting from index 0
    for(auto &p : mp){
        ans += p.second;
    }

    cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}