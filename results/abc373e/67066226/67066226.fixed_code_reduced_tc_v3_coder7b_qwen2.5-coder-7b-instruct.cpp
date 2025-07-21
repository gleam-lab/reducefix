#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(a[i] > (k / (n - m))) {
            ans[i] = 0;
            continue;
        }

        ll target = (k / (n - m)) - a[i];
        ll left = 0, right = target + 1;
        while(left < right) {
            ll mid = left + (right - left) / 2;
            if(pref[i + 1] + mid * (n - i - 1) >= pref[n]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if(pref[i + 1] + left * (n - i - 1) < pref[n]) {
            ans[i] = -1;
        } else {
            ans[i] = left;
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}