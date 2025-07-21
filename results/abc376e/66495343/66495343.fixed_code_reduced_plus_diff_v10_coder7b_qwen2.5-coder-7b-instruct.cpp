#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define arr array<int,3>

const int INF = 0x3f3f3f3f;

int a[200005], b[200005];
PII sa[200005];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        vector<PII> ab(n);
        for (int i = 0; i < n; ++i)
            ab[i] = {a[i], b[i]};

        sort(ab.begin(), ab.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += ab[i].se;
            pq.push(-ab[i].se);
            if (pq.size() > k) {
                sum += pq.top();
                pq.pop();
            }
        }

        int res = INF;
        for (int i = k - 1; i < n; ++i) {
            res = min(res, (long long)ab[i].fi * (-pq.top()));
        }

        cout << res << '\n';
    }

    return 0;
}