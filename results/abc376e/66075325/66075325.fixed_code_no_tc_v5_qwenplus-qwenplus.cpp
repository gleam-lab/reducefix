#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N); // (A_i, B_i)
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort items by A_i in increasing order
        sort(items.begin(), items.end());

        // Min-heap to keep the top K largest B_i values
        priority_queue<int, vector<int>, greater<>> pq;

        int sum_B = 0;
        int res = INF;

        // First, try last K elements (those with largest A_i)
        // This might not be optimal, but gives an initial bound
        for (int i = N - K; i < N; ++i) {
            sum_B += items[i].second;
        }
        res = sum_B * items[N - 1].first;

        // Now iterate from end to start, maintaining top K B_i
        sum_B = 0;
        for (int i = N - 1; i >= 0; --i) {
            pq.push(items[i].second);
            sum_B += items[i].second;

            if (pq.size() > K) {
                sum_B -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                res = min(res, sum_B * items[i].first);
            }
        }

        cout << res << '\n';
    }

    return 0;
}