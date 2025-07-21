#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;
int t, n, k;
int a[maxN], b[maxN];
pair<int, int> p[maxN];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        int sum = 0, ans = __INT_MAX__;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        for (int i = 0; i < n; i++) {
            p[i].first = a[i];
            p[i].second = b[i];
        }
        
        sort(p, p + n, [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });
        
        pq.push(p[0].second);
        sum = p[0].second;
        for (int i = 1; i < k; i++) {
            pq.push(p[i].second);
            sum += p[i].second;
            ans = min(ans, p[i].first * sum);
        }
        
        for (int i = k; i < n; i++) {
            sum = sum - pq.top() + p[i].second;
            pq.pop();
            pq.push(p[i].second);
            ans = min(ans, sum * p[i].first);
        }
        
        cout << ans << '\n';
    }

    return 0;
}