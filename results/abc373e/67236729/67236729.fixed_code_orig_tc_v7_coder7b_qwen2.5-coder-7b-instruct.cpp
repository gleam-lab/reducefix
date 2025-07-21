#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr int MOD = 1e9 + 7;

int n, m, k;
vi a, b, sm;

// Function to check if candidate i can win with at least d additional votes
bool check(ll d, int i) {
    int above = upper_bound(b.begin(), b.end(), a[i] + d) - b.begin();
    int up = n - above + 1;
    if (up >= m) return false;
    ll sum = sm[n] - sm[above];
    if (b[above - 1] <= a[i] + d && a[i] + d <= b[above]) {
        sum -= a[i] + d;
        sum += b[above - 1];
    }
    return (a[i] + d + 1) * (m - up) - sum > k - d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    a.resize(n), b.resize(n), sm.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin() + 1, b.end());

    for (int i = n; i >= 1; --i) {
        sm[i] = sm[i + 1] + b[i];
    }

    vi res(n);
    for (int i = 1; i <= n; ++i) {
        ll l = 0, r = k, ans = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid, i)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res[i] = ans;
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}