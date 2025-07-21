#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    // Sort by A_i in ascending order
    sort(ab.begin(), ab.end());

    // Edge case: only one element needed
    if (k == 1) {
        ll ans = INF;
        for (int i = 0; i < n; ++i)
            ans = min(ans, ab[i].first * ab[i].second);
        cout << ans << '\n';
        return;
    }

    // Max heap to keep the smallest (k-1) B_i values
    priority_queue<ll> max_heap;
    ll sum = 0;

    // Initialize with the first k-1 elements' B values
    for (int i = 0; i < k - 1; ++i) {
        sum += ab[i].second;
        max_heap.push(ab[i].second);
    }

    ll res = INF;

    // Try every element from index k-1 to n-1 as the "max A_i"
    for (int i = k - 1; i < n; ++i) {
        ll current_a = ab[i].first;
        ll current_b = ab[i].second;

        // Total sum of B values + current_b
        ll total_sum = sum + current_b;
        res = min(res, current_a * total_sum);

        // Maintain the smallest k-1 B values in the heap
        if (!max_heap.empty() && max_heap.top() > current_b) {
            sum -= max_heap.top();
            sum += current_b;
            max_heap.pop();
            max_heap.push(current_b);
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}