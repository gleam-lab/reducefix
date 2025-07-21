#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<ll, ll>> c;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        c.emplace(a, b);
    }
    set<pair<ll, ll>> captures;
    for (const auto& [a, b] : c) {
        if (a + 2 < n) {
            if (b + 1 < n) captures.emplace(a + 2, b + 1);
            if (b - 1 >= 0) captures.emplace(a + 2, b - 1);
        }
        if (a + 1 < n) {
            if (b + 2 < n) captures.emplace(a + 1, b + 2);
            if (b - 2 >= 0) captures.emplace(a + 1, b - 2);
        }
        if (a - 2 >= 0) {
            if (b + 1 < n) captures.emplace(a - 2, b + 1);
            if (b - 1 >= 0) captures.emplace(a - 2, b - 1);
        }
        if (a - 1 >= 0) {
            if (b + 2 < n) captures.emplace(a - 1, b + 2);
            if (b - 2 >= 0) captures.emplace(a - 1, b - 2);
        }
    }
    cout << n * n - c.size() - captures.size() << endl;
}