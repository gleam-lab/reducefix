#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> unsafe;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        unsafe.insert({a, b});
        // Check all 8 possible knight moves
        if (a + 2 < n && b + 1 < n) unsafe.insert({a + 2, b + 1});
        if (a + 1 < n && b + 2 < n) unsafe.insert({a + 1, b + 2});
        if (a - 1 >= 0 && b + 2 < n) unsafe.insert({a - 1, b + 2});
        if (a - 2 >= 0 && b + 1 < n) unsafe.insert({a - 2, b + 1});
        if (a - 2 >= 0 && b - 1 >= 0) unsafe.insert({a - 2, b - 1});
        if (a - 1 >= 0 && b - 2 >= 0) unsafe.insert({a - 1, b - 2});
        if (a + 1 < n && b - 2 >= 0) unsafe.insert({a + 1, b - 2});
        if (a + 2 < n && b - 1 >= 0) unsafe.insert({a + 2, b - 1});
    }
    cout << n * n - unsafe.size() << endl;
}