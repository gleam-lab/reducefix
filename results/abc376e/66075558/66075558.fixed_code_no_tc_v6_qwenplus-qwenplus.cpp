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
    cin.tie(0);
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

        // Sort items by A value ascending
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Min-heap to store top K B values
        priority_queue<int, vector<int>, greater<>> pq;

        int sum_b = 0;
        int result = 1e18; // Initialize to a large number

        // Start from the largest A values and maintain a window of K elements
        for (int i = N - 1; i >= 0; --i) {
            sum_b += items[i].b;
            pq.push(items[i].b);

            // If we have more than K elements, remove the one with smallest B
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Once we have exactly K elements, update answer with current A as max A
            if (pq.size() == K) {
                result = min(result, items[i].a * sum_b);
            }
        }

        cout << result << '\n';
    }

    return 0;
}