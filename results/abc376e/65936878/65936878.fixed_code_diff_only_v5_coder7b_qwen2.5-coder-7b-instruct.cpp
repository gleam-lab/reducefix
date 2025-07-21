#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        for(int i=0; i<n; ++i) cin >> b[i];

        // Sort indices based on A values in descending order
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){ return a[i] > a[j]; });

        // Priority queue to keep track of smallest B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        for(int i=0; i<k; ++i) {
            pq.push(b[idx[i]]);
            sum_b += b[idx[i]];
        }

        int ans = LLONG_MAX;
        for(int i=k; i<n; ++i) {
            int current_max_a = a[idx[i-k]];
            int current_min_b = pq.top();
            pq.pop();
            pq.push(b[idx[i]]);

            ans = min(ans, static_cast<long long>(current_max_a * (sum_b - current_min_b + b[idx[i]])));
        }

        // Handle the case when we only have one element left in the subset
        int last_element_a = a[idx[n-k]];
        int last_element_b = pq.top();
        ans = min(ans, static_cast<long long>(last_element_a * (sum_b - last_element_b)));

        cout << ans << '\n';
    }
    return 0;
}