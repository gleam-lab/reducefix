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

        // Min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, greater<>> pq;

        int sum_b = 0;
        int result = 1e18;  // Large initial value for min comparison

        // First pass: select first K elements by B value
        // and pair with the max A in these K
        vector<pair<int, int>> indexed_A_B;
        for (int i = 0; i < N; ++i) {
            indexed_A_B.emplace_back(items[i].a, items[i].b);
        }

        // We'll keep a max heap of size K to always have the K smallest B's
        priority_queue<int> max_heap;  // Max heap to keep smallest K B's
        int sum_b_small = 0;

        for (int i = 0; i < N; ++i) {
            if (max_heap.size() < K) {
                max_heap.push(items[i].b);
                sum_b_small += items[i].b;
            } else if (items[i].b < max_heap.top()) {
                sum_b_small -= max_heap.top();
                max_heap.pop();
                max_heap.push(items[i].b);
                sum_b_small += items[i].b;
            }

            if (max_heap.size() == K) {
                result = min(result, items[i].a * sum_b_small);
            }
        }

        cout << result << "\n";
    }

    return 0;
}