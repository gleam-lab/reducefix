#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: x + y, diag2: x - y
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll total = N * N;
    ll unsafe = 0;
    
    // Subtract rows, columns, and diagonals
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe += diag1.size() * N;
    for (auto d : diag2) {
        ll lower = max(1 - N, d);
        ll upper = min(N - 1, d);
        unsafe += (upper - lower + 1);
    }
    
    // Add intersections
    unsafe -= rows.size() * cols.size();
    unsafe -= rows.size() * diag1.size();
    for (auto d : diag2) {
        ll cnt = 0;
        for (auto r : rows) {
            ll c = r - d;
            if (cols.count(c)) cnt++;
        }
        unsafe -= cnt;
    }
    unsafe -= cols.size() * diag1.size();
    for (auto d : diag2) {
        ll cnt = 0;
        for (auto c : cols) {
            ll r = c + d;
            if (rows.count(r)) cnt++;
        }
        unsafe -= cnt;
    }
    for (auto s : diag1) {
        ll cnt = 0;
        for (auto r : rows) {
            ll c = s - r;
            if (cols.count(c)) cnt++;
        }
        unsafe -= cnt;
    }
    
    // Add triple intersections
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) unsafe++;
            if (diag2.count(r - c)) unsafe++;
        }
    }
    for (auto s : diag1) {
        for (auto d : diag2) {
            if ((s + d) % 2 != 0) continue;
            ll r = (s + d) / 2;
            ll c = (s - d) / 2;
            if (rows.count(r) && cols.count(c)) unsafe++;
        }
    }
    
    // Subtract quadruple intersections
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) unsafe--;
        }
    }
    
    ll safe = total - unsafe;
    cout << safe << endl;
    
    return 0;
}