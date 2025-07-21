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
        
        if(k == 1) {
            int min_val = LLONG_MAX;
            for(int i=0;i<n;i++) {
                min_val = min(min_val, v[i].f * v[i].s);
            }
            cout << min_val << '\n';
            continue;
        }
        
        priority_queue<int> pq;
        int sum = 0;
        
        for(int i=0;i<k-1;i++) {
            pq.push(v[i].s);
            sum += v[i].s;
        }
        
        int ans = LLONG_MAX;
        
        for(int i=k-1;i<n;i++) {
            ans = min(ans, v[i].f * (sum + v[i].s));
            if(!pq.empty() && v[i].s < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += v[i].s;
                pq.push(v[i].s);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}