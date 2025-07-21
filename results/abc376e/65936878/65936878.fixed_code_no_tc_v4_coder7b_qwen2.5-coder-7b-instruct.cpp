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
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].f; for(int i=0;i<n;i++) cin >> v[i].s;
        
        // Sort based on A_i in descending order to maximize the product with max(A_i)
        sort(rbegin(v), rend(v));

        priority_queue<int> pq;
        long long sum_b = 0;
        for(int i=0; i<k; ++i) {
            pq.push(v[i].s);
            sum_b += v[i].s;
        }

        long long result = LLONG_MAX;
        for(int i=k; i<n; ++i) {
            result = min(result, (sum_b + v[i].s) * v[i].f);
            
            // Maintain the maximum k elements sum using a priority queue
            sum_b += v[i].s - pq.top();
            pq.pop();
            pq.push(v[i].s);
        }
        
        cout << result << '\n';
    }
    
    return 0;
}