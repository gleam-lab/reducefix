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

        // Sort items by A value ascending
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        // Min-heap to maintain top K largest B values seen so far
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int res = 1e18;  // large initial value

        // Try each item as the max A in the subset
        for (int i = 0; i < N; ++i) {
            // Always include current item
            pq.push(items[i].b);
            sum_b += items[i].b;

            // If we have more than K items, remove the smallest B
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Once we have K items, calculate cost
            if (pq.size() == K) {
                res = min(res, items[i].a * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}