#include <bits/stdc++.h>
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

        ll ans = LINF;
        priority_queue<ll> pq;
        ll sum_b = 0;

        for (int i = 0; i < n; ++i) {
            ll a = p[i].first;
            ll b = p[i].second;
            
            if (pq.size() < k - 1) {
                pq.push(b);
                sum_b += b;
            } else {
                ans = min(ans, a * (sum_b + b));
                if (!pq.empty() && b < pq.top()) {
                    sum_b -= pq.top();
                    pq.pop();
                    sum_b += b;
                    pq.push(b);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}