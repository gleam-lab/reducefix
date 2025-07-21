#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>; // Pair to store A[i] and B[i]

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Pair A[i] with B[i]
        vector<P> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {a[i], b[i]};
        }

        // Sort pairs to start from the largest A[i]
        sort(pairs.rbegin(), pairs.rend());

        // Priority queue to maintain the sum of B[i] with the smallest A[i]
        priority_queue<ll, vector<ll>, greater<ll>> min_heap;
        ll sumB = 0;

        // Initialize the heap with the first k elements
        for (int i = 0; i < k; ++i) {
            min_heap.push(b[i]);
            sumB += b[i];
        }

        // Calculate the initial answer
        ll ans = min_heap.top() * sumB;

        // Iterate over the rest of the elements
        for (int i = k; i < n; ++i) {
            sumB += min_heap.top() - min_heap.push(b[i]);
            ans = min(ans, min_heap.top() * sumB);
        }

        cout << ans << '\n';
    }
    return 0;
}