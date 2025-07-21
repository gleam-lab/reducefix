#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    unordered_set<ll> rows, cols, diag1, diag2;
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
    }

    ll unused_rows = n - rows.size();
    ll unused_cols = n - cols.size();
    ll unused_diag1 = n - diag1.size();
    ll unused_diag2 = n - diag2.size();

    // Calculate the number of squares that can be used
    ll answer = unused_rows * unused_cols;

    // Check the diagonals
    for (ll i = 1; i <= n; ++i) {
        if (rows.find(i) == rows.end()) {
            // Check the diagonal i + i
            if (cols.find(2 * i) == cols.end() && diag1.find(i + i) == diag1.end()) {
                unused_diag1++;
            }
            // Check the diagonal i - i (which is always 0)
            if (cols.find(0) != cols.end() && diag2.find(0) == diag2.end()) {
                // Only subtract if it's not the first row/column
                if (i > 1) {
                    unused_diag2++;
                }
            }
        }
    }

    answer += unused_diag1 * unused_cols + unused_diag2 * unused_rows;

    cout << answer << endl;
    return 0;
}