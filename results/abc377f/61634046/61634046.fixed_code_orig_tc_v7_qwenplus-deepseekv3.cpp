#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, sum_diags, diff_diags;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        sum_diags.insert(a + b);
        diff_diags.insert(a - b);
    }
    
    ll R = rows.size();
    ll C = cols.size();
    ll S = sum_diags.size();
    ll D = diff_diags.size();
    
    // Total forbidden squares
    ll forbidden = R * N + C * N - R * C;
    
    // Add sum diagonals
    for (ll s : sum_diags) {
        ll l = max(1LL, s - N);
        ll r = min(N, s - 1);
        if (l <= r) forbidden += r - l + 1;
    }
    
    // Add difference diagonals
    for (ll d : diff_diags) {
        ll l = max(1LL, 1 - d);
        ll r = min(N, N - d);
        if (l <= r) forbidden += r - l + 1;
    }
    
    // Subtract intersections between rows/cols and diagonals
    for (ll a : rows) {
        for (ll b : cols) {
            if (sum_diags.count(a + b)) forbidden--;
            if (diff_diags.count(a - b)) forbidden--;
        }
    }
    
    // Subtract intersections between sum and difference diagonals
    for (ll s : sum_diags) {
        for (ll d : diff_diags) {
            if ((s + d) % 2 != 0) continue;
            ll a = (s + d) / 2;
            ll b = (s - d) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                forbidden--;
            }
        }
    }
    
    // Add back triple intersections (row, col, sum or diff diagonal)
    for (ll a : rows) {
        for (ll b : cols) {
            if (sum_diags.count(a + b) && diff_diags.count(a - b)) {
                forbidden++;
            }
        }
    }
    
    ll total = N * N;
    ll safe = total - forbidden;
    
    cout << safe << '\n';
    
    return 0;
}