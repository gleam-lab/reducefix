#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> pre(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    vector<ll> ans(n, 0);
    for (ll i = 0; i < n; i++) {
        ll need = -1;
        ll lower = 0, upper = k + 1;
        while (lower < upper) {
            ll mid = (lower + upper) / 2;
            ll total_votes = pre[n] + mid;
            ll max_winners = 0;
            for (ll j = 0; j < n; j++) {
                if (total_votes >= pre[j + 1]) {
                    max_winners++;
                } else {
                    break;
                }
            }
            if (max_winners >= m) {
                upper = mid;
            } else {
                lower = mid + 1;
            }
        }
        need = lower - a[i];
        if (need < 0) need = 0;
        ans[i] = need;
    }

    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}