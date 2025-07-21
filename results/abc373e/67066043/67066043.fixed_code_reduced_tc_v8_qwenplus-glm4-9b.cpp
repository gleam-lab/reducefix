#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    vector<ll> pos(n), neg(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            pos.push_back(i + 1);
        } else {
            neg.push_back(a[i] - sum);
        }
        sum += a[i];
    }
    const ll INF = 1e18;
    vector<ll> ans(n, INF);
    for (int i = 0; i < pos.size(); ++i) {
        ans[pos[i] - 1] = 0;
    }
    for (int i = neg.size() - 1; i >= 0; --i) {
        int idx = neg[i] + sum + n - m;
        if (idx < 0 || idx >= n) continue;
        int left = upper_bound(pos.begin(), pos.end(), idx + 1) - pos.begin();
        int right = upper_bound(pos.begin(), pos.end(), idx + m) - pos.begin();
        if (right - left > m) continue;
        ans[idx] = min(ans[idx], neg[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == INF) {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}