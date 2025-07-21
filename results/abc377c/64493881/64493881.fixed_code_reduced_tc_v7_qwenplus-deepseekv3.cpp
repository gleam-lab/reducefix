#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> unsafe;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        unsafe.insert({a, b});

        // Check all 8 possible moves
        if (a + 2 <= N && b + 1 <= N) unsafe.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) unsafe.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) unsafe.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) unsafe.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) unsafe.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) unsafe.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) unsafe.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) unsafe.insert({a + 2, b - 1});
    }

    cout << (N * N - unsafe.size()) << '\n';

    return 0;
}