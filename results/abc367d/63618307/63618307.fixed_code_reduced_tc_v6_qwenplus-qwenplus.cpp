#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;
    cnt[0] = 1; // To handle subarrays starting from index 0
    
    for (int i = 1; i <= n; i++) {
        // Count how many times this remainder has been seen before
        ans += cnt[prefix_sum[i]]++;
    }
    
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}