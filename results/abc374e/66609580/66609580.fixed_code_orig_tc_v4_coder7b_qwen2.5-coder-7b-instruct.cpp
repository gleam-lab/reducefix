#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

bool check(const vector<vector<ll>>& data, ll x) {
    int n = data.size();
    for (const auto& row : data) {
        ll a = row[0], p = row[1], b = row[2], q = row[3];
        ll lcm = a / gcd(a, b) * b;
        ll vm = max(0LL, (x / lcm - 1) * min(p * (lcm / a), q * (lcm / b)));
        ll ms = LLONG_MAX >> 1;
        for (ll j = 0; (j - 1) * a <= x - vm * lcm; ++j) {
            ms = min(ms, j * p + max(0LL, ((x - vm * lcm - j * a) / b + !!((x - vm * lcm - j * a) % b)) * q));
        }
        if (vm + ms > x) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll x;
    cin >> n >> x;
    vector<vector<ll>> data(n, vector<ll>(4));
    for (auto& row : data) {
        cin >> row[0] >> row[1] >> row[2] >> row[3];
    }

    ll l = 0, r = LLONG_MAX;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(data, mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    return 0;
}