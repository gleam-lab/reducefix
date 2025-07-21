#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 2e5 + 5;

int t, n, k;
ll a[maxN], b[maxN];
pair<ll, ll> p[maxN];

bool cmp(pair<ll, ll>& p1, pair<ll, ll>& p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        priority_queue<ll> q;
        ll sum = 0;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        for (int i = 0; i < n; ++i)
            p[i] = {a[i], b[i]};
        
        sort(p, p + n, cmp);

        // Initialize with first K elements
        sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += p[i].second;
            q.push(p[i].second);
        }

        ll res = p[k - 1].first * sum;

        // Try replacing larger B values with smaller ones if possible
        for (int i = k; i < n; ++i) {
            if (!q.empty() && q.top() > p[i].second) {
                sum -= q.top();
                q.pop();
                q.push(p[i].second);
                sum += p[i].second;
            }
            res = min(res, p[i].first * sum);
        }

        cout << res << "\n";
    }

    return 0;
}