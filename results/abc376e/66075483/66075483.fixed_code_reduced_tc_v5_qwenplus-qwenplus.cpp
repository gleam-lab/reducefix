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

        // Sort by A value
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Use a min-heap to keep track of top K B values
        priority_queue<int, vector<int>, greater<int>> heap;
        int sum_b = 0;
        int res = 1e18; // A large number as initial result

        // First, try the first K elements
        for (int i = 0; i < K; ++i) {
            sum_b += items[i].b;
            heap.push(items[i].b);
        }
        res = items[K - 1].a * sum_b;

        // Try other combinations
        for (int i = K; i < N; ++i) {
            if (items[i].b > heap.top()) {
                sum_b -= heap.top();
                heap.pop();
                sum_b += items[i].b;
                heap.push(items[i].b);
                res = min(res, items[i].a * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}