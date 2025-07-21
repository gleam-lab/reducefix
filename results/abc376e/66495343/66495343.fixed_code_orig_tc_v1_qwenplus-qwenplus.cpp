#include <bits/stdc++.h>
using namespace std;

#define int long long

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // min-heap on B[i]
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N + 1), B(N + 1);
        for (int i = 1; i <= N; ++i) cin >> A[i];
        for (int i = 1; i <= N; ++i) cin >> B[i];

        vector<pair<int, int>> items(N + 1); // 1-based index
        for (int i = 1; i <= N; ++i) {
            items[i] = {A[i], B[i]};
        }

        sort(items.begin() + 1, items.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        for (int i = 1; i <= N; ++i) {
            if (pq.size() == K - 1) {
                // Remove the largest B-value so far to make room
                if (!pq.empty() && B[i] < pq.top().second) {
                    sum_b -= pq.top().second;
                    pq.pop();
                } else {
                    // Current B is larger, skip adding it
                    // Because we want to pick smallest K-1 B-values
                    // So we only keep small B-values
                    goto skip_push;
                }
            }

            pq.push({items[i].first, items[i].second});
            sum_b += items[i].second;

        skip_push:
            if (i >= K) {
                // Now we have at least K elements: take K-1 smallest B-values from previous ones
                // and add current B[i]
                // So current A[i] is the max in the group
                int curr_max_a = items[i].first;
                res = min(res, curr_max_a * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}