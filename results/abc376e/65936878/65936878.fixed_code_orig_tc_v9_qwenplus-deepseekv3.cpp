#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].f;
        for(int i=0;i<n;i++) cin >> v[i].s;
        
        sort(v.begin(), v.end());
        
        priority_queue<int> q;
        int sum = 0;
        int ans = LLONG_MAX;
        
        for(int i=0;i<n;i++) {
            if(i >= k) {
                if(q.top() > v[i].s) {
                    sum -= q.top();
                    q.pop();
                    sum += v[i].s;
                    q.push(v[i].s);
                }
            } else if(i == k-1) {
                sum += v[i].s;
                ans = min(ans, sum * v[i].f);
                q.push(v[i].s);
            } else {
                sum += v[i].s;
                q.push(v[i].s);
            }
            
            if(i >= k-1) {
                ans = min(ans, (sum) * v[i].f);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}