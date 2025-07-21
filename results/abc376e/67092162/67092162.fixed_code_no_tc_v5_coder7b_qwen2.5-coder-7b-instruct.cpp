#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        long long sum = 0, ans = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            v[i] = {a[i], b[i]};
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < k; ++i) {
            sum += v[i].second;
            pq.push({v[i].second, v[i].first});
        }

        ans = min(ans, sum * v[k - 1].first);

        for (int i = k; i < n; ++i) {
            if (pq.top().first > v[i].second) {
                sum -= pq.top().first;
                pq.pop();
                sum += v[i].second;
                pq.push({v[i].second, v[i].first});
            }
            ans = min(ans, sum * v[i].first);
        }

        cout << ans << "\n";
    }
    return 0;
}