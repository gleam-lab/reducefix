#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a, b;

bool check(ll mid, ll k) {
    vector<int> count(b.size());
    for (ll x : a) {
        int idx = lower_bound(b.begin(), b.end(), x - mid) - b.begin();
        int cnt = upper_bound(b.begin() + idx, b.end(), x + mid) - b.begin() - idx;
        if (cnt >= k) return true;
        count[idx]++;
        if (idx > 0) count[idx - 1]--;
    }
    partial_sum(count.begin(), count.end(), count.begin());
    for (int c : count) {
        if (c == k) return true;
    }
    return false;
}

void solve() {
    ll n, q; cin >> n >> q;
    a.resize(n); b.resize(q);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (ll k : b) {
        ll left = 0, right = 2e8;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (check(mid, k)) right = mid;
            else left = mid + 1;
        }
        cout << left << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}