#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int solve() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i].first;
    for (int i = 0; i < N; ++i)
        cin >> A[i].second;

    sort(A.begin(), A.end());

    priority_queue<int, vector<int>, greater<>> pq;
    int sum = 0;
    int res = INF;

    // Traverse in reverse so we can fix A[i] as max A and pick best K-1 B's before it
    for (int i = N - 1; i >= 0; --i) {
        if (pq.size() < K - 1) {
            pq.push(A[i].second);
            sum += A[i].second;
        } else {
            res = min(res, A[i].first * (sum + A[i].second));

            // Maintain heap size K-1
            pq.push(A[i].second);
            sum += A[i].second;
            if (pq.size() > K - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        cout << solve() << '\n';

    return 0;
}