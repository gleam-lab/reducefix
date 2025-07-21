#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int t, n, k;
int a[maxN], b[maxN];
pair<int, int> p[maxN];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        priority_queue<int> pq;
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

        // Initialize first K elements
        for (int i = 1; i <= k; ++i) {
            sum += p[i].second;
            pq.push(p[i].second);
        }

        long long ans = 1LL * p[k].first * sum;

        for (int i = k + 1; i <= n; ++i) {
            if (pq.top() > p[i].second) {
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