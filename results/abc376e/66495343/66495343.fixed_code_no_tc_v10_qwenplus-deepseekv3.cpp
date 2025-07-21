#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10, INF=1e18;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> a[i];
        
        for(int i=1; i<=n; i++)
            cin >> b[i];
            
        for(int i=1; i<=n; i++)
            sa[i] = {a[i], b[i]};
        
        sort(sa+1, sa+1+n);
        
        int res = INF;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;

        for(int i=1; i<=n; i++) {
            if(min_heap.size() < k) {
                min_heap.push(sa[i].se);
                sum += sa[i].se;
            } else if(sa[i].se > min_heap.top()) {
                sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(sa[i].se);
                sum += sa[i].se;
            }
            
            if(min_heap.size() == k) {
                res = min(res, sa[i].fi * sum);
            }
        }
        
        cout << res << endl;
    }
    return 0;
}