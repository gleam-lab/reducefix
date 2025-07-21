#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n), b(n);
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (long long i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Pair up A and B to maintain order
        vector<pii> ab(n);
        for (long long i = 0; i < n; ++i) {
            ab[i] = {a[i], b[i]};
        }
        
        // Sort by A in descending order
        sort(ab.begin(), ab.end(), [](const pii &p1, const pii &p2) {
            return p1.first > p2.first;
        });

        // Min-heap to store the sum of B_i
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum_b = 0;
        for (long long i = 0; i < k; ++i) {
            pq.push(ab[i].second);
            sum_b += ab[i].second;
        }

        long long ans = sum_b * ab[k - 1].first;

        // Iterate through the remaining elements to find the minimum value
        for (long long i = k; i < n; ++i) {
            sum_b += ab[i].second - pq.top();
            pq.pop();
            pq.push(ab[i].second);
            ans = min(ans, sum_b * ab[i].first);
        }

        cout << ans << '\n';
    }

    return 0;
}