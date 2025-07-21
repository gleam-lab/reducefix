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

        // Sort by A ascending
        sort(items.begin(), items.end(), [](const Item &x, const Item &y) {
            return x.a < y.a;
        });

        // Min-heap to maintain top K smallest B values
        priority_queue<int> max_heap;  // max heap for B values (to keep smallest K)
        int sum_b = 0;
        int res = 1e18;  // large initial value

        for (int i = 0; i < N; ++i) {
            // Try including items[0..i] as the max A_i in subset S
            // We need to pick K elements from items[0..i]
            if (K <= i + 1) {
                max_heap.push(items[i].b);
                sum_b += items[i].b;

                if (max_heap.size() > K) {
                    sum_b -= max_heap.top();
                    max_heap.pop();
                }

                if (max_heap.size() == K) {
                    res = min(res, items[i].a * sum_b);
                }
            } else {
                max_heap.push(items[i].b);
                sum_b += items[i].b;
            }
        }

        cout << res << "\n";
    }

    return 0;
}