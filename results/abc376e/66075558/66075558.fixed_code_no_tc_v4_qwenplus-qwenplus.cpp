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

        // Sort items by A value in ascending order
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Min-heap to keep track of top K B values
        priority_queue<int, vector<int>, greater<>> min_heap;
        int sum_b = 0;
        int res = 1e18; // Large initial value

        // Start from the end and maintain a window of K elements
        for (int i = N - 1; i >= 0; --i) {
            sum_b += items[i].b;
            min_heap.push(items[i].b);

            if (min_heap.size() > K) {
                sum_b -= min_heap.top();
                min_heap.pop();
            }

            if (min_heap.size() == K) {
                res = min(res, items[i].a * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}