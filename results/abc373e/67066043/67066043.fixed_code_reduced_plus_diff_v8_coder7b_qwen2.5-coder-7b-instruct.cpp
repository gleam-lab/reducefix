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

    // Sort the votes
    sort(a.begin(), a.end());

    // Prefix sums
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = k + 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            int lid = n - m - (i >= n - m ? 1 : 0);
            ll cnt = 0;
            if (lid > i && i < lid) {
                cnt++;
            } else if (lid <= i) {
                cnt--;
            }
            cnt += mid;

            if (cnt > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l == k + 1) {
            ans[i] = -1;
        } else {
            ans[i] = l;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}