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
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) cin >> v[i].f;
        for(int i = 0; i < n; i++) cin >> v[i].s;
        
        sort(v.begin(), v.end());
        
        priority_queue<int> q;
        int sum_b = 0;
        
        for(int i = 0; i < k - 1; i++) {
            q.push(v[i].s);
            sum_b += v[i].s;
        }
        
        int ans = LLONG_MAX;
        
        for(int i = k - 1; i < n; i++) {
            int current_max_a = v[i].f;
            int current_sum_b = sum_b + v[i].s;
            ans = min(ans, current_max_a * current_sum_b);
            
            if(k > 1) {
                if(!q.empty() && q.top() > v[i].s) {
                    sum_b -= q.top();
                    q.pop();
                    sum_b += v[i].s;
                    q.push(v[i].s);
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}