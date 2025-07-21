#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        for (int i = 0; i < n; ++i) p[i] = {a[i], b[i]};
        sort(p, p + n, cmp);

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0, ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            sum += p[i].second;
            pq.push(sum * p[i].first);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, pq.top());
            }
        }

        cout << ans << "\n";
    }
    return 0;
}