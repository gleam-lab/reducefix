#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) cin >> p[i].second;  // B values first
        for (int i = 0; i < n; i++) cin >> p[i].first;   // A values second

        sort(p.begin(), p.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
            if (l.first != r.first) return l.first < r.first;
            return l.second > r.second;  // Descending order of A for max cases
        });

        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(p[i].second);
            sum += p[i].second;
            if (i >= k) {
                sum -= pq.top();
                pq.pop();
            }
            if (i == k - 1) {
                ans = max(ans, (long long)pq.top() * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}