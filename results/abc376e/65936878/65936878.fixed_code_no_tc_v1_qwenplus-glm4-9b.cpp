#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int b, a;
};

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<Node> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].a;
        for (int i = 0; i < n; ++i) cin >> v[i].b;
        
        sort(v.begin(), v.end(), [&](Node x, Node y) {
            if (x.a != y.a) return x.a > y.a;
            return x.b < y.b;
        });
        
        int sum = 0, max_val = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(v[i].b);
            sum += v[i].b;
            max_val = v[i].a;
        }
        
        int ans = max_val * sum;
        for (int i = k; i < n; ++i) {
            sum += v[i].b;
            sum -= pq.top();
            pq.pop();
            pq.push(v[i].b);
            max_val = v[i].a;
            ans = min(ans, max_val * sum);
        }
        
        cout << ans << '\n';
    }
    return 0;
}