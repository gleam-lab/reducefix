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
        
        if(k == 1) {
            int ans = LLONG_MAX;
            for(int i = 0; i < n; i++) {
                ans = min(ans, v[i].f * v[i].s);
            }
            cout << ans << '\n';
            continue;
        }
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        for(int i = 0; i < k - 1; i++) {
            min_heap.push(v[i].s);
            sum += v[i].s;
        }
        
        int ans = LLONG_MAX;
        for(int i = k - 1; i < n; i++) {
            ans = min(ans, v[i].f * (sum + v[i].s));
            if(!min_heap.empty() && v[i].s > min_heap.top()) {
                sum += v[i].s - min_heap.top();
                min_heap.pop();
                min_heap.push(v[i].s);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}