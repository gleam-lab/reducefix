#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort by A in ascending order
        sort(items.begin(), items.end());

        priority_queue<int> max_heap; // To maintain up to K smallest B's
        int total_b = 0;
        int result = 1e18; // Large initial value

        for (int i = 0; i < N; ++i) {
            int a = items[i].first;
            int b = items[i].second;

            total_b += b;
            max_heap.push(b);

            // Maintain only K elements in the heap
            if (max_heap.size() > K) {
                total_b -= max_heap.top();
                max_heap.pop();
            }

            // Once we have at least K elements, compute the product
            if (max_heap.size() == K) {
                result = min(result, a * total_b);
            }
        }

        cout << result << endl;
    }

    return 0;
}