#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        
        for (int i = 1; i <= n; i++) 
            cin >> b[i];
        
        for (int i = 1; i <= n; i++) 
            sa[i] = {a[i], b[i]};
        
        sort(sa + 1, sa + n + 1);

        int res = INF, sum = 0;
        vector<int> pq;

        for (int i = 1; i <= n; i++) {
            if (pq.size() < k - 1) {
                sum += sa[i].se;
                pq.push_back(sa[i].se);
                continue;
            }

            int na = sa[i].fi;
            sum += sa[i].se;

            if (pq.size() > k - 1) {
                int big = *max_element(pq.begin(), pq.end());
                sum -= big;
                pq.erase(max_element(pq.begin(), pq.end()));
            }

            pq.push_back(sa[i].se);
            sort(pq.begin(), pq.end());
            res = min(res, na * sum);
        }

        cout << res << endl;
    }

    return 0;
}