#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].f; for(int i=0;i<n;i++) cin >> v[i].s;
        
        // Sort based on the product of B_i and A_i to prioritize maximizing A_i while minimizing B_i
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
            return a.f * b.s < b.f * a.s;
        });
        
        priority_queue<int> pq;
        long long sum = 0;
        
        // Select the K elements with the largest A_i values
        for(int i=0; i<k; ++i) {
            pq.push(v[i].s);
            sum += v[i].s;
        }
        
        long long ans = LLONG_MAX;
        
        // Calculate the minimum value of the expression for the selected set
        for(int i=k; i<n; ++i) {
            ans = min(ans, (sum + v[i].s) * v[i].f);
            sum -= pq.top();
            pq.pop();
            pq.push(v[i].s);
            sum += v[i].s;
        }
        
        cout << ans << '\n';
    }
    return 0;
}