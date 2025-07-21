#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Item {
    int A, B;
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
            cin >> items[i].A;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].B;
        }

        // Sort items by A_i in ascending order
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.A < y.A;
        });

        // Min-heap to maintain top K smallest B_i values
        priority_queue<int, vector<int>, greater<int>> pq;

        int sum_B = 0;
        int min_result = 1e18;  // To store the minimum value

        // First K-1 elements (we will add Kth separately in loop)
        for (int i = 0; i < K - 1; ++i) {
            sum_B += items[i].B;
            pq.push(items[i].B);
        }

        // Now consider each item from K-1 to N-1 as the max A_i
        for (int i = K - 1; i < N; ++i) {
            // Add current B to complete a set of K elements
            sum_B += items[i].B;
            pq.push(items[i].B);

            // Calculate the current cost: A[i] * sum_B
            min_result = min(min_result, items[i].A * sum_B);

            // Remove the smallest B to prepare for next iteration
            sum_B -= pq.top();
            pq.pop();
        }

        cout << min_result << "\n";
    }

    return 0;
}