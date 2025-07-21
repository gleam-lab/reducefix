#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[n - i];
    }

    function<bool(ll)> check = [&](ll x) {
        int needed = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] + x <= a[n - m]) {
                break;
            }
            needed++;
        }
        ll total_needed = prefix_sum[min(m - 1, needed)];
        return total_needed <= k;
    };

    ll left = 0, right = k, answer = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (answer == -1) {
            cout << 0 << " ";
        } else {
            cout << answer << " ";
        }
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