#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) cin >> v[i].f;
        for(int i = 0; i < n; i++) cin >> v[i].s;
        
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for(int i = 0; i < k - 1; i++) {
            pq.push(v[i].s);
            sum += v[i].s;
        }
        
        int ans = LLONG_MAX;
        for(int i = k - 1; i < n; i++) {
            ans = min(ans, (sum + v[i].s) * v[i].f);
            
            if(pq.size() == k - 1 && v[i].s < pq.top()) {
                sum -= pq.top();
                sum += v[i].s;
                pq.pop();
                pq.push(v[i].s);
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}