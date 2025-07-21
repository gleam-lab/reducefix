#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    sort(a.rbegin(), a.rend()); // Sort in descending order
    sort(b.begin(), b.end());   // Sort in ascending order

    ll sum_b = 0;
    for(int i = 0; i < k; ++i) sum_b += b[i]; // Sum of smallest k elements in B

    ll ans = LLONG_MAX;
    for(int i = 0; i <= n-k; ++i) { // Iterate through valid starting indices for a subarray of size k
        ans = min(ans, (ll)a[i] * sum_b); // Calculate the product and update the answer
        if(i < n-k) sum_b -= b[i];       // Adjust the sum of B as we slide the window
        if(i+k < n) sum_b += b[i+k];     // Add the next element in B to the sum
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while(t--) solve();
}