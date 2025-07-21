#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    unordered_set<ll> rows, cols, diag1, diag2;

    for (int k = 0; k < M; ++k) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll unsafe = 0;

    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    for (ll d : diag1) {
        ll min_x = max(1LL, d - N);
        ll max_x = min(N, d - 1);
        unsafe += max_x - min_x + 1;
    }

    for (ll d : diag2) {
        ll min_x = max(1LL, 1 - d);
        ll max_x = min(N, N - d);
        unsafe += max_x - min_x + 1;
    }

    for (ll a : rows) {
        for (ll d : diag1) {
            ll b = d - a;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
        for (ll d : diag2) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }

    for (ll b : cols) {
        for (ll d : diag1) {
            ll a = d - b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
        for (ll d : diag2) {
            ll a = b + d;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }

    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                unsafe++;
            }
        }
    }

    for (ll a : rows) {
        for (ll b : cols) {
            if (diag1.count(a + b) && diag2.count(a - b)) {
                unsafe--;
            }
        }
    }

    ll total = N * N - M;
    ll safe = total - unsafe;

    cout << safe << endl;

    return 0;
}