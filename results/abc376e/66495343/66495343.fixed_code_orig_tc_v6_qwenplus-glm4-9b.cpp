#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int A[N], B[N], ans = INT_MAX;

int main() {
    int t, n, k;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &B[i]);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({A[1], B[1]});
        long long sum = B[1];
        ans = INT_MAX;

        for (int i = 2; i <= n; ++i) {
            if (i >= k) {
                auto top = pq.top();
                pq.pop();
                sum -= top.second;
            }
            pq.push({A[i], B[i]});
            if (i >= k) {
                ans = min(ans, top.first * sum);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}