#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    for (auto &q : queens) {
        cin >> q.first >> q.second;
    }

    unordered_set<ll> rows, cols, diag1, diag2;
    for (const auto &q : queens) {
        ll i = q.first, j = q.second;
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll total = N * N;
    ll unsafe = 0;

    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }

    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d2 + d1) / 2;
            ll j = (d2 - d1) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) || cols.count(j) || diag1.count(i - j) || diag2.count(i + j)) {
                    unsafe--;
                }
            }
        }
    }

    for (const auto &q : queens) {
        ll i = q.first, j = q.second;
        if (rows.count(i) && cols.count(j) && diag1.count(i - j) && diag2.count(i + j)) {
            unsafe++;
        }
    }

    ll safe = total - unsafe;
    cout << max(safe, 0LL) << endl;

    return 0;
}