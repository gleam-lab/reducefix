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

        // Min-heap to keep track of top K B values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int min_result = 1e18;  // Large enough initial value

        // First K-1 elements from the end (largest A values)
        for (int i = N - 1; i >= 1; --i) {
            pq.push(items[i].b);
            sum_b += items[i].b;

            if (pq.size() > K - 1) {
                sum_b -= pq.top();
                pq.pop();
            }

            // We can now consider the subset with max A being items[i-1].a
            if (pq.size() == K - 1) {
                int current_max_a = items[i - 1].a;
                int total = sum_b + items[i - 1].b;
                min_result = min(min_result, current_max_a * total);
            }
        }

        cout << min_result << "\n";
    }

    return 0;
}