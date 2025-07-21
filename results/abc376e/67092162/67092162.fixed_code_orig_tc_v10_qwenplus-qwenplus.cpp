#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int maxN = 2e5 + 5;

int t, n, k;
int a[maxN], b[maxN];
priority_queue<long long> pq;
pii p[maxN];

bool cmp(pii p1, pii p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        for (int i = 1; i <= n; ++i) {
            p[i] = {a[i], b[i]};
        }

        sort(p + 1, p + n + 1, cmp);

        // Initialize with first k elements
        while (!pq.empty()) pq.pop();
        sum = 0;
        for (int i = 1; i <= k; ++i) {
            sum += p[i].second;
            pq.push(p[i].second);
        }

        long long ans = 1LL * p[k].first * sum;

        for (int i = k + 1; i <= n; ++i) {
            if (p[i].second < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(p[i].second);
                sum += p[i].second;
            }
            ans = min(ans, 1LL * p[i].first * sum);
        }

        cout << ans << "\n";
    }

    return 0;
}