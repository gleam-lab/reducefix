#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        // Sort B in descending order
        sort(b.begin(), b.end(), greater<int>());

        // Use a max-heap to keep track of the maximum A_i for the current sum of B_i
        priority_queue<P, vector<P>, greater<P>> pq;
        ll sumB = 0, ans = LLONG_MAX;

        // Initialize the heap with the first K elements
        for (int i = 0; i < k; ++i) {
            pq.push({-a[i], b[i]});
            sumB += b[i];
        }
        ans = min(ans, -pq.top().first * sumB);

        // Adjust the sum and max A_i by replacing elements from the end of B with the start
        for (int i = k; i < n; ++i) {
            sumB += b[i] - b[i - k];
            pq.push({-a[i], b[i]});
            sumB -= b[i - k];
            pq.pop();
            ans = min(ans, -pq.top().first * sumB);
        }

        cout << ans << '\n';
    }
    return 0;
}