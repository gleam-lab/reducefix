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

        // Use min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        int result = 1e18; // Initialize to large value

        for (int i = 0; i < N; ++i) {
            pq.push(items[i].b);
            sum_b += items[i].b;

            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                result = min(result, items[i].a * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}