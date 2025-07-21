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

        // Use a min-heap to maintain top K B values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int res = 1e18; // To store the answer

        // First take last K elements from sorted list as initial solution
        for (int i = N - 1; i >= N - K; --i) {
            pq.push(items[i].b);
            sum_b += items[i].b;
        }

        // The current max A is at N-K+1 since we're moving leftward
        res = items[N - K + 1].a * sum_b;

        // Try replacing one big A with smaller A and see if it's better
        for (int i = N - K; i >= 0; --i) {
            // Current item is items[i], which has smaller A than current max in heap
            int candidate_a = items[i].a;
            
            // Remove the smallest B from heap and replace with larger B from i-th element
            // This maintains heap size K and keeps only the best (largest) Bs
            if (!pq.empty() && items[i].b > pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].b);
                sum_b += items[i].b;
            }
            
            // Update result: candidate_a is the largest A currently considered
            res = min(res, candidate_a * sum_b);
        }

        cout << res << "\n";
    }

    return 0;
}