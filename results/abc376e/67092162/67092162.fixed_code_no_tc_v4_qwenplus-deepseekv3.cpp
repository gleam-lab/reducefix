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
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) {
            p[i] = {a[i], b[i]};
        }
        sort(p, p + n);
        
        priority_queue<int> q;
        long long sum = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += p[i].second;
            q.push(-p[i].second); // Using min-heap via negation
        }
        long long ans = LLONG_MAX;
        for (int i = k - 1; i < n; i++) {
            sum += p[i].second;
            q.push(-p[i].second);
            if (q.size() > k) {
                sum += q.top();
                q.pop();
            }
            ans = min(ans, p[i].first * sum);
        }
        cout << ans << "\n";
    }
    return 0;
}