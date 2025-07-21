#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll N, ll M, vector<ll> a, vector<ll> b) {
    unordered_set<ll> blocked;
    for (ll i = 0; i < M; ++i) {
        ll x = a[i], y = b[i];
        // Check all possible moves from the current position
        for (ll dx = -2; dx <= 2; ++dx) {
            for (ll dy = -2; dy <= 2; ++dy) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                ll nx = x + dx, ny = y + dy;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    blocked.insert((nx - 1) * N + ny);
                }
            }
        }
    }

    ll total_squares = N * N;
    ll available_squares = total_squares - blocked.size();

    return available_squares;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    for (ll i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    cout << solve(N, M, a, b) << endl;

    return 0;
}