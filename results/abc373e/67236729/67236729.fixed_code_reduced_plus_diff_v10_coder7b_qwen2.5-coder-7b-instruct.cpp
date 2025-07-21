#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 200010;

int n, m;
ll k;
ll a[MAXN];

bool can_win(ll x, int id) {
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) b[i] = a[i];
    b[id] += x;
    sort(b.begin(), b.end());
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (b[n - i - 1] > b[i]) ++cnt;
        if (cnt > m) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<ll> res(n, -1);
    for (int i = 0; i < n; ++i) {
        ll left = 0, right = k;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (can_win(mid, i)) {
                res[i] = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << res[i] << " ";
    cout << endl;

    return 0;
}