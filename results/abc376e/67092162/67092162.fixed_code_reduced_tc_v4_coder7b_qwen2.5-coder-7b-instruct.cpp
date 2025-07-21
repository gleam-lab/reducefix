#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
vector<pair<int, int>> p(maxN);

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> sum_b(k, 0);
        priority_queue<int> pq;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cin >> b[i];
            p[i] = {a[i], b[i]};
        }

        sort(p.begin() + 1, p.begin() + n + 1, cmp);

        long long ans = LLONG_MAX;
        for (int i = 1; i <= k; ++i) {
            sum_b[i % k] += p[i].second;
            pq.push(-p[i].second); // Using negative for max-heap behavior
        }

        ans = min(ans, static_cast<long long>(p[k].first) * accumulate(sum_b.begin(), sum_b.end(), 0LL));

        for (int i = k + 1; i <= n; ++i) {
            if (-pq.top() > p[i].second) {
                sum_b[pq.top() % k] -= pq.top();
                pq.pop();
                sum_b[p[i].second % k] += p[i].second;
                pq.push(-p[i].second);
            }
            ans = min(ans, static_cast<long long>(p[i].first) * accumulate(sum_b.begin(), sum_b.end(), 0LL));
        }

        cout << ans << "\n";
    }
    return 0;
}