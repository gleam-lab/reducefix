#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].first;
        for (int i = 0; i < n; ++i) cin >> p[i].second;
        sort(p.begin(), p.end());
        
        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LINF;
        for (int i = 0; i < n; ++i) {
            sum += p[i].second;
            pq.push(p[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, p[i].first * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}