#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

// Directions where a knight can attack
const array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2};
const array<int, 8> dy = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ll n, m;
    cin >> n >> m;

    set<pair<ll, ll>> occupied;

    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        // Use 0-based internally
        x--; y--;
        occupied.insert({x, y});

        // Check all 8 possible attacked positions
        for (int d = 0; d < 8; ++d) {
            ll nx = x + dx[d];
            ll ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                occupied.insert({nx, ny});
            }
        }
    }

    // Total grid size is n * n, subtract number of occupied/captured cells
    cout << (n * n - (ll)occupied.size()) << endl;
}