#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const int N = 2e5 + 10;
ll a[N];

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        k -= votes[i];
    }

    sort(votes.begin(), votes.end());

    auto can_win = [&](ll x) {
        int above = n - (upper_bound(votes.begin(), votes.end(), votes.back() + x) - votes.begin());
        return above < m;
    };

    vector<ll> res(n);
    for (int i = 0; i < n; ++i) {
        ll left = 0, right = k;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (can_win(mid + votes[i])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        res[i] = left - votes[i];
    }

    for (int i = 0; i < n; ++i) {
        if (res[i] < 0) res[i] = 0;
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}