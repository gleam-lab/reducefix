#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Sort A in descending order
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end());

        // Priority queue to keep track of the largest K-1 elements of B
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;
        for (int i = 0; i < k - 1; ++i) {
            pq.push(b[i]);
            sum += b[i];
        }

        ll ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, a[i] * (sum + b[i]));
            if (!pq.empty()) {
                sum -= pq.top();
                pq.pop();
                pq.push(b[i]);
                sum += b[i];
            } else break;
        }

        cout << ans << '\n';
    }

    return 0;
}