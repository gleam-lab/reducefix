#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    priority_queue<pair<int, int>> pq;
    rep(i, n) pq.push({a[i], i});
    while (!pq.empty()) {
        auto [h, i] = pq.top(); pq.pop();
        h--;
        ans++;
        if (h > 0) pq.push({h, i});
        if (ans % 3 == 0 && !pq.empty()) {
            auto [h2, i2] = pq.top(); pq.pop();
            h2--;
            if (h2 > 0) pq.push({h2, i2});
        }
    }
    cout << ans << endl;
}