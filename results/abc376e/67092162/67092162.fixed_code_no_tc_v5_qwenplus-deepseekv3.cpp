#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> p[i].first;
        for (int i = 0; i < n; i++) cin >> p[i].second;
        
        sort(p, p + n);
        
        priority_queue<int> q; // max-heap to keep the smallest K B_i
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += p[i].second;
            q.push(p[i].second);
            if (q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            if (q.size() == k) {
                ans = min(ans, sum * p[i].first);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}