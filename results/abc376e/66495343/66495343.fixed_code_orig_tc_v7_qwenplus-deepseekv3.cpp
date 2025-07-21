#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i=0; i<n; i++)
            cin >> a[i];
        
        for(int i=0; i<n; i++)
            cin >> b[i];
            
        for(int i=0; i<n; i++)
            sa[i] = {a[i], b[i]};
        
        sort(sa, sa+n);
        
        int res = LLONG_MAX;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> q; // min-heap to keep the largest K-1 elements
        
        for(int i=0; i<n; i++) {
            if (i < k-1) {
                sum += sa[i].se;
                q.push(sa[i].se);
                continue;
            }
            
            // Current element is sa[i], with sa[i].fi as the max A in the subset
            sum += sa[i].se;
            q.push(sa[i].se);
            
            if (q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            
            if (i >= k-1) {
                res = min(res, sa[i].fi * sum);
            }
        }
        
        // Handle the case where k == n
        if (k == n) {
            res = min(res, sa[n-1].fi * accumulate(b, b+n, 0LL));
        }
        
        cout << res << endl;
    }
    return 0;
}