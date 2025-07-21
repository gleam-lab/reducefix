#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> forbidden;

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        forbidden.emplace(a, b);

        // All possible attack positions from (a, b)
        if (a + 2 < n && b + 1 < n) forbidden.emplace(a + 2, b + 1);
        if (a + 1 < n && b + 2 < n) forbidden.emplace(a + 1, b + 2);
        if (a - 1 >= 0 && b + 2 < n) forbidden.emplace(a - 1, b + 2);
        if (a - 2 >= 0 && b + 1 < n) forbidden.emplace(a - 2, b + 1);
        if (a - 2 >= 0 && b - 1 >= 0) forbidden.emplace(a - 2, b - 1);
        if (a - 1 >= 0 && b - 2 >= 0) forbidden.emplace(a - 1, b - 2);
        if (a + 1 < n && b - 2 >= 0) forbidden.emplace(a + 1, b - 2);
        if (a + 2 < n && b - 1 >= 0) forbidden.emplace(a + 2, b - 1);
    }

    cout << n * n - forbidden.size() << endl;
}