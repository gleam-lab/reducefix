#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(vector<ll>& a, vector<ll>& b, ll x) {
    multiset<ll> s(b.begin(), b.end());
    for (ll y : a) {
        auto it = s.lower_bound(y);
        if (it == s.end()) {
            return false;
        } else {
            s.erase(it);
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll left = 0, right = 1e9, ans = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(a, b, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}