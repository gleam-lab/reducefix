#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Item {
    int a, b;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<Item> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].a;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].b;
        }

        // Sort by A value ascending
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Use min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int res = 1e18; // large number as initial result

        // First K-1 elements (we'll add one more later)
        for (int i = 0; i < K - 1; ++i) {
            pq.push(items[i].b);
            sum_b += items[i].b;
        }

        // Try each possible max A_i from position K-1 onwards
        for (int i = K - 1; i < N; ++i) {
            pq.push(items[i].b);
            sum_b += items[i].b;

            // Maintain heap size K
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Current max A is items[i].a
            res = min(res, items[i].a * sum_b);
        }

        cout << res << '\n';
    }

    return 0;
}