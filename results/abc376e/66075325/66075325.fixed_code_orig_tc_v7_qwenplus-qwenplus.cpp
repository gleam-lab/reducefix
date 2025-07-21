#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first; // A_i
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second; // B_i
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        priority_queue<int> max_heap; // To maintain K smallest B's (as max heap of K smallest)
        int sum_b = 0;
        int ans = 1LL << 60; // Large number

        for (int i = 0; i < N; ++i) {
            int a = items[i].first;
            int b = items[i].second;

            sum_b += b;
            max_heap.push(b);

            // Maintain heap size <= K
            if (max_heap.size() > K) {
                sum_b -= max_heap.top();
                max_heap.pop();
            }

            // Once we have K elements, compute cost
            if (max_heap.size() == K) {
                ans = min(ans, a * sum_b);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}