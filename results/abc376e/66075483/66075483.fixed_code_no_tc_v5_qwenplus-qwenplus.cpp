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
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_b = 0;

        // Initialize the first K elements
        for (int i = 0; i < K; ++i) {
            sum_b += items[i].b;
            min_heap.push(items[i].b);
        }

        int result = items[K - 1].a * sum_b;

        // Try each possible max A_i from index K to N-1
        for (int i = K; i < N; ++i) {
            // If current item's B is larger than the smallest in heap, replace it
            if (items[i].b > min_heap.top()) {
                sum_b -= min_heap.top();
                min_heap.pop();
                sum_b += items[i].b;
                min_heap.push(items[i].b);
            }
            // Current max A is items[i].a
            result = min(result, items[i].a * sum_b);
        }

        cout << result << '\n';
    }

    return 0;
}