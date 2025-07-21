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

        // Min-heap to keep track of top K B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        int res = 1e18; // Large initial value

        // First K - 1 elements' B values (will not form a complete subset yet)
        for (int i = 0; i < K - 1; ++i) {
            sum_b += items[i].b;
            pq.push(items[i].b);
        }

        // Now consider each item from K-1 to N-1 as the max A in the subset
        for (int i = K - 1; i < N; ++i) {
            sum_b += items[i].b;
            pq.push(items[i].b);

            // Maintain only top K B values
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // The current item has the maximum A in the current subset
            res = min(res, items[i].a * sum_b);
        }

        cout << res << "\n";
    }

    return 0;
}