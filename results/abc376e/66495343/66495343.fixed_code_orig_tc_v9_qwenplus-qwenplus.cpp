#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>

int INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

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

        // Sort by A[i]
        sort(AB.begin(), AB.end());

        priority_queue<int> pq; // max-heap to keep track of smallest K B[i]
        int sum_B = 0;
        int res = INF;

        for (int i = 0; i < N; ++i) {
            int curr_A = AB[i].first;
            int curr_B = AB[i].second;

            if (pq.size() >= K) {
                // If heap has more than K elements, remove the largest B
                sum_B -= pq.top();
                pq.pop();
            }

            pq.push(curr_B);
            sum_B += curr_B;

            if (pq.size() == K) {
                res = min(res, curr_A * sum_B);
            }
        }

        cout << res << endl;
    }

    return 0;
}