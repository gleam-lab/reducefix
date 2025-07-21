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
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        int ans = LLONG_MAX;
        
        for(int i=n-1;i>=0;i--) {
            pq.push(v[i].s);
            sum += v[i].s;
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k) {
                ans = min(ans, sum * v[i].f);
            }
        }
        
        cout << ans << '\n';
    }
}