#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int INF = 0x3f3f3f3f;

int a[200010], b[200010];

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

        // Sort based on a[i]
        vector<PII> sa(n + 1);
        for (int i = 1; i <= n; i++) 
            sa[i] = {a[i], b[i]};
        
        sort(sa.begin() + 1, sa.end());

        // Find the top K elements in terms of a[i]
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 1; i <= k; i++) {
            pq.push(sa[i].se);
            sum += sa[i].se;
        }

        int res = INF;
        for (int i = k + 1; i <= n; i++) {
            int na = sa[i].fi;
            int nb = sa[i].se;
            
            if (pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
            
            pq.push(nb);
            sum += nb;
            
            res = min(res, static_cast<long long>(na) * sum);
        }

        cout << res << endl;
    }

    return 0;
}