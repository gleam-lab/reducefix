#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        // Sort arrays
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // Min-heap to store the sum of elements outside the current window
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum_outside = 0;
        for (int i = 0; i < n; ++i) {
            sum_outside += B[i];
            pq.push(B[i]);
            if (pq.size() > k) {
                sum_outside -= pq.top();
                pq.pop();
            }
        }

        // Initial product with the first K elements
        ll ans = A[n - 1] * sum_outside;

        // Slide the window across the array
        for (int i = n - 2; i >= 0; --i) {
            sum_outside += B[i] - B[i + k];
            pq.push(B[i]);
            pq.pop();
            ans = min(ans, A[i] * sum_outside);
        }

        cout << ans << '\n';
    }

    return 0;
}