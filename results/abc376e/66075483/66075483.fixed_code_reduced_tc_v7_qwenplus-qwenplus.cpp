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

        // Sort items by A value
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Min-heap to maintain top K B values
        priority_queue<int, vector<int>, greater<>> pq;

        int sum_b = 0;
        // Initialize with last K elements
        for (int i = N - 1; i >= N - K; --i) {
            pq.push(items[i].b);
            sum_b += items[i].b;
        }

        int result = items[N - 1].a * sum_b;

        // Slide window leftwards
        for (int i = N - K - 1; i >= 0; --i) {
            // Try to replace the smallest in heap if current is bigger
            if (!pq.empty() && items[i].b > pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].b);
                sum_b += items[i].b;
            }

            // Update answer with current A[i] and sum of B's
            if (pq.size() == K) {
                result = min(result, items[i].a * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}