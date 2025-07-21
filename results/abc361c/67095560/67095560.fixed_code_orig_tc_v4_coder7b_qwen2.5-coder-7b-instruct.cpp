#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<ll>
#define vvi vector<vi>

void solve() {
    ll n, k;
    cin >> n >> k;
    vi arr(n);
    for (auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());
    
    ll ans = LLONG_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, arr[k - i] - arr[i]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}