#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    VI a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    // Pair up elements of A and B
    vector<pair<int, int>> ab(n);
    for(int i = 0; i < n; ++i) ab[i] = {a[i], b[i]};
    
    // Sort based on A values
    sort(ab.begin(), ab.end());

    // Initialize variables
    ll ans = LLONG_MAX;
    ll current_sum_b = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap for B values

    // First window of size K
    for(int i = 0; i < k; ++i) {
        pq.push(ab[i].second);
        current_sum_b += ab[i].second;
    }

    // Calculate initial answer
    ans = min(ans, (ll)ab[k-1].first * current_sum_b);

    // Sliding window
    for(int i = k; i < n; ++i) {
        // Remove smallest element from the previous window
        current_sum_b -= pq.top();
        pq.pop();

        // Add new element to the window
        pq.push(ab[i].second);
        current_sum_b += ab[i].second;

        // Update answer with the current window
        ans = min(ans, (ll)ab[i].first * current_sum_b);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}