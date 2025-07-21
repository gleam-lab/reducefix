#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>& a, ll m, ll k, ll i, ll x) {
    ll sum = accumulate(a.begin(), a.end(), 0ll) + x;
    sort(a.begin(), a.end());
    ll cnt = 0;
    for (int j = 0; j < a.size(); j++) {
        if (a[j] > a[i]) cnt++;
    }
    if (cnt >= m) return false;
    ll needed = (m - cnt) * (a[i] + 1) - sum;
    return needed <= x;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (check(a, m, k, i, 0)) {
            ans[i] = 0;
            continue;
        }
        ll low = 0, high = k - accumulate(a.begin(), a.end(), 0ll);
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(a, m, k, i, mid)) {
                ans[i] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}