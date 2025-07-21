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

        // Sort by A_i in descending order and B_i in ascending order
        sort(begin(v), end(v), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.f == b.f ? a.s < b.s : a.f > b.f;
        });

        // Priority queue to keep track of the smallest B_i values
        priority_queue<int, vector<int>, greater<int>> pq;
        int total_sum_B = 0;
        for(int i = 0; i < k; i++) {
            pq.push(v[i].s);
            total_sum_B += v[i].s;
        }

        int ans = total_sum_B * v[k-1].f;

        for(int i = k; i < n; i++) {
            if(pq.top() > v[i].s) {
                total_sum_B -= pq.top();
                total_sum_B += v[i].s;
                pq.pop();
                pq.push(v[i].s);
            }
            ans = min(ans, total_sum_B * v[i].f);
        }

        cout << ans << '\n';
    }

    return 0;
}