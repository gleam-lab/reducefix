#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define vi vector<ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (ll &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    
    // The optimal strategy is to remove the smallest k/2 elements and the largest k/2 elements
    // This ensures that the difference between the maximum and minimum of the remaining elements is minimized
    
    ll min_val = a[k / 2] - a[(n - k) / 2];
    
    cout << min_val << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}