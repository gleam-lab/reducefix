#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define priority_queue_max priority_queue<int>

const int INF = 1e18;

int T;
int N, K;
int A[200005];
int B[200005];
PII sa[200005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> N >> K;

        for (int i = 1; i <= N; ++i) cin >> A[i];
        for (int i = 1; i <= N; ++i) cin >> B[i];

        for (int i = 1; i <= N; ++i) {
            sa[i] = {A[i], B[i]};
        }

        sort(sa + 1, sa + N + 1);

        priority_queue<int> pq;
        int sum_b = 0;
        int res = INF;

        for (int i = 1; i <= N; ++i) {
            if (i <= K - 1) {
                sum_b += sa[i].se;
                pq.push(sa[i].se);
                continue;
            }

            // Maintain only K-1 smallest B's
            if (pq.size() >= K - 1) {
                int top = pq.top();
                if (sa[i].se < top) {
                    sum_b -= top;
                    pq.pop();
                    sum_b += sa[i].se;
                    pq.push(sa[i].se);
                }
            } else {
                sum_b += sa[i].se;
                pq.push(sa[i].se);
            }

            int current = sa[i].fi * (sum_b + sa[i].se);
            res = min(res, current);
        }

        cout << res << '\n';
    }

    return 0;
}