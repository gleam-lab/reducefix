#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n);
        rep(i, n) {
            cin >> a[i].first;
        }
        rep(i, n) {
            cin >> a[i].second;
        }
        
        sort(a.begin(), a.end(), [](const auto &p1, const auto &p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        
        priority_queue<int> pq;
        ll sum = 0;
        rep(i, k) {
            pq.push(a[i].second);
            sum += a[i].second;
        }
        
        ll ans = sum * a[k - 1].first;
        
        rep(i, n - k) {
            sum -= pq.top();
            pq.pop();
            pq.push(a[i + k].second);
            sum += a[i + k].second;
            ans = min(ans, sum * a[i + k].first);
        }
        
        cout << ans << '\n';
    }
    return 0;
}