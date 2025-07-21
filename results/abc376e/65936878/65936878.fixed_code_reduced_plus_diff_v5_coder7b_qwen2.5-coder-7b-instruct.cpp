#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        int ans = LLONG_MAX;

        for(int i = 0; i < n; ++i) {
            pq.push(b[i]);
            sum_b += b[i];
            if(pq.size() > k) {
                sum_b -= pq.top();
                pq.pop();
            }
            if(i >= k - 1) {
                ans = min(ans, (a[i] * sum_b));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}