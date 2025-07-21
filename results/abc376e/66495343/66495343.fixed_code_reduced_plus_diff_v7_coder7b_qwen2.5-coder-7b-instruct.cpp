#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pii> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first >> ab[i].second;
        }

        // Sort by A in descending order
        sort(ab.begin(), ab.end(), [&](const pii &a, const pii &b) {
            return a.first > b.first;
        });

        long long result = 0;
        long long sum_b = 0;
        priority_queue<long long> pq;

        for (int i = 0; i < k; ++i) {
            sum_b += ab[i].second;
            pq.push(-ab[i].second); // Using negative to simulate min heap
        }

        result = ab[k - 1].first * sum_b;

        for (int i = k; i < n; ++i) {
            sum_b -= pq.top();
            pq.pop();

            sum_b += ab[i].second;
            pq.push(-ab[i].second);

            result = min(result, ab[i].first * sum_b);
        }

        cout << result << '\n';
    }

    return 0;
}