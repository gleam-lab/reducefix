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

        // Sort items by A value ascending
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Min-heap to keep track of top K B values among first i elements
        priority_queue<int, vector<int>, greater<>> min_heap;
        int sum_b = 0;
        int result = numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            // Always include current item
            sum_b += items[i].b;
            min_heap.push(items[i].b);

            // Maintain only K elements in heap
            if (min_heap.size() > K) {
                sum_b -= min_heap.top();
                min_heap.pop();
            }

            // Once we have at least K elements, compute the cost
            if (min_heap.size() == K) {
                result = min(result, items[i].a * sum_b);
            }
        }

        cout << result << '\n';
    }

    return 0;
}