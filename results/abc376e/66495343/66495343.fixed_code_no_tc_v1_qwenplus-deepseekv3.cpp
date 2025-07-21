#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10;
const int INF=1e18;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        for (int i = 0; i < n; ++i)
            cin >> b[i];
            
        for (int i = 0; i < n; ++i)
            sa[i] = {a[i], b[i]};
        
        sort(sa, sa + n);
        
        int res = INF;
        int sum = 0;
        priority_queue<int> q; // max-heap to keep the smallest K-1 B_i's

        for (int i = 0; i < n; ++i) {
            sum += sa[i].se;
            q.push(sa[i].se);

            if (q.size() > k) {
                sum -= q.top();
                q.pop();
            }

            if (q.size() == k) {
                res = min(res, sa[i].fi * sum);
            }
        }

        cout << res << endl;
    }
    return 0;
}