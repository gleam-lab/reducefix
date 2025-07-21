#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] - b[i]);
        diag2.insert(a[i] + b[i]);
    }

    ll forbidden = 0;
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;
    forbidden -= rows.size() * cols.size(); // subtract intersections of rows and cols

    // For diagonals of type i - j = constant (diag1)
    for (auto d : diag1) {
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min > i_max) continue;
        ll cnt = i_max - i_min + 1;
        forbidden += cnt;
    }

    // For diagonals of type i + j = constant (diag2)
    for (auto d : diag2) {
        ll i_min = max(1LL, d - N);
        ll i_max = min(N, d - 1);
        if (i_min > i_max) continue;
        ll cnt = i_max - i_min + 1;
        forbidden += cnt;
    }

    // Now subtract intersections between rows, cols, and diagonals that were counted multiple times
    // Subtract intersections of rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                forbidden--;
            }
        }
    }

    // Subtract intersections of cols and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll i = d + c;
            if (i >= 1 && i <= N) {
                forbidden--;
            }
        }
    }

    // Subtract intersections of rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll j = d - r;
            if (j >= 1 && j <= N) {
                forbidden--;
            }
        }
    }

    // Subtract intersections of cols and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll i = d - c;
            if (i >= 1 && i <= N) {
                forbidden--;
            }
        }
    }

    // Add back intersections of rows, cols, and diag1 or diag2 that were subtracted multiple times
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c)) {
                forbidden++;
            }
            if (diag2.count(r + c)) {
                forbidden++;
            }
        }
    }

    // The total safe squares is N*N - forbidden + M (since M squares are already occupied)
    ll total_safe = N * N - forbidden;
    cout << total_safe << endl;
    return 0;
}