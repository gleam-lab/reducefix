#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const int N = 1e9 + 5;
vector<int> r, c, d1, d2;

void add(vector<int>& v, int x) {
    if (v.empty() || v.back() < x) {
        v.push_back(x);
    } else {
        auto it = lower_bound(v.begin(), v.end(), x);
        *it = x;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        add(r, x);
        add(c, y);
        add(d1, x - y);
        add(d2, x + y);
    }

    ll ans = ((n - r.size()) % mod) * ((n - c.size()) % mod) % mod;
    for (int i = 0; i < d1.size(); ++i) {
        for (int j = i + 1; j < d1.size(); ++j) {
            if (d1[j] == d1[i]) continue;
            int x = min(abs(d1[i]), abs(d1[j]));
            ans -= (x * (n - x)) % mod;
            ans %= mod;
        }
    }

    for (int i = 0; i < d2.size(); ++i) {
        for (int j = i + 1; j < d2.size(); ++j) {
            if (d2[j] == d2[i]) continue;
            int x = min(abs(d2[i]), abs(d2[j]));
            ans -= (x * (n - x)) % mod;
            ans %= mod;
        }
    }

    cout << (ans + mod) % mod << '\n';
    return 0;
}