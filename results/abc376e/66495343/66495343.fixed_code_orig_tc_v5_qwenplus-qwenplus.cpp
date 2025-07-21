#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> PII;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<PII> AB(N);
        for (int i = 0; i < N; ++i)
            cin >> AB[i].first;
        for (int i = 0; i < N; ++i)
            cin >> AB[i].second;

        // Sort by A ascending
        sort(AB.begin(), AB.end());

        int res = numeric_limits<int>::max();
        int sum_b = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < N; ++i) {
            int a = AB[i].first;
            int b = AB[i].second;

            if (min_heap.size() < K) {
                sum_b += b;
                min_heap.push(b);
            } else {
                // Try to replace the smallest B in heap if current b is larger
                if (!min_heap.empty() && b > min_heap.top()) {
                    sum_b -= min_heap.top();
                    min_heap.pop();
                    sum_b += b;
                    min_heap.push(b);
                }
            }

            if (min_heap.size() == K) {
                res = min(res, a * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}