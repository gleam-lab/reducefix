#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    vector<vector<bool>> can_capture(n, vector<bool>(n, false));

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-indexed
        pieces[i] = {a, b};

        // Mark all positions that can be captured by the current piece
        can_capture[a][b] = true;
        if (a + 2 < n) can_capture[a + 2][b + 1] = true;
        if (a + 1 < n) can_capture[a + 1][b + 2] = true;
        if (a - 1 >= 0) can_capture[a - 1][b + 2] = true;
        if (a - 2 >= 0) can_capture[a - 2][b + 1] = true;
        if (a - 2 >= 0) can_capture[a - 2][b - 1] = true;
        if (a - 1 >= 0) can_capture[a - 1][b - 2] = true;
        if (a + 1 < n) can_capture[a + 1][b - 2] = true;
        if (a + 2 < n) can_capture[a + 2][b - 1] = true;
    }

    // Calculate the number of safe squares
    ll safe_squares = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (!can_capture[i][j]) {
                ++safe_squares;
            }
        }
    }

    cout << safe_squares << endl;

    return 0;
}