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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        
        int res = INF;
        priority_queue<int> pq; // max heap to keep the smallest K-1 B_i's
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (pq.size() < k - 1) {
                sum += sa[i].se;
                pq.push(sa[i].se);
            } else if (k > 1 && sa[i].se < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += sa[i].se;
                pq.push(sa[i].se);
            }
            
            if (pq.size() == k - 1) {
                res = min(res, sa[i].fi * (sum + sa[i].se));
            }
        }
        
        cout << res << endl;
    }
    return 0;
}