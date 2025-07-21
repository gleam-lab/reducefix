#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, k;
int a[200010], b[200010];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        sort(b, b + n);
        long long ans = LLONG_MAX, sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += b[i];
            if (pq.size() >= k) {
                sum -= pq.top();
                pq.pop();
            }
            pq.push(a[i]);
            if (pq.size() == k) {
                ans = min(ans, pq.top() * sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}