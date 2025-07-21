#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

// Structure to hold the A_i, B_i pairs
struct Pair {
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

        vector<Pair> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].a;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].b;
        }

        // Sort by A_i in ascending order
        sort(items.begin(), items.end(), [](const Pair& x, const Pair& y) {
            return x.a < y.a;
        });

        // Use a min-heap to maintain the top K smallest B_i values among the first i+1 elements
        priority_queue<int, vector<int>, greater<>> pq;
        int sumB = 0;

        // Initialize heap with first K elements
        for (int i = 0; i < K; ++i) {
            pq.push(items[i].b);
            sumB += items[i].b;
        }

        int result = items[K - 1].a * sumB;

        // Slide window and update result
        for (int i = K; i < N; ++i) {
            if (items[i].b > pq.top()) {
                sumB -= pq.top();
                pq.pop();
                pq.push(items[i].b);
                sumB += items[i].b;
            }
            result = min(result, items[i].a * sumB);
        }

        cout << result << "\n";
    }

    return 0;
}